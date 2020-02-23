				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

void solve() {

    int n ; cin >> n;
    vector<int> a(n) , b(n) ;
    for(auto &x : a){
        cin >> x;
    }
    for(auto &x : b){
        cin >> x ;
    }
    int win = 0 , draw = 0 ;
    sort(a.begin(),a.end()) ;
    sort(b.begin(),b.end()) ;
    bool ra[n+1] ={}  , rb[n+1]={} ;
    for(int i = 0; i < n ; ++i ){
       int x = a[i] ;
       for(int j = n-1 ; j >= 0 ; j--){
           if(x > b[j] &&  rb[j]==false){
               win ++ ;
               ra[i] = true ;
               rb[j] = true ;
               break ;
           }
       } 
    }
    for(int i = 0 ; i < n ; i++){
        if(ra[i]==false){
            for(int j = 0 ; j < n ; j++){
                if(rb[j]==false && a[i]==b[j]){
                    draw ++ ;
                    ra[i] = rb[j] = true ;
                    break ;
                }
            }
        }
    }

    long long ans = win * 2 + draw ;
    cout << ans << endl ;
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int testcase;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++){
        cout << "Case "<<t<<": ";
        solve();
    }

    return 0;
}
