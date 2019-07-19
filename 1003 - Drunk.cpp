#include<bits/stdc++.h>
using namespace std;
const int nax = 1e4 + 10;
vector <int > v[nax];
bool isvisited[nax];
bool flag ;

void dfs(int i , bool rem[]){
	if(rem[i]){
		flag = false;
	}
	if(flag == false)
		return ;
	rem[i] = true;
	for(auto x : v[i]){
		dfs(x,rem);
	}
	rem[i] = false;
}

void solve(int cn){
	
	memset(isvisited,0,sizeof isvisited);
	int n; 
	cin >> n;
	
	for(int i = 0 ; i < nax ; i++)
		v[i].clear();
	
	map <string,  int > mymap;
	int assign = 0 ;
	for(int i = 0 ; i < n; i++){
		string s,t;
		cin >> s >> t;
		if(mymap.find(s)==mymap.end()){
			mymap[s] = assign++;
		}
		if(mymap.find(t) == mymap.end()){
			mymap[t] = assign++;
		}
		v[mymap[s]].emplace_back(mymap[t]);
		
	}
	flag = true;
	
	bool rem[assign + 10];
	memset(rem, 0 , sizeof rem);
	for(int i = 0 ; i< assign && flag; i++){
		dfs(i,rem);
	}
	
	cout << "Case "<<cn<<": "<<(flag?"Yes":"No")<<"\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	int t , cn = 0;
	cin >> t;
	while(t--)
		solve(++cn);
		
	return 0;
}
