#include<iostream>
using namespace std;

const int MAX = 105;
const char Array[] = "ALLIZZWELL";

int  R, C;              // Lưu số lượng hàng và cột ở ma trận
int  Answer;            // Lưu kết quả của bài toán
char Matrix[MAX][MAX];  // Ma trận đầu vào
bool Visit[MAX][MAX];   // Đánh dấu trạng thái là thăm hay chưa.

int drow[8] = {-1,-1,0,1,1, 1, 0,-1};
int dcol[8] = { 0, 1,1,1,0,-1,-1,-1};

/*
* row, col lần lượt là hàng và cột đang xét
* current là chỉ số của kí tự hiện tại trong mảng Array[] = "ALLIZZWELL"
* chỉ số bắt đầu từ 0 và cuối cùng là 9
*/
void Start(int row, int col, int current)
{
	// Nếu tìm được đường đi
	if(current == 9)
	{
		Answer = 1;
		return;
	}

	// Kiểm tra 8 hướng kề với ô đang xét
	for(int i = 0; i < 8; i++)
	{
		int r = row + drow[i];
		int c = col + dcol[i];

		/*
		* Ô nhảy được tới phải là ô trong ma trận
		* Chưa được thăm 
		* Và là kí tự tiếp theo trong mảng Array[] trên
		*/
		if (r >= 0 && r < R && c >= 0 && c < C &&
			!Visit[r][c] && Matrix[r][c] == Array[current+1])
		{
			Visit[r][c] = true;
			Start(r, c, current+1);
			Visit[r][c] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for(int tc = 0; tc < T; tc++)
	{
		Answer = 0;

		cin >> R >> C;
		for(int i = 0; i < R; i++)
			cin >> Matrix[i];

		for(int i = 0; i < R; i++)
			for(int j = 0; j < C; j++)
				Visit[i][j] = false;

		// Tìm tất cả các kí tự A trong ma trận và tìm đường đi từ đó
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
				if(Matrix[i][j] == 'A')
				{
					Visit[i][j] = true;
					Start(i, j, 0);
					Visit[i][j] = false;

					// Nếu đã tìm được đường đi thoả mãn thì thoát luôn.
					if(Answer) break;
				}

			if(Answer) break;
		}

		// In ra kết quả
		cout << endl;
		if(Answer) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}