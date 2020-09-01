#include<bits/stdc++.h>
using namespace std;
void solve() {

  int n , t ;
  cin >> n >> t;
  vector<int> v(100) ;
  int l , r;
  l = 50 , r = 51 ;
  int cnt = 0 ;
  while(t--){
    string s ; cin >> s;
    if(s[1]=='o'){
      if(cnt==0){
        cout << "The queue is empty" << endl ;
      }
      else{
        if(s[3]=='L'){
          cout << "Popped from left: "<< v[++l] << endl ;
        }
        else{
          cout << "Popped from right: " << v[--r] << endl ;
        }
        --cnt ;
      }
    }
    else{
      int x ; cin >> x;
      if(cnt==n){
        cout << "The queue is full" << endl ;
        continue ;
      }
      if(s[4]=='L'){
        cout <<"Pushed in left: "<< x << endl ;
        v[l--] = x;
      }
      else{
        cout << "Pushed in right: " << x << endl ;
        v[r++] = x;
      }
      cnt ++ ;
    }
  }
}
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int testcase;
  cin >> testcase;
  for (int t = 1; t <= testcase; t++){
    cout << "Case "<< t <<":\n"; 
    solve();
  }
  
  
  return 0 ;
}
