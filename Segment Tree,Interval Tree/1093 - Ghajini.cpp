				/*Saurav Paul*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

class obj{
	public :
		int mini,maxi;
	obj(){
		mini = 1e9+90 , maxi = 0;
	}
	void operator = (const int x){
		mini = maxi = x;
	}
	obj operator ^ (const obj x){
		obj temp;
		temp.mini = min(mini,x.mini);
		temp.maxi = max(maxi,x.maxi);
		return temp;
	}
};

inline int getMid(int st , int sp){
	return st + ((sp-st) >> 1);
}

using vec = vector<obj> ;
void build_tree(vec &tree,vector<int> &v,int st , int sp , int node){
	if(st==sp){
		tree[node] = v[st];
		return ;
	}
	int mid = getMid(st,sp);
	int lft = node << 1 ;
	int rght = lft + 1;
	build_tree(tree,v,st,mid,lft);
	build_tree(tree,v,mid+1,sp,rght);
	tree[node] = tree[lft] ^ tree[rght];
}

void query_tree(vec &tree,int l , int r , int st , int sp , int node,obj &temp){
	if(st > r or sp < l)
		return ;
	if(st >= l and sp <= r){
		temp = temp ^ tree[node];
		return ;
	}
	int mid = getMid(st,sp);
	int lft = node << 1;
	int rght = lft + 1;
	query_tree(tree,l,r,st,mid,lft,temp);
	query_tree(tree,l,r,mid+1,sp,rght,temp);
}

void solve(int caseno){
	int n , d;
	scanf("%d%d",&n,&d);
	vector <int > v(n);
	for(int i = 0 ; i < n; i++)
		scanf("%d",&v[i]);
	vec tree(4*n);
	build_tree(tree,v,0,n-1,1);

	int maxDiff = 0;
	for(int i = 0 ; i < n-d ; i++){
		obj temp ;
		query_tree(tree,i,i+d-1,0,n-1,1,temp);
		maxDiff=max(maxDiff,temp.maxi-temp.mini);
	}
	
	printf("Case %d: %d\n",caseno,maxDiff);
}

int main()
{
	int testcase ,caseno = 0;
	scanf("%d",&testcase);
	while(testcase--)
		solve(++caseno);

	
    return 0;
}
