				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 99;
using ll = long long int ;
using pii = pair<int,int >;
using vec = vector<int> ;

vector<int> primelist ;
void sieve () {
	const int nax = 1e6 + 10 ;
	bool ok[nax] = {} ;
	primelist.emplace_back(2) ;
	for(int i = 3 ; i < nax-1 ; i+=2) {
		if(ok[i] == false ) {
			primelist.emplace_back(i) ;
			int add = i << 1;
			for(int j = i + add ; j < nax-1 ; j += add ) {
				ok[j] = true ;
			}
		}
	}
}

ll No_Of_Divisor(ll n){
	
	ll cnt = 1 , sqt = sqrt(n);
	
	for(int i=0; primelist[i]<=sqt; i++) {
		
                if(n%primelist[i] ==0){
		         ll temp = 1 ;
		          while( n%primelist[i] == 0 ){
			
			        n /= primelist[i] ;
			        temp ++ ;
			
		          }
                   sqt=sqrt(n);
	        	cnt *= temp ;
                }
	}
	
	if(n > 1 ) cnt *= 2 ;
	
	return cnt ;
	
	
}


void solve () {
	ll a , b ; scanf("%lld%lld",&a,&b) ;
	
	if( b * b >= a ){
		puts("0") ;
		return ;
	}
	
	ll cnt = No_Of_Divisor(a) ;
	cnt /= 2 ;
	
	for(int i=1; i<b; i++) if(a%i==0) cnt--;
	
	printf("%lld\n",cnt) ;
}

int main()
{
	sieve () ;
	
	int testcase ; scanf("%d",&testcase) ;
	for(int i = 1; i <= testcase ; i++ ){
		printf("Case %d: ",i) ;
		solve() ;
	}

    return 0;
}
