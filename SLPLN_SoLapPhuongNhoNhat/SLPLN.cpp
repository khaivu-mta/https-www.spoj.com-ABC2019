#include <bits/stdc++.h>
using namespace std;

int InLapPhuong(int a, int b)
{
    int max = 0;
	int j;
    for (int i = a; i <= b; i++) {
        for (j = 1; j * j * j <= i; j++) {
            if (j * j * j == i) {
                max = j;
            	break;
            }
        }
    }
    return max;
}

int main()
{
    int gioihan1 = 0, input = 0, soluong = 0;
    cin>>soluong;
    for(int i = 0; i < soluong; ++i){
    	cin>>input;
	    cout<<InLapPhuong(gioihan1, input)<<"\n";
	}
    return 0;
}