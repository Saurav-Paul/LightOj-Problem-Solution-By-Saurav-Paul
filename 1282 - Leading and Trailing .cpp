				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;


ll bigMod(ll num,ll power ,ll mod ){
	if(power == 0 ) 
		return 1 ;
	
	ll res= 1;
	if(power & 1 ){
		res = num ;
	}
	ll x = bigMod(num , power/2 , mod )%mod ;
	x = (x%mod * x%mod)%mod ;
	return ( (res%mod) * (x%mod) )%mod ;
	
}


ll first_three_finder(ll n , ll power ){
	double x = power * log10(n) ;
	ll ans = pow(10,x-(long long int)x) *100 ;
	return ans ;
}

void solve() {
	ll n , k ;
	scanf("%lld%lld",&n,&k) ;
	ll last_three = bigMod(n,k,1000) ;
	ll first_three = first_three_finder(n,k) ;
	printf("%.3lld %.3lld\n",first_three,last_three) ;
}

int main()
{
	int testcase ; scanf("%d",&testcase) ;
	for(int i = 1 ; i <= testcase ; i++ ){
		printf("Case %d: ",i) ;
		solve() ;
	}
    return 0;
}
