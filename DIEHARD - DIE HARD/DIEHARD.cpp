#include <iostream>
using namespace std;

const int MAX_INT = 1<<20;
const int MAX = 30;

int w, h;               // Kích thước ma trận
int SR, SC, DR, DC;     // Lần lượt là hàng, cột của điểm bắt đầu, kết thúc
int number;             // Số lượng điểm mà bạn có thể đi vào
int Matrix[MAX][MAX];   // Ma trận đầu vào
int Distance[MAX][MAX]; // Ma trận khoảng cách sau khi áp dụng Dijkstra
bool Mark[MAX][MAX];    // Ma trận đánh dấu

/*
* Tìm điểm chưa thăm, có thể đi và giá trị ma trận khoảng cách là nhỏ nhất
* Tham số dạng tham chiếu để lưu tọa độ hàng, cột tìm được
*/
void FindMin(int &rmin, int &cmin)
{
	int _min = MAX_INT;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
			if(Mark[i][j] == false && Matrix[i][j] != -1 && Distance[i][j] < _min)
			{
				_min = Distance[i][j];
				rmin = i;
				cmin = j;
			}
}

int drow[] = {-1,0,1, 0};
int dcol[] = { 0,1,0,-1};

/*
* Thuật toán Dijkstra tại điểm bắt đầu là (sr, sc)
*/
void Dijkstra(int sr, int sc)
{
    // Đếm số điểm đã xét, khi duyệt hết các điểm có thể thì dừng
	int cnt = 0;
	Distance[sr][sc] = 0;
	while (cnt < number)
	{
		int rmin = 0, cmin = 0;
		FindMin(rmin,cmin);

		Mark[rmin][cmin] = true;
		cnt++;
		for(int i = 0; i < 4; i++)
		{
			int r = rmin + drow[i];
			int c = cmin + dcol[i];
			if( r >= 0 && r < h && c >= 0 && c < w &&
			    Mark[r][c] == false && Matrix[r][c] != -1 && 
			    Distance[rmin][cmin] + Matrix[r][c] < Distance[r][c]
			    )
				Distance[r][c] = Distance[rmin][cmin] + Matrix[r][c];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
//	freopen("input.txt","r",stdin);

	while(true)
	{
		cin >> w >> h;	
		if(w==0 && h==0) break;

		SR = SC = DR = DC = number = 0;
		for(int i = 0; i < h; i++)
		{
			char temp[MAX];
			cin >> temp;
			for(int j = 0; j < w; j++)
			{
				if(temp[j]=='X')
				{
					Matrix[i][j] = -1;
					number++;
				}
				else if(temp[j]=='S')
				{
					Matrix[i][j] = 0;
					SR = i;
					SC = j;
				}
				else if(temp[j]=='D')
				{
					Matrix[i][j] = 0;
					DR = i;
					DC = j;
				}
				else Matrix[i][j] = temp[j] - '0';
				Distance[i][j] = MAX_INT;
				Mark[i][j] = false;
			}
		}
		number = w*h - number;
		Dijkstra(SR,SC);
		cout << Distance[DR][DC] << endl;
	}
	return 0;
}