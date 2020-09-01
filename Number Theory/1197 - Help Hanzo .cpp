				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;
vector<int> primelist ;

void sieve() {
	
	const int nax = 1e6 ;
	bool notprime[nax+5] ;
	memset(notprime , 0 , sizeof notprime ) ;
	
	primelist.emplace_back(2) ;
	for(int i =3 ; i <= nax ; i+= 2){
		if(notprime[i] == false){
			primelist.emplace_back(i) ;
			int add = i << 1;
			for(int j = i + add ; j <= nax ; j+= add ){
				notprime[j] = true ;
			}
		}
	}
	
}

void solve() {
	
	int a , b ;
	scanf("%d%d",&a,&b) ;
	const int nax = 1e6 + 90 ;
	bool notprime[nax] = {} ;
	if(a <= 1 ) notprime[0] = true ;
	int cnt = 0;
	for(int x : primelist){
		if( x > b ) break ;
		ll div = (int)ceil((double)a/x) ;
		ll st = x * div ;
		if(st == x ) cnt ++;
		for(ll i = st-a,lim = b-a; i <= lim ; i+=x){
			notprime[i] = true;
		}
		
	}

	for(int i = 0 , lim = b-a; i <= lim ; i ++){
		if(notprime[i] == false )
			cnt ++;
	}
	printf("%d\n",cnt ) ;
}

int main()
{
	sieve() ;
	int testcase ; scanf("%d",&testcase) ;
	for(int i = 1 ; i <= testcase ; i++){
		printf("Case %d: ",i) ;
		solve() ;
	}

    return 0;
}
