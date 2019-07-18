#include<bits/stdc++.h>
using namespace std;

int Grundy(int n){
	if(n==0 or n==1)
		return 0;
	
	return n&1?Grundy(n/2):n/2;
	
}

void solve(int cn){
	
	int n; 
	scanf("%d",&n);
	long long int Xor = 0;
	for(int i=0 ; i < n; i++){
		int temp ;
		scanf("%d",&temp);
		
		Xor ^= Grundy(temp);
	}
	printf("Case %d: ",cn);
	puts(Xor?"Alice":"Bob");
	
}

int main(){
	
	int t , cn = 0;
	
	scanf("%d",&t);
	while(t--)
		solve(++cn);
	
	return 0;
}
