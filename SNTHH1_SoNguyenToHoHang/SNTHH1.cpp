#include <iostream> 
#include<math.h> 
using namespace std; 

bool isPrime(int n) 
{
    if (n <= 1) 
        return false;
    int n4 = n + 4;
    int n2 = sqrt(n4);
    int n1 = sqrt(n);
    for (int i = n2; i >= 2; i--) {
        if (n4 % i == 0 && i <= n1 ){
        	return false;
		}
	}
    return true;
}

int main()
{ 
    int soluong = 0;
    int n = 0;
    cin>>soluong;
    while(soluong-->0){
    	cin>>n;
    	if(n<=1)
    		continue;
    	if(isPrime(n)) {
    		cout<<"YES\n";
		}
		else
			cout<<"NO\n";
	}
} 