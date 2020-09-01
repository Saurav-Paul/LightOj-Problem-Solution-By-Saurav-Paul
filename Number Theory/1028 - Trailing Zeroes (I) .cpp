				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std ;
const int nax = 1e6+ 90;
vector<int> primelist ;
using ll = long long int ;
bool notprime[nax] ;

void sieve() {

    primelist.emplace_back(2);
    for(int i = 3 ; i < nax ; i+=2){
        if(notprime[i]==false){
            primelist.emplace_back(i) ;
            int add = i << 1;
            for(int j = add + i ; j < nax ; j+= add){
                notprime[j] = true ;
            }
        }
    }

}

long long num_of_divisor(long long n){

    long long cnt = 1;
    for(auto x : primelist){
        if(x*x > n)
            break ;

        long long temp = 1;
        while(n%x==0){
            temp ++;
            n/= x ;
        }
        cnt *= temp;
    }
    if(n > 1) cnt *= 2;
    return cnt ;
}
void solve() {
    ll n ;
    scanf("%lld",&n);
    ll ans = num_of_divisor(n) -1 ;
    printf("%lld\n",ans);

}

int main()
{
    int t;
    sieve() ;

    scanf("%d",&t);
    for(int i = 1 ; i <= t; i++){
        printf("Case %d: ",i);
        solve() ;
    }
    return 0;
}
