				/*Saurav Paul*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	while(n)
		cnt += (n&1) , n>>=1;
	puts(cnt&1?"odd":"even");
}
int main()
{
	int t; scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		printf("Case %d: ",i);
		solve();
	}
	
    return 0;
}
