#include<bits/stdc++.h>
using namespace std;

void solve(int caseno){
	int n;
	scanf("%d",&n);
	long long int  Xor = 0;
	for(int i = 0 ; i< n; i++){
		int a, b;
		scanf("%d%d",&a,&b);
		Xor ^= abs(b-a)-1;
	}
	printf("Case %d: ",caseno);
	
	if(Xor)
		puts("Alice");
	else
		puts("Bob");
}

int main(){
	int t, caseno = 0;
	scanf("%d",&t);
	while(t--)
		solve(++caseno);
		
	return 0;
}
