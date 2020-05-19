#include <iostream>
using namespace std;

const int MAX = 2005;

int N;		// số lượng bọ
int I;		// số lượng tương tác
int Answer;	// kết quả 1 : nếu tồn tại tình dục đồng giới

int Matrix[MAX][MAX];	// Đánh dấu tồn tại cạnh giữa 2 điểm
int Mark[MAX];			// Mảng đánh dấu loại các con bọ

/**
* u : điểm đang xét
* before: điểm trước đó
* type: loại của điểm đang xét
*/
void DFS(int u, int before, int type)
{
	Mark[u] = type;
	for(int i = 1; i <= Matrix[u][0] && !Answer; i++)
	{
		int v = Matrix[u][i];
		if(Mark[v] == -1)
		{
			// Nếu chưa duyệt thì duyệt và đánh dấu loại khác với điểm trước đó
			DFS(v, u, !type);
		}
		else if(v != before && Mark[v] == type)
		{
			// Nếu gặp một điểm mà được xét rồi và cùng loại thì có tình dục đồng giới
			// Lúc này dừng lại luôn.
			Answer = 1;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		// Nhập đầu vào
		Answer = 0;
		cin >> N >> I;
		for(int i = 0; i <= N; i++)
		{
			Mark[i] = -1;
			for(int j = 0; j <= N; j++)
				Matrix[i][j] = 0;
		}

		int a, b, m;
		for(int i = 1; i <= I; i++)
		{
			cin >> a >> b;

			m = ++Matrix[a][0];
			Matrix[a][m] = b;

			m = ++Matrix[b][0];
			Matrix[b][m] = a;
		}

		// Tìm những điểm chưa được duyệt thì sẽ duyệt
		for(int i = 1; i <= N; i++)
			if(Mark[i] == -1)
				DFS(i,-1,0);

		// Đầu ra
		cout << "Scenario #" << tc + 1  << ":"<< endl;
		if (Answer) cout << "Suspicious bugs found!" << endl;
		else cout << "No suspicious bugs found!" << endl;
	}
	return 0;
}