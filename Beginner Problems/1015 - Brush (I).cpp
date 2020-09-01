				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n; scanf("%d",&n);
	int total = 0;
	for(int i = 0 ; i < n ; i++){
		int a ; scanf("%d",&a);
		total += (a > 0 ? a : 0 );
	}
	printf("%d\n",total);
}
int main()
{
	int t; scanf("%d",&t);
	for(int i = 1 ; i <= t ; i++){
		printf("Case %d: ",i);
		solve();
	}

    return 0;
}
