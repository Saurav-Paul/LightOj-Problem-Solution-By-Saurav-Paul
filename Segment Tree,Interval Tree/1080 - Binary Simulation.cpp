#include<bits/stdc++.h>
using namespace std;
using vec = vector<pair<int,char> >;
const int nax = 1e5+10;
char s[nax];

void build_tree(vec &tree, int st , int sp , int node){
	if(st == sp){
		tree[node].second = s[st];
		
		return ;
	}
	int mid = st + ((sp-st) >> 1);
	int lft = (node << 1);
	int rght = lft + 1;
	build_tree(tree,st,mid,lft);
	build_tree(tree,mid+1,sp,rght);
	
}


void lazy_update_tree(vec &tree,int l , int r , int st , int sp , int node){
	if(sp < l || st > r)
		return ;
	if(st >= l && sp <=r){
		tree[node].first ^=1;
		return ;
	}
	int mid = st + ((sp-st)>> 1);
	int lft = (node << 1);
	int rght = lft + 1;
	lazy_update_tree(tree,l,r,st,mid , lft);
	lazy_update_tree(tree,l,r,mid+1,sp,rght);
	
}

int query_tree(vec &tree, int indx, int st , int sp , int node,bool flag){
	
	if(tree[node].first)
		flag ^=1;
	if(sp < indx || st > indx)
		return -1;
	if(sp==indx && sp==st){
		int ans = tree[node].second - '0';
		return ans^(flag);
	}
	int mid = st + ((sp-st) >> 1);
	int lft =  (node << 1) ;
	int rght = lft + 1;
	int t1 = query_tree(tree,indx,st,mid,lft,flag);
	int t2 = query_tree(tree,indx,mid+1,sp,rght,flag);
	
	return max(t1,t2);
	
}

void solve(int caseno){
	
	scanf("%s",s);
	int n= (int)strlen(s);
	vec tree(4*n);
	build_tree(tree,0,n-1,1);
	
	int q; scanf("%d ",&q);
	printf("Case %d:\n",caseno);
	while(q--){
		char c;
		int l , r , inx , situation;
		scanf("%c",&c);
		
		switch(c){
			
			case 'I' :
				scanf("%d%d ",&l,&r);
				lazy_update_tree(tree,l-1,r-1,0,n-1,1);
				break ;
			case 'Q' :
				scanf("%d ",&inx);
				situation = query_tree(tree,inx-1,0,n-1,1,false);
				printf("%d\n",situation);
				break ;
			
		}
		
		
		
	}
}

int main(){
	int testcase = 0 , caseno = 0;
	scanf("%d",&testcase);
	while(testcase--)
		solve(++caseno);
		
	return 0;
}
