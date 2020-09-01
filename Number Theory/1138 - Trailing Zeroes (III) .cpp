				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;

ll zero_cnt(ll n) {
	ll x = 5;
	ll zero = 0 ;
	while(x <= n){
		zero += n/ x;
		x *= 5;
	}
	return zero ;
}

void solve() {
	ll Q ;
	scanf("%lld",&Q) ;
	
	ll low = 0 , high = 1e9 ;
	while( low < high) {
		ll mid = (low + high ) >> 1 ;

		ll zero = zero_cnt(mid) ;
		if( zero >= Q ){
			high = mid ;
		}
		else low = mid+1;
	}
	if(zero_cnt(low) == Q) printf("%lld\n",low);
	else puts("impossible") ;
}

int main()
{

	int t ; scanf("%d",&t) ;
	for(int i = 0 ; i < t ; i++){
		printf("Case %d: ",i+1);
		solve() ;
	}

    return 0;
}
