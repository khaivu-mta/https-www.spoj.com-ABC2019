#include <iostream> 
#include<bits/stdc++.h> 
using namespace std; 

bool isPrime(int n) 
{
    if (n <= 1) 
        return false;
  
    // kiem tra tu 2 den sqrt(n)
    double n2 = sqrt(n);
    for (int i = 2; i <= n2; i++) 
        if (n % i == 0) 
            return false;
    return true;
} 

int main() 
{ 
    int soluong = 0;
    cin>>soluong;
    for(int i = 0; i < soluong; ++i){
        int n = 0;
        cin>>n;
        if(n<=1)
            continue;
        for(int j = n; j > 1; --j){
            if(isPrime(j)){
                cout<<j<<"\n";
                break;
            }
        }
    }
} 