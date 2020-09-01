				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

const int nax = 1e4 + 10 ;
vector<int> primelist ;

string addStringModified (string a, string b){
	reverse(a.begin(),a.end());
	int l1 = a.size() , l2 = b.size();
	if(l1 > l2){
		swap(a,b);
		swap(l1,l2);
	}
	string ans ="";

	bool carry = false;
	
	for(int i = 0 ;i < l1 ; i++){
		int temp = (a[i]-'0') + (b[i]-'0') + (carry);
		carry = false;
		if(temp > 9){
			carry = true;
			temp = temp-10;
		}
		ans += (temp+'0');
	}
	for(int i = l1 ; i < l2 ; i++){
		int temp = (b[i]-'0') + (carry);
		carry = false;
		if(temp > 9){
			carry = true;
			temp = temp-10;
		}
		ans += (temp+'0');
	}
	if(carry) ans += '1';
	reverse(ans.begin(),ans.end());
	
	return ans;
}

string multiplication(string s, ll n ){
	
	reverse(s.begin() , s.end() ) ;
	vector<string> temporary ;

	int koy_number = 0 ;
	while( n!= 0 ){
		int num = n%10 ;
		n /= 10 ;
		
		int carry = 0 ;
		
		string temp = "";
		for(auto x : s ) {
			int y = carry + (x - '0' ) * num;
			carry = 0;
			if( y > 9 ){
				carry = y / 10 ;
				y %= 10;
			}
			
			temp += char( y + '0' ) ;
		}
		if(carry) temp += char(carry + '0' ) ;
		
		string zero = "";
		for(int i = 0 ; i < koy_number ; i++) {
			zero += '0' ;
		}
		temp = zero + temp ;
		temporary.emplace_back(temp) ;
		koy_number ++;
		
	}
	
	s = "0";
	
	for(auto x : temporary ){
		s = addStringModified(s , x ) ;
	}
	
	return s ; 
}

void sieve(int n) {
	bool rem[n+10] ;
	memset(rem , 0 , sizeof(rem) ) ;
	primelist.emplace_back(2);
	for(int i = 3 ; i < n ; i++){
		if(rem[i] == false) {
			primelist.emplace_back(i) ;
			int add = i << 1;
			for(int x = add + i ; x < n ; x += add){
				rem[x] = true ;
			}
		}
	}

}
	

void factorization(vector<int> &cnt , int n ) {

	vector< pair<int, int > > v;
	for(auto x : primelist ) {
		if(x * x > n ) break ;
		int temp = 0 ;
		while( n%x == 0){
			temp ++;
			n /= x ;
		}
		if(temp){
			v.emplace_back(make_pair(x , temp ) );
		}
	}
	if(n > 1){
		v.emplace_back(make_pair(n,1) ) ;
	}
	
	for(auto x : v){
		cnt[x.first] = max(x.second , cnt[x.first] ) ;
	}

}

void solve() {
	string multi = "1";
	int n ; scanf("%d",&n) ;


	vector<int> cnt(nax+5) ;
	vector<int> v(n) , newv;
	for(int &x : v){
		scanf("%d",&x) ;
		factorization(cnt,x) ;	
	}
	
	for(int i = 1 ; i < nax ; i++){
		if(cnt[i] == 0) continue ;
		ll x = pow(i,cnt[i]) ;
		multi = multiplication(multi,x) ;
	}
	cout << multi << endl ;
}

int main()
{
	sieve(nax + 10 ) ;
	int testcase; scanf("%d",&testcase ) ;
	for(int i = 1 ; i <= testcase ; i++){
		printf("Case %d: ",i);
		solve() ;
	}

    return 0;
}
