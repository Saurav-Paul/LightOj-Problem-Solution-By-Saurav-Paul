#include<bits/stdc++.h>
using namespace std;
const int nax = 125 + 1;
vector< vector<int> > precom(nax, vector<int> (nax)) ;
vector<int> primelist;

void sieve(){
    bool notprime[nax+5] ;
    memset(notprime , 0 , sizeof(notprime)) ;
    primelist.emplace_back(2);
    for(int i = 3 ; i < nax ; i+= 2){
        if(notprime[i] == false){
            primelist.emplace_back(i);
            int add = i << 1;
            for(int j = i + add ; j < nax ; j += add){
                notprime[i] = true ;
            }
        }
    }

}

void factorization(int n){
    int node = n ;

    for(auto x : primelist){
        if(x*x > n) break ;
        while(n%x == 0){
            precom[node][x] ++;
            n /= x;
        }
    }
    if(n > 1)
        precom[node][n] ++;
}

void pre_com(){
    for(int i = 2 ; i < nax ; i++){
        precom[i] = precom[i-1] ;
        factorization(i) ;
    }

}
void solve(){
    int n ;
    scanf("%d",&n) ;
    printf("%d =",n);
    bool ok = true ;
    for(int i = 2 ; i < nax ; i++){
        if(precom[n][i] > 0){
            if(ok){
                printf(" %d (%d)",i,precom[n][i]);
                ok = false ;
            }
            else
                printf(" * %d (%d)",i,precom[n][i]);
        }
    }
    puts("");
}
int main() {


    sieve();
    pre_com() ;

    int testcase ;
    scanf("%d",&testcase);

    for(int i = 1 ; i <= testcase ; i++){
        printf("Case %d: ",i);
        solve() ;
    }



    return 0 ;
}
/*
Inputs :
3

2

3

6


Output :
Case 1: 2 = 2 (1)

Case 2: 3 = 2 (1) * 3 (1)

Case 3: 6 = 2 (4) * 3 (2) * 5 (1)
*/
