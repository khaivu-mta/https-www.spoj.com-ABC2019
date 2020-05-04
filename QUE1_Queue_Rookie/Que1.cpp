#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX=1001;
int arr[MAX];
int high_index[100005];
int finalpos[MAX];
int main()
{
    int T;
    scanf(" %d",&T);
    while(T--){
    int N;
    scanf(" %d",&N);
        int i,j;
        // reset gia tri cua mang ket qua
        memset(finalpos,0,sizeof(finalpos));
        for(i=0;i<N;i++) scanf(" %d",&arr[i]);
        for(i=0;i<N;i++) scanf(" %d",&high_index[arr[i]]);
        sort(arr,arr+N);
        for(i=0;i<N;i++){
 
			int cnt=high_index[arr[i]];
			// tim vi tri
            for(j=0;j<N;j++){
            	// khi nao bien dem bang 0 thi dien no vao
                if(cnt==0 && finalpos[j]==0) {
                    finalpos[j]=arr[i];
                    break;
                }
                // khi o truoc trong thi giam bien dem
                if(finalpos[j]==0) cnt--;
            }
 
        }
        for(i=0;i<N;i++) printf("%d ",finalpos[i]);
        printf("\n");
    }
    return 0;
}
/*//bad
#include <bits/stdc++.h>
using namespace std;

inline void inp( int &n ) {
    n=0;
    int ch=getchar();
    int sign=1;
    while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    n=n*sign;
}

int n;
int height[1000];
int nbhigher[1000];

void quickSort(int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = height[(left + right) / 2];

    while (i <= j) {
        while (height[i] < pivot)
              i++;
        while (height[j] > pivot)
              j--;
        if (i <= j) {
              tmp = height[i];
              height[i] = height[j];
              height[j] = tmp;
              tmp = nbhigher[i];
              nbhigher[i] = nbhigher[j];
              nbhigher[j] = tmp;
              i++;
              j--;
        }
    };

    if (left < j)
        quickSort(left, j);
    if (i < right)
        quickSort(i, right);
}

void findAns(vector<int> * rs, int left, int right) {
    (* rs).clear();
    if (left == right) {
        (* rs).push_back(height[left]);
    } else {
        bool inserted = false;
        vector <int> tmp_rs; tmp_rs.clear();
        findAns(&tmp_rs, left+1, right);
        for (int i = 0; i < tmp_rs.size(); i++) {
            if (tmp_rs.size()-i == nbhigher[left]) {
                (*rs).push_back(height[left]);
                inserted = true;
            }
            (*rs).push_back(tmp_rs[i]);
        }
        if (!inserted)
            (*rs).push_back(height[left]);
    }
}

int main() {
    int t;
    vector <int> ans;
    inp(t);
    for (int zzz = 0; zzz < t; zzz++) {
        inp(n);
        for (int i = 0; i < n; i++)
            inp(height[i]);
        for (int i = 0; i < n; i++)
            inp(nbhigher[i]);
        quickSort(0, n-1);
        findAns(&ans, 0, n-1);
        for (int i = ans.size()-1; i >= 0; i--) {
            cout << ans[i];
            if (i != 0)
                cout << " ";
        }
        cout << "\n";
    }
}*/
/*//other way
#include <iostream>
using namespace std;

//Hoán vị 2 số a và b
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//Sắp xếp dãy theo chiều tăng dần của dãy a
//Dãy b được đi kèm theo dãy a
//left, right: chỉ số trái, phải của dãy
void QuickSort_Ascending(int *a, int *b, int left, int right)
{
    int i = left, j = right;
    int pivot = a[(i+j)/2];
    while(i <= j)
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i <= j)
        {
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i++;
            j--;
        }
    }
    if(left < j) QuickSort_Ascending(a,b,left,j);
    if(i < right) QuickSort_Ascending(a,b,i,right);
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);

    int T, N;
    int height[1000];       // Lưu chiều cao của N người
    int numTallerBef[1000]; // Lưu số người cao hơn đứng trước
    int result[1000];       // Lưu dãy kết quả
    
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        // Nhập đầu vào
        cin >> N;
        for(int i = 0; i <  N; i++)
            cin >> height[i];
        for(int i = 0; i < N; i++)
        {
            cin >> numTallerBef[i];
            result[i] = -1;
        }

        // Sắp xếp lại dãy theo chiều tăng dần của chiều cao
        QuickSort_Ascending(height, numTallerBef, 0, N-1);
            
        // Duyệt dãy sau khi sắp xếp để tìm vị trí đúng
        int count, j, temp;
        for(int i = 0; i < N; i++)
        {
            temp = numTallerBef[i];
            j = count = 0;

            if(temp == 0)
            {
                for(j = 0; j < N; j++)
                    if(result[j] == -1) break;
                result[j] = height[i];
            }
            else
            {
                for(j = 0; j < N; j++)
                {
                    if(result[j] == -1) count++;
                    if(count == temp && result[j+1] == -1) break;
                }
                result[j+1] = height[i];
            }
        }
        for(int i = 0; i< N; i++)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}*/