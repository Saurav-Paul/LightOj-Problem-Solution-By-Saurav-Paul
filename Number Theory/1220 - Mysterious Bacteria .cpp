				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;

void factorization(ll n, map<ll,ll> &sample, bool even){
	for(int i = 2 ; i <= n ; i++ ){
		if(i > sqrt(n) ) break ;
		
		ll cnt = 0;
		ll curr = n ;
		while(n%i==0){
			cnt ++;
			n /= i ;
		}
		if((cnt&1 || even) && n==1){
			sample[i] += cnt ;
		}
		else n = curr  ;
	}
	if(n > 1 ) sample[n] ++; 

}
void solve() {
	
	ll x; 
	scanf("%lld",&x) ;
	map<ll , ll> fact;
	factorization(abs(x) , fact, (x >= 0) );

	ll ans = 1 ;
	for(auto i : fact){
		ans = max(ans, i.second ) ;
	}
	printf("%lld\n",ans) ;

	
}

int main()
{
	int testcase ; scanf("%d",&testcase ) ;
	for(int i = 1; i <= testcase ; i++){
		printf("Case %d: ",i);
		solve() ;
	}

    return 0;
}
