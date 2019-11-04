				/*Saurav Paul*/
#include<bits/stdc++.h>
#define boost		          ios_base::sync_with_stdio(0);
using namespace std;

void solve () {
	string s; cin >> s;
	bool ok = true ;
	for(int x = 0 , y = s.size() -1 ; x < y ; x++ , y--){
		if(s[x] != s[y]){
			ok = false ;
			break ;
		}
		
	}
	puts(ok?"Yes":"No") ;
}

int main()
{
	boost ;
	int testcase ; cin >> testcase ;
	for(int i =1 ;i <= testcase ; i++ ){
		printf("Case %d: ",i) ;
		solve() ;
	}
    return 0;
}
