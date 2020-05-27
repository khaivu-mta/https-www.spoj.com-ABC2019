#include <bits/stdc++.h>

typedef long long  ll;

#define MOD   1000000007
#define scll(t)  scanf("%lld",&t)
#define sc(t)  scanf("%d",&t)
#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<b?a:b)
#define gc   getchar_unlocked
#define mp   make_pair
#define pb   push_back
#define freinp  freopen("in.txt","r",stdin)
#define freout  freopen("out.txt","w",stdout)
#define Size(a)  int((a).size())
#define F   first
#define S   second
#define pdiii       pair<pair<double,int>, pair<int,int> >
#define pdd         pair<double,double>


using namespace std;


int components, N, W;
double R, U, V;
int parent[1000010];
double ans0,ans1;
vector<pdd> city;
vector<pdiii> roads;

int find(int a)
{
 if(parent[a]!=a)
  parent[a] =  find(parent[a]);
 return parent[a];
}
void unite(int a,int b,double cost,int type)
{

 int u=find(a);
 int v=find(b);
 if(u==v)
  return;
 parent[u]=v;
 if(type==0)
        ans0 += cost;
    else ans1 +=cost;
    components--;

}


void calculateDistance()
{
    int i, j , type;
    double d,diff_x,diff_y;
    double cost;
    for(i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                diff_x = city[i].F - city[j].F;
                diff_y = city[i].S - city[j].S;             
                d = hypot(diff_x , diff_y);
                if(d <= R)
                    cost = d*U,type = 0;
                else cost = d*V, type = 1;
                roads.pb(pdiii(mp(cost,type),mp(i,j)));
            }
        }
}


int main()
{
 int t, test, i, to, from, type;

 double dist,x,y;
 double cost;
 sc(t);
 test = 0;
 while(t--)
 {
        test++;
        ans0 = 0.0;
        ans1 = 0.0;
  scanf("%d%lf%d%lf%lf",&N,&R,&W,&U,&V);
        city.clear();
        roads.clear();
  for(i=0;i<1000010;i++)
  {
            parent[i] = i;
  }

  for(i=1;i<=N;i++)
  {
   scanf("%lf%lf",&x,&y);
   city.pb(pdd(x,y));
  }
  calculateDistance();
  sort(roads.begin(),roads.end());

        components = N;
  for(i=0;i<Size(roads);i++)
  {
            cost = roads[i].F.F;
            type = roads[i].F.S;
            from = roads[i].S.F;
            to = roads[i].S.S;

   unite(from,to,cost,type);
   if(components == W || components == 1)
                break;
  }
  printf("Caso #%d: %0.3lf %0.3lf\n",test,ans0,ans1);

 }
}
