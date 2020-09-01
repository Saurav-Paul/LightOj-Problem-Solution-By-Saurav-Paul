#include<bits/stdc++.h>
using namespace std;

void solve(int caseno){
	int n;
	scanf("%d",&n);
	vector <int > v(n);
	for(int &x : v)
		scanf("%d",&x);
	int cnt = 0;
	for(int i = 0 ; i < n-1 ; i++){
		int index = -1 ; int mini = v[i];
		for(int j = i + 1; j < n ; j++){
			if(v[j]< mini){
				mini = v[j];
				index = j;
			}
		}
		if(index != -1)
			swap(v[i],v[index]),cnt++;
		
	}
	printf("Case %d: %d\n",caseno,cnt);
}

int main(){
	int n , caseno = 0;
	scanf("%d",&n);
	while(n--)
		solve(++caseno);
		
	return 0;
}
