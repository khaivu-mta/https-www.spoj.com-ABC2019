#include<iostream>
using namespace std;

const int MAX = 10005;

int  Matrix[MAX][MAX];      // Ma trận lưu trạng thái của đồ thị
bool Visit[MAX];            // Mảng đánh dấu mỗi điểm được thăm hay chưa
int  cnt;                   // Đếm số điểm đi qua trong 1 lần duyệt để biết 
                            // đồ thị có liên thông hay không
int  N, M;                  // Lần lượt là số đỉnh và số cạnh

void Try(int u)
{
	Visit[u] = 1;
	cnt++;

	for (int i = 1; i <= Matrix[u][0]; i++)
	{
		int v = Matrix[u][i];
		if(!Visit[v]) Try(v);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	// Comment dòng này trước khi submit
	// freopen("input.txt","r",stdin);

	cin >> N >> M;
	if(M == 0) cout << "NO" << endl;
	else
	{
		cnt = 0;

		for(int i = 0; i <= N; i++)
		{
			Visit[i] = false;
			for(int j = 0; j <= N; j++)
				Matrix[i][j] = 0;
		}

		// Tại hàng thứ i trong ma trận, 
		// ta sẽ lưu id của những đỉnh kề với đỉnh i
		// Matrix[i][0] lưu số lượng đỉnh kề.
		for(int i = 0; i < M; i++)
		{
			int a, b, m;
			cin >> a >> b;

			m = ++Matrix[a][0];
			Matrix[a][m] = b;
		
			m = ++Matrix[b][0];
			Matrix[b][m] = a;
		}

		// Nếu số cạnh < số đỉnh trừ 1 thì chắc chắn không phải là cây
		if(M == N-1)
		{
			// Thử duyệt tại một điểm bất kì, ở đây là điểm 1
			Try(1);

			// Khi số cạnh là N - 1 và đi được qua hết N điểm 
			// thì chứng tỏ đồ thị liên thông.
			// và không có chu trình. Nên sẽ là cây.
			if(cnt == N) cout << "YES" << endl;
			else cout << "NO" << endl;

		}
		else cout << "NO" << endl;
		
	}

	return 0;
}
