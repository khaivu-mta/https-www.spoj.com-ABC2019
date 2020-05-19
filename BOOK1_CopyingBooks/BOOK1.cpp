#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
const int inf = 0x7fffffff;
using namespace std;
ll ul,lol;
void print(ll arr[],int n,int k,ll upplmt)
{
    int slcount[500],c=0; // to record where '/' will b put
    ll sum=0;
    vector <int > v;
    int cnt = 1;
    for(int i=n-1;i>-1;i--)
    {
        if(sum+arr[i] > upplmt || i == k-cnt-1)
        {
            sum=0;
            v.pb(-1);
            cnt++;
        }
        sum+=arr[i];
        v.pb(arr[i]);
    }
    reverse(v.begin(),v.end());
    int l = v.size();
    for(int i=0;i<l;i++)
    {
        if(v[i] == -1 )
            printf("/ ");
        else
            cout << v[i] << " ";
    }
    cout << endl;
}
bool ok(ll arr[],int n,ll p,int k)
{
    int cnt = 1;
    ll sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] > p)
        {
            cnt = inf;
            break;
        }
        if(sum + arr[i] > p)
        {
            cnt++;
            sum=0;
        }
        sum += arr[i];
    }
    //cout << cnt << endl;
    return (cnt <= k);
}
void binary(ll arr[],int n,int k)
{
    ll low = lol;
    ll high = ul;
    while(low < high)
    {
        ll mid = low + (high - low)/2;
        if(ok(arr,n,mid,k))
            high = mid;
        else
            low = mid+1;
    } 
    
    //cout << high << endl;
    print(arr,n,k,high);
}
int main()
{
    int t,n,k;
    ll arr[505],sum=0;
    cin >> t;
    while(t--)
    {   sum=0;
        cin >> n >> k;
        ul=0;
        lol=inf;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            ul+=arr[i];
            if(lol>arr[i])
                lol=arr[i];
        }
        binary(arr,n,k);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define mod 1000000009
bool check(int A , vector<int> &v , ull mid){
    int  n = v.size() , i = 0 , tot = 1;
    ull count = 0;
    while(i < n)
    {
        if((long long)v[i] > mid)
            return false;
        if(count + (long long )v[i] > mid){
            tot++;
            count = 0;
        }
        if(count <= mid){
            count += (long long)v[i];
            i++;
        }
    }
    if(tot <= A)
        return true;
    return false;
}
bool print(int pos , int k ,vector<int> &v , ull mid){
    ull count = 0;
    int pos_till = -1;
    for(int i = pos ; i>= 0 ; i--){
        if(count + v[i] > mid || i == k-2){
            print(i , k-1  , v , mid);
            pos_till = i;
            break;
        }
        count += v[i];
    }
    if(pos_till >= 0)
        printf("/ ");
    for(int i = pos_till +1 ; i<= pos ; i++)
        printf("%d ", v[i]);
}
ull binary_search(vector<int> &v , int A){
    ull low = 1 , high = LLONG_MAX , mid , ans = LLONG_MAX;
    while(low < high){
        mid = (low + high)>>1;
        if(check(A , v , mid)){
            ans = min(ans , mid);
            high = mid;
        } else
            low = mid+1;
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m , k;
        scanf("%d%d",&m,&k);
        vector<int> v(m);
        for(int i = 0 ; i < m ; i ++){
            scanf("%d",&v[i]);
        }
        v.pb(0);
        ull ans = binary_search(v , k);
        print(v.size() - 2 , k , v , ans);
        printf("\n");
    }
    return 0;
}
*/
/*
#include<iostream>
using namespace std;
 
typedef long long int ll;
 
const int MAX = 505;
 
ll M, K;                // Lưu số lượng cuốn sách, và số phần cần chia
ll Left,Right, mid;        
ll Page[MAX];           // Lưu số lượng trang sách của mỗi cuốn
ll Index[MAX];          // Mảng lưu chỉ số của phần tử đầu tiên của mỗi phần
ll ValidIndex[MAX];     // Kết quả cuối cùng
 
// Cập nhật lại từng phần sao cho tổng mỗi phần không lớn hơn mid
void Update(ll id)
{
    ll sum = 0, t = Index[id];
 
    for(ll i = Index[id + 1] - 1; i >= t; i--)
    {
        sum += Page[i];
        
        if(sum == mid)
        {
            Index[id] = i;
            break;
        }else if(sum > mid)
        {
            Index[id] = i + 1;
            break;
        }
    }
}
 
// Kiểm tra xem với với số lượng lớn nhất của các phần là mid
// có hợp lệ hay không
bool IsValid()
{
    for(int i = 0; i < K; i++)
        Index[i] = i;
    Index[K] = M;
 
    // Cập nhật lại từng phần
    for(int i = K - 1; i >= 0; i--)
        Update(i);
 
    // Nếu sau
    if (Index[0] > 0) return false;
 
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    // comment dòng này trước khi submit
    // freopen("input.txt","r",stdin);
 
    int T;
    cin >> T;
 
    for(int tc = 0; tc < T; tc++)
    {
        ll max_page = 0;        // Tìm ra cuốn sách có nhiều trang nhất
        ll sum_page = 0;        // Tìm tổng số trang
        
        cin >> M >> K;
 
        for(int i = 0; i < M; i++)
        {
            cin >> Page[i];
 
            if(Page[i] > max_page) max_page = Page[i];
            sum_page += Page[i];
        }
            
        // Khi chia ra thành các phần, thì tổng lớn nhất của các phần
        // sẽ nằm trong khoảng từ Left = max_page (số trang nhiều nhất)
        // và Right = sum_page (số trang nhiều nhất)
        Left  = max_page;
        Right = sum_page;
 
        // Triển khai thuật toán chia để trị
        while (Left < Right)
        {
            mid = (Left + Right) / 2;
            
            if (IsValid())
            {
                Right = mid;
                
                // Ta dùng mảng để lưu lại chỉ số của các phần tử
                // để phân chia các phần.
                for(int i = 0; i < K; i++)
                    ValidIndex[i] = Index[i];
            }
            else
            {
                Left = mid + 1;
            }
        }
 
        // In ra kết quả
        for(int i = 0; i < K - 1; i++)
        {
            for(int j = ValidIndex[i]; j < ValidIndex[i+1]; j++)
                cout << Page[j] << " ";
            cout << "/ ";
        }
        
        for(int i = ValidIndex[K-1]; i < M; i++)
        {
            cout << Page[i];
            if(i == M-1) break;
            cout << " ";
        }
 
        cout << endl;
    }
 
    return 0;
}
*/