#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
char A[501][200000];
bool B[501];
bool fun(int n, int sum){
  if( sum >=0 && A[n][sum]!=0 ){
    if( A[n][sum]==-1)
      return false;
    else
      return true;
  }
  if( sum == 0 ){
    A[n][0]=1;
    return true;
  }
  if( sum<0 || n==1){
    return false;
  }
  if( fun(n-1,sum-n ) ){
    A[n][sum]=1;
    B[n]=true;
    return true;
  }
  if( fun(n-1,sum)){
    A[n][sum]=1;
    B[n] = false;
    return true;
  }
  A[n][sum]=-1;
  return false;
}

int main(){
  int n,s,i,j,k,c,sum,start;
  char pos,neg;
  bool flag;
  cin>>n>>s;
  s--;
  c = n*(n+1)/2;
  c--;
  k = s + c;
  if ( k & 1){
    cout<<"Impossible"<<endl;
    return 0;
  }
  sum = k/2;
  start = 0;
  flag = fun(n,sum);
  if( !flag ){
    cout<<"Impossible"<<endl;
    return 0;
  }
  cout<<1;
  for( i=2;i<=n;i++){
    if(B[i])
      cout<<"+"<<i;
    else
      cout<<"-"<<i;
  }
  cout<<endl;
  return 0;
}
