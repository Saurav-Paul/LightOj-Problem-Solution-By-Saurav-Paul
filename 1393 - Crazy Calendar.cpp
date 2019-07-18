#include<bits/stdc++.h>
using namespace std;

inline int need(int i , int j , int n, int m){
	
	return (n-i)+(m-j);
	
}

void solve(int caseno){
	int n, m;
	scanf("%d%d",&n,&m);
	long long int Xor = 0;
	int temp ;
	for(int i =1  ; i <= n; i++){
		for(int j = 1; j <= m ; j++){
			scanf("%d",&temp);
			
			if(need(i,j,n,m)&1)
				Xor ^= temp;
		}
	}
	printf("Case %d: ",caseno);
	if(Xor)
		puts("win");
	else
		puts("lose");
	
}

int main(){
	int t , cn= 0;
	scanf("%d",&t);
	while(t--)
		solve(++cn);
	return 0;
}
