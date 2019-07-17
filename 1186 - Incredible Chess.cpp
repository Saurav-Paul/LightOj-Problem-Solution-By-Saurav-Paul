#include<bits/stdc++.h>
using namespace std;

void solve(int caseno){
	
	int n ; scanf("%d",&n);
	vector <int > v (n);
	for(int &x : v)
		scanf("%d",&x);
	int Xor = 0;
	for(int i = 0 ; i < n; i++){
		
		int temp  ;
		scanf("%d",&temp);
		temp -= v[i] + 1;
		Xor ^= temp;
		
	}
	printf("Case %d: ",caseno);
	if(!Xor)
		puts("black wins");
	else
		puts("white wins");
	
}

int main(){
	int t , caseno = 0;
	scanf("%d",&t);
	while(t--)
		solve(++caseno);
	
	
	return 0;
}
