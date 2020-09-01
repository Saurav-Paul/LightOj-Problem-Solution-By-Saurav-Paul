#include<bits/stdc++.h>
using namespace std;
const int nax =  1e6 + 5;
char s[nax],pattern[nax];

void build_suffix_array(vector <int > &suffix,int n){
	/**
	 abcabcd
	 0001230
	 
	 abcabca
	 0001231
	 
	 **/
	
	for(int i = 0 , j = 1 ; j < n; ){
		if(pattern[i] == pattern[j]){
			suffix[j] = i + 1;
			i++ , j++;
		}
		else{
			if(i)
				i = suffix[i-1];
			else{
				suffix[j] = 0;
				j++;
			}
		}
	}
	
	
}

int find_text(vector <int > &suffix , int lens, int lenp){
	int cnt = 0;
	
	for(int i = 0 ,  j = 0 ; j < lens ; ){
		if(s[j] == pattern[i]){
			i++, j++;
			if( i == lenp){
				cnt ++;
				if(i)
					i = suffix[i-1];
			}
		}
		else{
			if(i)
				i = suffix[i-1];
			else{
				j++;
			}
		}
		
		
	}
	
	
	return cnt ;
}

void solve(int caseno){
	
	scanf("%s %s",s,pattern);
	int lens = (int) strlen(s), lenp = (int)strlen(pattern);
	vector <int > suffix(lenp);
	build_suffix_array(suffix,lenp);
	int cnt = find_text(suffix,lens,lenp);
	printf("Case %d: %d\n",caseno,cnt);
	
}


int main(){
	int testCase;
	scanf("%d",&testCase);
	int caseno = 1;
	while(testCase--)
		solve(caseno++);
	
	return 0;
}
