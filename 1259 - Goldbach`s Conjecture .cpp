				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
const int nax = 1e7 + 5;
bool isprime[nax+5] ;
vector<int> primelist ;
void precom(){
	primelist.emplace_back(2) ;
	
	for(int i = 4 ; i < nax ; i += 2) isprime[i] = true ;
	for(int i =3 ; i < nax ; i+= 2 ){
		if(isprime[i] == false ){
			primelist.emplace_back(i) ;
			int ad = (i << 1 ) ;
			for(int j = ad + i ; j < nax ; j += ad ){
				isprime[j] = true; 
			}
		}
	}
	
} 

void solve(int cn) {
	int n ;
	scanf("%d",&n);
	
	int cnt = 0;
	int lim = n/2 ;
	for(int i : primelist){
		if(i > lim ) break ;
		if(isprime[i]==false && isprime[n-i] == false ){
			cnt ++ ;
		}
	}
	printf("Case %d: %d\n",cn,cnt);
}

int main()
{
	precom() ;
	int t ; 
	scanf("%d",&t);
	for(int i = 1; i <= t ; i ++){
		solve(i) ;
	}
    return 0;
}
