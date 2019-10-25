				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;

void solve() {
	ll ax , bx , ay , by;
	scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
	ll ans = gcd(abs(ax-bx) , abs(ay-by) ) + 1;
		
	printf("%lld\n",ans ) ;
	
	
}

int main()
{
	int testcase ; scanf("%d",&testcase) ;
	for(int  t= 1 ; t <= testcase ; t++){
		printf("Case %d: ",t);
		solve() ;
	}

    return 0;
}
