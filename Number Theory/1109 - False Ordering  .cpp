				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int nax = 1e3 ;
vector< pair<int,int > > store;

bool comp( pair<int,int> &a , pair<int,int> &b ){
	if(a.second == b.second)
		return a.first > b.first ;
	return a.second < b.second ;
}

void precom () {
	vector<int > cnt(1001) ;
	for(int i = 1 ; i <= 1000 ; i++){
		for(int j = i ; j <= 1000 ; j+= i){
			cnt[j] ++ ;
		}
	}
	for(int i = 1 ; i <= 1000 ; i++){
		store.emplace_back(i,cnt[i]);
	}
	sort(store.begin() , store.end() , comp );
}
void solve(int cn) {
	
	int n ;
	scanf("%d",&n);
	printf("Case %d: %d\n",cn,store[n-1].first);
	
}

int main()
{
	precom() ;
	int t ;
	scanf("%d",&t);
	for(int i = 1; i <= t ; i++){
		solve(i) ;
	}
	
    return 0;
}
