				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &v , int value){
	int low = 0 , high =(int) v.size() ;
	while(low < high){
		int mid = low + ( (high-low) >> 1 ) ;
		if(v[mid] < value )
			low = mid +1 ;
		else
			high = mid ;
	}
	return low;
}

void solve(){
	int n ;
	scanf("%d",&n);
	vector<int> v(n);
	
	for(int &x : v)
		scanf("%d",&x);
	
	sort(v.begin(),v.end());
	long long cnt = 0 ;

	for(int i = 0 ; i < n; i++){
		for(int j = i+1 ; j < n; j++){
			int sum = v[i] + v[j];
			int ind = lowerbound(v,sum) ;
			if(ind >= n or v[ind] >= sum ) ind --;
			cnt += (ind-j) ;
		}
	}
	printf("%lld\n",cnt);
}
int main()
{
	int testcase; scanf("%d", &testcase);
	
	for(int i = 1; i <= testcase ; i++){
		printf("Case %d: ",i);
		solve();
	}

    return 0;
}
