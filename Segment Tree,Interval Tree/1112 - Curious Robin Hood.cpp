#include<bits/stdc++.h>
using namespace std;
using vec = vector <int> ;

int query_tree(vec & tree, int l , int r){
	int sum = 0;
	while(l < r){
		if(l&1)
			sum += tree[l++];
		if(r&1)
			sum += tree[--r];
		
		l >>=1 , r >>=1;
	}
	return sum;
}

void update_tree(vec &tree, int index, int value,bool add){
	
	if(add==false)
		printf("%d\n",tree[index]);
	tree[index] = add ? tree[index] + value : 0;
	while(index > 1){
		tree[index>>1] = tree[index] + tree[index^1];
		index >>=1;
	}
	
	
}

void solve(int caseno){
	int n, q;
	scanf("%d%d",&n,&q);
	vec tree(2*n);
	for(int i = 0 ; i < n; i++)
		scanf("%d",&tree[n+i]);
		
	for(int i = n- 1; i > 0 ; i--)
		tree[i] = tree[i<<1] + tree[i<<1|1];
	printf("Case %d:\n",caseno);
	while(q--){
		int op; scanf("%d",&op);
		switch(op){
			case 1 :
				int indx; scanf("%d",&indx);
				update_tree(tree,indx+n,0,false);
				break;
			case 2 :
				int index,value ; scanf("%d%d",&index,&value);
				update_tree(tree,index+n,value,true);
				break;
			case 3 :
				int l , r; scanf("%d%d",&l,&r);
				int ans = query_tree(tree,l+n,r+n+1);
				printf("%d\n",ans);
				break ;
			
		}
	}
}

int main(){
	
	int testcase,caseno= 0;
	scanf("%d",&testcase);
	while(testcase--)
		solve(++caseno);
		
	return 0;
}
