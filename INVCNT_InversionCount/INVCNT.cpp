#include<iostream>
using namespace std;

const int MAX = 200005;

long long Answer;
int N, T;
int A[MAX];

void Merge(int *a, int left, int m, int right)
{
	int *temp = new int[right - left + 1];
	int k = 0, i = left, j = m + 1;

	while(i <= m && j <= right)
	{
		if(a[i] > a[j])
		{
			temp[k++] = a[i++];
			
			// Rõ ràng ở đây i < j mà a[i] > a[j]
			// thì ta đã có cặp đảo nghịch ở đây.
			// Hơn nữa, bạn để ý rằng, vì tôi sắp xếp dãy giảm dần
			// nên nếu a[i] > a[j] thì a[i] cũng sẽ lớn hơn các số ở nhánh phải
			// chú ý là tôi đang trộn 2 nhánh đã sắp xếp, nên a[j] là số lớn nhất
			// nghĩa là tôi có thêm (right - j + 1) cặp đảo nghịch
			Answer += right - j + 1;
		}
		else 
		{
			temp[k++] = a[j++];
		}
	}

	while(i <= m) temp[k++] = a[i++];
	while(j <= right) temp[k++] = a[j++];

	for(int i = 0; i < k; i++)
		a[i + left] = temp[i];
	delete[] temp;
}

void MergeSort(int *a, int left, int right)
{
	int m;
	if(left < right)
	{
		m = (left + right) / 2;
		MergeSort(a, left, m);
		MergeSort(a, m + 1, right);
		Merge(a, left, m, right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	//freopen("input.txt","r",stdin);

	cin >> T;
	for(int tc = 0; tc < T; tc++)
	{
		//input
		Answer = 0;
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> A[i];

		// implementing code below
		MergeSort(A, 0, N-1);

		//output
		cout << Answer << endl;
	}
	return 0;
}
/*#include <iostream>
using namespace std; 

int getInvCount(int arr[], int n) 
{ 
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++;
    return inv_count; 
} 

int main()
{ 
    int soluong = 0;
    int n = 0;
    cin>>soluong;
    while(soluong-->0){
    	cout<<"\n";
    	cin>>n;
    	if(n<=1)
    		continue;
    	int arr[n];
    	int i = 0;
    	while(i < n){
    		cin>>arr[i++];
		}
    	cout<<getInvCount(arr, n);
	}
}
*/