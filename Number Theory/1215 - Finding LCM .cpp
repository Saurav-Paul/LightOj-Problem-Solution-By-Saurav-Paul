				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;

void factorization(ll n, map<ll,ll> &sample){
	for(int i = 2 ; i <= n ; i++ ){
		if(i > sqrt(n) ) break ;
		while(n%i==0){
			sample[i] ++;
			n /= i ;
		}
	}
	if(n > 1 ) sample[n] ++; 

}

void solve() {
	ll a , b , l , c ; scanf("%lld%lld%lld",&a,&b,&l);
	map<ll,ll> sample, at, bt ;
	factorization(l,sample) ;
	factorization(a,at) ;
	for(auto x : at){
		
		if(x.second> sample[x.first] ){
			
			puts("impossible") ;
			return ;
		}
	}
	factorization(b,bt) ;
	for(auto x : bt){
		
		if(x.second> sample[x.first] ){
			
			puts("impossible") ;
			return ;
		}
	}
	c = 1;
	for(auto value : sample){
		ll i = value.first ;
		if(value.second - max(at[i] , bt[i]))
			c *= (ll)pow(i,value.second) ;
	}
	printf("%lld\n",c ) ;
}

int main()
{
	int testcase ; scanf("%d",&testcase ) ;
	for(int i = 1 ; i <= testcase ; i++){
		printf("Case %d: ",i);
		solve() ;
	}
    return 0;
}
