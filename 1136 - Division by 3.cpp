				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

inline int f(int b){
	return b - (b/3) - (b%3==1 or b%3== 2);
}
void solve(){
	int a , b;
	scanf("%d%d",&a,&b);
	
	int x = f(a-1);
	int y = f(b);

	printf("%d\n",y-x);
}
int main()
{
	int t; scanf("%d",&t);
	for(int i = 1; i <= t ; i++){
		printf("Case %d: ",i);
		solve();
	}
    return 0;
}
