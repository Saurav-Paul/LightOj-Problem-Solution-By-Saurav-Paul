				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 90 ;
vector<double> harmonic_1000(nax) ;

inline double harmonic(int i ){
	return 1.0/i ;
}

void pre_cum() {
	double past = 0.0 , now = 0.0 ;
	int lim = 1e8 + 5;
	for(int i = 1,x=1 ; i < lim; i++) {
		now = past + harmonic(i) ;
		
		if(i%1000 == 0 ){
			harmonic_1000[x] = now ;
			x++;
		}
		past = now ;
	}
	
	
}
void solve() {
	int n ; scanf("%d",&n) ;
	int x = n/1000;
	double have = harmonic_1000[x] ;
	for(int i = n - n%1000 + 1;  i <= n; i++){
		have += harmonic(i) ;
	}
	printf("%.12g\n",have) ;
}
int main()
{
	
	pre_cum () ;
	int testcase ; scanf("%d",&testcase ) ;
	for(int i= 1 ; i <= testcase ; i++){
		printf("Case %d: ",i);
		solve() ;
	}

    return 0;
}
