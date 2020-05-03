#include <bits/stdc++.h> 
using namespace std;
// kiem tra so nguyen to
bool isPrime(int n) 
{ 
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    
    if (n % 2 == 0 || n % 3 == 0) 
        return false;

    // kiểm tra để có thể bỏ qua năm số ở giữa trong vòng lặp bên dưới
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
}

// Hàm trả về true nếu n là số nguyên tố giai thừa
bool isFactorialPrime(long n) 
{
    // Nếu n không phải là số nguyên tố thì trả về false
    if (!isPrime(n))
        return false; 
  
    long fact = 1; 
    int i = 1; 
    while (fact <= n + 1) {

        // Tính giai thừa
        fact = fact * i;

        // Nếu n là số nguyên tố
        if (n + 1 == fact || n - 1 == fact) 
            return true; 
  
        i++; 
    }
    // n không phải là số nguyên tố
    return false; 
}

int main() 
{
	int soluongtest = 0;
	cin>>soluongtest;
	for(int i = 0; i < soluongtest; ++i){
		int n;
		cin>>n;
		if (isFactorialPrime(n))
        	cout << "YES\n"; 
    	else
        	cout << "NO\n";
	}
    return 0;
} 