                /*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
/*
    observation : We can find it using log Rule
    we know , Digit of N is = log10(N) + 1

    so , if we try to find digit of, N! = N * (N-1) *(N-2) .....1
    Also we know = log(x * y * Z ) = log(x) + log(y) + log(z)

    So the number of digit of N! will be = log(N) + log(N-1) + log(N-2) +....+log(1) + 1

    We also know another rule of log,
        log xY = log xZ * log zY
        so , log zY = log xZ / log xY

    So our answer is , ans = ( log xZ / log xY ) + 1


*/
const int nax = 1e6 + 10 ;
vector<double>  cum(nax+5);
void precom(){
    for(int i = 1 ; i < nax  ; i++){
        cum[i] = cum[i-1] + log(i) ;
    }
}
void solve(){
    int n , base ;
    scanf("%d%d",&n,&base);
    if(n==0 or n==1){
        puts("1");
        return ;
    }
    int ans = floor(cum[n]/log(base)) + 1;
    printf("%d\n",ans);

}
int main() {

    precom() ;
    int testcase ;
    scanf("%d",&testcase);

    for(int i = 1 ; i <= testcase ; i++){
        printf("Case %d: ",i);
        solve() ;
    }


    return 0 ;
}

