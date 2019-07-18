#include<bits/stdc++.h>
using namespace std;
const int nax = 510;
int dp[nax][nax];

int Grundy(int x, int y){
	if(x < 0 or y < 0)
		return -1;
	if(x==0 && y==0)
		return 0;
	
	int &ret = dp[x][y];
	if(~ret)
		return ret;
		
	set<int> s;
	
	s.insert(Grundy(x+1,y-2));
	s.insert(Grundy(x-1,y-2));
	s.insert(Grundy(x-1,y-3));
	s.insert(Grundy(x-2,y-1));
	s.insert(Grundy(x-3,y-1));
	s.insert(Grundy(x-2,y+1));
	
	ret = 0;
	while(s.count(ret)) 
		ret ++;
	
	return ret;
}

void solve(int cn){
	
	int n ;
	scanf("%d",&n);
	long long int Xor = 0;
	for(int i = 0; i< n; i++){
		int x, y;
		scanf("%d%d",&x,&y);
		Xor ^= Grundy(x,y);
	}
	printf("Case %d: %s\n",cn,Xor?"Alice":"Bob");
	
}

int main(){
	
	memset(dp,-1, sizeof dp);
	
	int t, cn = 0;
	scanf("%d",&t);
	while(t--)
		solve(++cn);
	
	return 0;
}
