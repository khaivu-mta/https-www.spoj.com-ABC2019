#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define tol (1e-13)
#define N 0x20
using namespace std;
typedef long long i64;
enum { D, S };
enum { FIRST, SECOND };
#define oo (1LL<<60)

int n;
i64 z[2][2][N][N],c[N],pref[N];

i64 sum( int i, int j ) {
	return pref[j]-pref[i-1];
}

i64 calc_z( int t, int mode, int i, int j ) {
	if ( z[t][mode][i][j] < +oo )
		return z[t][mode][i][j];
	if ( i > j ) return +oo;
	if ( i == j ) 
		return z[t][mode][i][j] = c[i];
	assert( i < j );
	if ( t == FIRST && mode == D ) {
		return z[t][mode][i][j] = sum(i,j)-min(calc_z(t^1,mode,i,j-1),calc_z(t^1,mode,i+1,j));
	}
	else if ( t == FIRST && mode == S ) {
		return z[t][mode][i][j] = sum(i,j)-min(calc_z(t^1,mode,i,j-1),calc_z(t^1,mode,i+1,j));
	}
	else if ( t == SECOND && mode == D ) {
		return z[t][mode][i][j] = sum(i,j)-max(calc_z(t^1,mode,i,j-1),calc_z(t^1,mode,i+1,j));
	}
	else {
		assert( t == SECOND && mode == S ) ;
		return z[t][mode][i][j] = sum(i,j)-min(calc_z(t^1,mode,i,j-1),calc_z(t^1,mode,i+1,j));
	}
}

int main() {
	int i,j,k,t,ts;
	for ( scanf("%d",&ts); ts--; ) {
		scanf("%d",&n);
		for ( i = 1; i <= n; ++i )
			scanf("%lld",c+i), pref[i] = pref[i-1]+c[i];
		for ( i = 0; i <= n; ++i )
			for ( j = 0; j <= n; ++j )
				for ( t = FIRST; t <= SECOND; ++t )
					for ( k = D; k <= S; ++k )
						z[t][k][i][j] = +oo;
		printf("%lld %lld\n",calc_z(FIRST,D,1,n),calc_z(FIRST,S,1,n));
	}
	return 0;
}
