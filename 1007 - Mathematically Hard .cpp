				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int nax = 5e6  + 10 ;;
bool mark[nax];
vector<unsigned long long int > phi(nax+20);

void sieve_phi(int n) {
	for(int i = 1 ; i<= n; i++) phi[i] = i;
	mark[1] = true ;
	
	for(int i = 2 ; i <= n; i+= 2){
		if(i != 2 ) mark[i] = 1;
		phi[i] = phi[i] /  2 ;
	}
	
	for(int i = 3; i <= n; i+= 2){
		if(mark[i] == false ){
			phi[i] = phi[i] - 1;
				
			for(int j =( i << 1) ; j <= n ; j+= i){
				mark[j] = true ;
				phi[j] = phi[j] / i * (i-1)  ;
			}
		}
	}
}


void precom(){
	for(int i = 1 ; i <= 5000000 + 5 ; i++){
		phi[i] = phi[i-1] + ((unsigned long long )phi[i] * phi[i] ) ;
	}
}
void solve(int cn ){
	int a , b;
	scanf("%d%d",&a,&b);
	
	unsigned long long int ans = phi[b] - phi[a-1] ;
	printf("Case %d: %llu\n",cn,ans);
	
}
int main()
{
	int n = 5e6+5;
	sieve_phi(n) ;
	precom();
	
	int t ;
	scanf("%d",&t);
	
	for(int i = 1 ; i <= t ; i++){
		solve(i);
	}

    return 0;
}
