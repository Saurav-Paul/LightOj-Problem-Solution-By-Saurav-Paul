				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;
using vec = vector<int> ;

vector< vec > dp(11, vec(11) ) ;

ll find_ans(vector<int> &v, int x,int curr, int n){
	if(curr == n){
		return 1;
	}
	if(dp[curr][x] != -1 )
		return dp[curr][x];
	ll ans = 0;
	for(auto y : v){
		if(curr == 0 or abs(x-y) <= 2)
			ans += find_ans(v,y,curr+1,n);
	}
	return dp[curr][x] = ans ; 
}

void solve(){
	int m , n;
	scanf("%d%d",&m,&n);
	vector<int> v(m);
	
	for(int i = 0 ; i < 11 ; i++)
		for(int j = 0 ; j < 11 ; j++ )
			dp[i][j] = -1;
	
	for(int i = 0 ; i < m ; i++) scanf("%d",&v[i]);
	
	long long int cnt = find_ans(v,0,0,n);
	printf("%lld\n",cnt);
}

int main()
{
	int t; scanf("%d",&t);
	for(int i = 1 ; i <= t ; i++)
		printf("Case %d: ",i),solve();

    return 0;
}
