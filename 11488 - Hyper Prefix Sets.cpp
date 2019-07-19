#include<bits/stdc++.h>
using namespace std;
int mx = 0;
class node{
	
	public :
		int cnt;
		node *next[2];
	node(){
		cnt = 0;
		for(int i= 0 ;i < 2 ; i++)
			next[i] = NULL;
	}
} *root;

void insert(string &s){
	
	int sz = (int)s.size();
	node * curr  = root;
	for(int i=0 ; i < sz ; i++){
		int id = (int) s[i]-'0';
		if(curr->next[id]==NULL)
			curr->next[id] = new node();
		curr->next[id]->cnt += 1;
		int temp = curr->next[id]->cnt *(i+1);
		if(temp > mx)
			mx = temp;
		curr = curr->next[id];
	}
	
	
}

void solve(){

	mx = 0;
	int n ; cin >> n;
	string s;
	root = new node();
	
	for(int i = 0 ; i < n; i++){
		cin >> s;
		insert(s);
	}
	
	cout << mx << "\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	
	int t ;
	cin >> t;
	while(t--)
		solve();
		
	return 0;
}
