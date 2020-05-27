#include <cstdio>

const int MAX = 400;
typedef struct
{
	int x, y;
}Point;
typedef struct
{
	int front, real, count;
	Point data[MAX];
}Queue;
void initQueue(Queue &Q)
{
	Q.count = Q.front = 0;
	Q.real = -1;
}
int isEmpty(Queue &Q)
{
	if(Q.count == 0)return 1;
	return 0;
}
void Push(Queue &Q,Point value)
{
	Q.data[(++Q.real)%MAX] = value;
	Q.count ++;
}
Point Pop(Queue &Q)
{
	Point value = Q.data[Q.front];
	Q.front = (Q.front++)%MAX;
	Q.count--;
	return value;
}
int nRow, nCol, count, min;
char Map[21][21];
Point dirty[12];
int distance[12][21][21];
int visited[12];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
Queue Q;
void BFS(int index)
{
	Point value = dirty[index];
	distance[index][value.x][value.y] = 1;
	initQueue(Q);
	Push(Q,value);
	while(!isEmpty(Q))
	{
		value = Pop(Q);
		for(int i=0; i<4; i++)
		{
			int tempx = value.x + dx[i];
			int tempy = value.y + dy[i];
			if(tempx>=0 && tempx<nRow && tempy>=0 && tempy<nCol && distance[index][tempx][tempy] == 0 && Map[tempx][tempy] != 'x')
			{
				distance[index][tempx][tempy] = distance[index][value.x][value.y] + 1;
				Point temp;
				temp.x = tempx; temp.y = tempy;
				Push(Q, temp);
			}
		}
	}
}
void get_min(int index,int nDirty, int dis)
{
	if(dis>min)return;
	if(nDirty == count)
	{
		if(dis<min)min = dis;
		return;
	}
	visited[index] = 1;
	for(int i=1; i<count; i++)
	{
		if(visited[i] == 0)
		{
			if(distance[index][dirty[i].x][dirty[i].y] != 0)get_min(i, nDirty + 1, dis + distance[index][dirty[i].x][dirty[i].y] - 1);
			else break;
		}
	}
	visited[index] = 0;

}
int main()
{
	while(1)
	{
		scanf("%d %d", &nCol, &nRow);
		if(nCol == 0 && nRow == 0)break;
		for(int i=0; i<nRow; i++)scanf("%s", &Map[i]);
		count = 1;
		Point value;
		for(int i=0; i<nRow; i++)
		{
			for(int j=0; j<nCol; j++)
			{
				if(Map[i][j] == 'o')
				{
					dirty[0].x = i;
					dirty[0].y = j;
				}
				else if(Map[i][j] == '*')
				{
					value.x = i;
					value.y = j;
					dirty[count++] = value;
				}
			}
		}
		// find min distance
		for(int i=0; i<count; i++)
			BFS(i);
		min = 5000;
		get_min(0, 1, 0);
		if(min == 5000)printf("-1\n");
		else printf("%d\n", min);
		for(int index =0; index<count; index++)
			for(int i=0; i<nRow; i++)
				for(int j=0; j<nCol; j++)distance[index][i][j] = 0;
	}
	return 0;
}
