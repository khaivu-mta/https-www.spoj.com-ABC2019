#include<iostream>
using namespace std;
 
// Lưu ma trận suduku
int Matrix[9][9];               

// Kết quả bài toán, Answer = true => có giải pháp, Answer = false nghĩa là không có
bool Answer;                

// Lưu trạng thái tại từng hàng, cột từ 0 đến 9, các số từ 1 đến 9 đã có chưa    
bool Row[9][10], Col[9][10];
 
void Next(int &row, int &col)
{
    if(col < 8) col++;
    else 
    {
        col = 0;
        row++;
    }
}
 
bool IsValid(int row, int col, int value)
{
    // Kiểm tra xem tại cột đang xét, giá trị 'value' này đã có chưa
    if(Col[col][value] == true) return false;
 
    // Kiểm tra xem tại hàng đang xét, giá trị 'value' này đã có chưa
    if(Row[row][value] == true) return false;
 
    // Kiểm tra xem trong khối nhỏ 3x3 đã có giá trị 'value' hay chưa
    int sr = row - row % 3;
    int sc = col - col % 3;
 
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(Matrix[i + sr][j + sc] == value) return false;
 
    return true;
}
 
void Check(int row, int col)
{
    // Nếu đi được hết các dòng thì có nghĩa là đã có giải pháp
    if(row == 9)
    {
        Answer = true;
        return;
    }
 
    // Nếu tại ô đó đã có giá trị khác 0 thì ta sẽ kiểm tra đến ô tiếp theo
    if (Matrix[row][col] != 0) 
    {
        Next(row, col);
        Check(row, col);
    }
    else // Nếu ô đó = 0 thì bắt đầu điền thử giá trị từ 1 đến 9
    {
        int old_row, old_col;
 
        for(int i = 1; i <= 9; i++)
        {
            // Kiểm tra xem nếu ô tại hàng row, và cột col, 
            // điền giá trị i có hợp lệ không. Nếu hợp lệ thì điền thử
            if(IsValid(row, col, i))
            {
                old_row = row;
                old_col = col;
        
                Matrix[row][col] = i;
                Row[row][i] = true;
                Col[col][i] = true;
                Next(row,col);
 
                Check(row,col);
 
                if(Answer) return;
 
                row = old_row;
                col = old_col;
                Row[row][i] = false;
                Col[col][i] = false;
                Matrix[row][col] = 0;
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
 
    // Comment dòng này trước khi submit
    // freopen("input.txt","r",stdin);
 
    int T;
    cin >> T;
 
    for(int tc = 0; tc < T; tc++)
    {
        Answer = false;
        for(int i = 0; i < 9; i++)
            for(int j = 1; j <= 9; j++)
                Row[i][j] = Col[i][j] = 0;
 
        // Nhập vào ma trận
        // đồng thời kiểm lưu trạng thái các số đã có hay chưa tại từng hàng, cột
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                int tmp;
                cin >> tmp;
                Matrix[i][j] = tmp;
 
                // Tại dòng i, số có giá trị tmp đã xuất hiện
                Row[i][tmp] = true;
                // Tại cột j, số có giá tị tmp đã xuất hiện
                Col[j][tmp] = true;
            }
 
        // Bắt đầu xét từ ô đầu tiên hàng = 0 và cột = 0
        Check(0, 0);
 
        // In kết quả
        if(Answer)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                    cout << Matrix[i][j] << " ";
                cout << endl;
            }
        }
        else cout << "No solution" << endl;
        
    }
 
    return 0;
}
