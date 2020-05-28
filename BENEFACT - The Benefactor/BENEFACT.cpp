#include <iostream>
using namespace std;
 
const int MAX = 50005;
 
struct Node
{
    int leng;
    int id;
    Node *next;
};
 
class List
{
public:
    Node *begin;
public:
    List()
    {
        begin = 0;
    }
 
    void Add(int id, int leng)
    {
        Node *tmp = new Node;
        tmp->id   = id;
        tmp->leng = leng;
 
        tmp->next = begin;
        begin = tmp;
    }
};
 
int Answer;         // Lưu kết quả
int T, N, idMax;    
int Distance[MAX];  // Mảng lưu khoảng cách từ điểm bắt đầu BFS đến các điểm còn lại
List MyList[MAX];   // Lưu danh sách đầu vào
 
int queue[MAX];
int fr, re, leng;
 
void EnQueue(int u)
{
    queue[re] = u;
    re = (re + 1) % MAX;
    leng++;
}
 
int DeQueue()
{
    int t = queue[fr];
    fr = (fr + 1) % MAX;
    leng--;
    return t;
}
 
// tìm ra điểm có khoảng cách xa nhất với điểm bắt đầu BFS
void FindMax()
{
    for(int i = 1; i <= N; i++)
        if(Distance[i] > Answer)
        {
            Answer = Distance[i];
            idMax  = i;
        }
}
 
// Dùng BFS để tìm khoảng cách từ 1 điểm đến các điểm còn lại
// Lưu vào mảng Distance[]
void BFS(int u)
{
    fr = re    = leng = 0;
 
    for(int j = 1; j <= N; j++)
        Distance[j] = 0;
 
    EnQueue(u);
    Distance[u] = 1;
 
    while(leng > 0)
    {
        int k = DeQueue();
        Node *p = MyList[k].begin;
        int v,l;
 
        while(p != 0)
        {
            v = p->id;
            l = p->leng;
 
            if(Distance[v] == 0)
            {
                Distance[v] = Distance[k] + l;
                EnQueue(v);
            }
 
            p = p->next;
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
 
    // comment dòng này trước khi submit
    // freopen("input.txt","r",stdin);
 
    cin >> T;
 
    for(int tc = 0; tc < T; tc++)
    {
        Answer = 0;
        for(int i = 1; i <= N; i++)
            MyList[i].begin = 0;
 
        cin >> N;
 
        for(int i = 0; i < N-1; i++)
        {
            int st, ed, leng;
            cin >> st >> ed >> leng;
 
            MyList[st].Add(ed,leng);
            MyList[ed].Add(st,leng);
        }
        
        BFS(1);
        FindMax();
 
        BFS(idMax);
        FindMax();
        
        // In ra kết quả
        cout << Answer - 1 << endl;
    }
 
    return 0;
}
