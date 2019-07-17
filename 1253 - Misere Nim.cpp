#include<bits/stdc++.h>
using namespace std;

void solve(int caseno){
	int n; scanf("%d",&n);
	bool flag = false;
	long long int Xor = 0;
	for(int i= 0 ; i < n; i++){
		int temp ;
		scanf("%d",&temp);
		Xor ^= temp;
		flag = (temp!=1 or flag) ;
	}
	printf("Case %d: ",caseno);
	if(!flag)
		puts(n&1 ? "Bob" : "Alice");
	else
		puts(Xor ? "Alice" : "Bob");
	
	return ;
}

int main(){
	
	int t, cn = 0;
	scanf("%d",&t);
	while(t--)
		solve(++cn);
	
	return 0;
}
