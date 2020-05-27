#include <stdio.h>

int visited[7][8];
int matrix[7][8];
int F[7][7];
int result = 0;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
void load_domino_in_matrix(int x, int y)
{
	if(x==7)
	{
		result++;
		return;
	}
	if(visited[x][y]==0)
	{
		int one, two;
		one = matrix[x][y];
		for(int i=0; i<2; i++)
		{
			int tempx = x + dx[i];
			int tempy = y + dy[i];
			if(tempx>=0&&tempx<7&&tempy>=0&&tempy<8&&visited[tempx][tempy]==0)
			{
				two = matrix[tempx][tempy];
				if(one<=two && F[one][two])
				{
					F[one][two] = 0;
					visited[x][y] = visited[tempx][tempy] = 1;
					if(y<7)load_domino_in_matrix(x, y+1);
					else load_domino_in_matrix(x+1, 0);
					visited[x][y] = visited[tempx][tempy] = 0;
					F[one][two] = 1;
				}
				else if(F[two][one])
				{
					F[two][one] = 0;
					visited[x][y] = visited[tempx][tempy] = 1;
					if(y<7)load_domino_in_matrix(x, y+1);
					else load_domino_in_matrix(x+1, 0);
					visited[x][y] = visited[tempx][tempy] = 0;
					F[two][one] = 1;
				}
			}
		}
	}
	else
	{
		if(y<7)load_domino_in_matrix(x, y+1);
		else load_domino_in_matrix(x+1, 0);
	}
}

int main()
{
	int number_test, i, j, test;
	for(int i=0; i<=6; i++)
		for(int j=i; j<=6; j++)
			F[i][j] = 1;
	scanf("%d", &number_test);
	for(test=0; test<number_test; test++)
	{
		for(i=0; i<7; i++)
			for(j=0; j<8; j++)
				scanf("%d", &matrix[i][j]);
		result = 0;
		load_domino_in_matrix(0, 0);
		printf("%d\n", result);
	}

}
