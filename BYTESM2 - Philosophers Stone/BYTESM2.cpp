#include <iostream>
using namespace std;

int h, w;
int Matrix[101][101];	// Lưu giá trị lớn nhất tại mỗi ô

int main()
{
	int Testcase;
	cin >> Testcase;
	for(int tc = 0; tc < Testcase; tc++)
	{
		// Nhập đầu vào
		cin >> h >> w;
		for(int row = 0; row < h; row++)
			for(int col = 0; col < w; col++)
				cin >> Matrix[row][col];

		// Bắt đầu xét từ dòng thứ 2
		for(int row = 1; row < h; row++)
		{
			for(int col = 0; col < w; col++)
			{
				int left = 0, above = 0, right = 0, temp = 0;
				
				// Tại một ô, tôi sẽ kiểm tra giá trị của 3 ô phía trước nó
				// là trên trái, trên phải và điểm ngay phía trên
				if(col > 0)		left = Matrix[row-1][col-1];
				if(col < w-1)	right= Matrix[row-1][col+1];
				above = Matrix[row-1][col];
				
				// Tìm ra trường hợp lớn nhất
				int max = left;
				if(right > max) max = right;
				if(above > max) max = above;
				
				Matrix[row][col] += max;
			}
		}

		// Tìm ra giá trị lớn nhất ở hàng cuối cùng
		int max_stone = 0;
		for(int col = 0; col < w; col++)
			if(Matrix[h-1][col] > max_stone) max_stone = Matrix[h-1][col];
			
		cout << max_stone << endl;
	}
	return 0;
}
