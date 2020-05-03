#include <iostream> 
#include <math.h> 
using namespace std; 

// Hàm trả về true nếu x là số chính phương
bool isPerfectSquare(int x)
{ 
    int s = sqrt(x); 
    return (s*s == x); 
}
  
// Trả về true nếu n là Số Fibinacci, còn lại false
bool isFibonacci(int n) 
{ 
    // n là Fibinacci nếu 5 * n * n + 4 hoặc 5 * n * n - 4 hoặc cả hai là số chính phương
    return isPerfectSquare(5*n*n + 4) || 
           isPerfectSquare(5*n*n - 4); 
} 

int main () 
{ 
	int sophantu = 0;
	cin>>sophantu;
	for(int i = 0; i<sophantu; ++i){
		int nn;
		cin>>nn;
		cout<<(char*)(isFibonacci(nn) ? "YES\n" : "NO\n");
	}
	return 0;
}