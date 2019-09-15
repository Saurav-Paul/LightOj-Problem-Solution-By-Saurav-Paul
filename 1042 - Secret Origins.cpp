				/*Saurav Paul*/
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

void solve_using_bit(int n){
	bitset<32>bit(n);
	string s = bit.to_string();
	reverse(s.begin(),s.end()) ;
	int one = 0;
	for(int i = 0 ; i < (int)s.size()-1 ; i++){
		if( s[i+1] == '0' and s[i] =='1' ){
			swap(s[i],s[i+1]);
			for(int x = 0 ; x < i ; x++){
				if(one){
					one --;
					s[x]='1';
				}
				else s[x] = '0';
			}
			break ;
		}
		else if(s[i]=='1') one ++;
	}
	long long int ans = 0;
	for(int base = 0 ; base <(int) s.size() ; base ++){
		if(s[base]=='1')	ans += pow(2,base);
	}
	printf("%lld\n",ans);
	
}
void solve(){
	int n;
	scanf("%d",&n);
	solve_using_bit(n);
}
int main()
{
	int t; scanf("%d",&t);
	for(int i = 1 ; i <= t ; i++){
		printf("Case %d: ",i);
		solve();
	}
    return 0;
}
