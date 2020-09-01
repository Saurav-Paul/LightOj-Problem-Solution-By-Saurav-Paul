
				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

long long F(long long int n){
	long long int res = 0 ;
	for( int i= 1 ,x=n, k =0 ; i <= x; i++,k++){
		long  long int y = n / i ;
		res += k * ( x-y) ;
		x -=(x-y) ;
		if( x >= i ) res += y ; ;
	}
	return res ;
}

void solve () {
	long long int n ; scanf("%lld", &n) ;
	printf("%lld\n",F(n) ) ;
	
}
int main()
{
	int t ; scanf("%d",&t) ;
	for(int i = 1; i <= t ; i++){
		printf("Case %d: ",i) ;
		solve() ;
	}
    return 0;
}
