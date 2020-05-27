#include <iostream>
using namespace std;

const int MAX = 5005;

char Str[MAX];
int Leng;
long long Memo[MAX];// Memo[i] là số cách tính từ kí tự i đến cuối.

int GetLeng(char *s)
{
	int leng = 0;
	while(s[leng] != '\0') leng++;
	return leng;
}

/*
* Lấy 2 kí tự tiếp theo trong xâu s, bắt đầu từ vị trí i
* RETURN: giá trị số nguyên của 2 chữ số đó.
*/
int Get2Next(char *s, int i)
{
	return (s[i] - '0') * 10 + s[i + 1] - '0';
}

long long Solve(int i)
{
	if(Str[i] == '0') return -1;
	if(Memo[i] != -1) return Memo[i];

	int t = Get2Next(Str, i);
	
	if(t == 10 || t == 20)
		return Memo[i] = Solve(i + 2);

	if(t <= 26)
	{
		long long t1 = Solve(i + 1);
		long long t2 = Solve(i + 2);

		// Kiểm tra xem t1, t2 cái nào hợp lệ.
		if(t1 == -1 && t2 != -1) return Memo[i] = Solve(i + 2); 
		if(t1 != -1 && t2 == -1) return Memo[i] = Solve(i + 1);
		if(t1 == -1 && t2 == -1) return -1;
		return Memo[i] = Solve(i + 1) + Solve(i + 2); 
	}
	return Memo[i] = Solve(i + 1);
}

int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	while(true)
	{
		cin >> Str;
		if(Str[0] == '0') break;
		Leng = GetLeng(Str);

		for(int i = 0; i < Leng; i++)
			Memo[i] = -1;

		if(Str[Leng-1] != '0') Memo[Leng-1] = 1;

		// Nếu 2 chữ cái đầu tiên có giá trị <= 26 thì tính đến 2 kí tự
		// Ta có hai cách: ví dụ: 25
		// Có 2 cách giải mã là: BE hoặc Y
		int t = Get2Next(Str, Leng-2);

		if(t > 26 || t == 10 || t == 20) Memo[Leng-2] = 1;
		else Memo[Leng-2] = 2;

		// Print the answer to standard output(screen).
		cout << Solve(0) << endl;
	}
	return 0;//Your program should return 0 on normal termination.
}
