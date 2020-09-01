
/**
 *    author        : Saurav Paul 
 *    created       : August 19, 2020 12:15 AM
 *    Problem Name  : 1185 - Escape
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1185
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{
  public :

    static const int nax = 111 ;
    int N , M ;
    vector<int> graph[nax+1] ;
    bool dp[nax+1][2] = {};

    void dfs(int node, int col){
        if(col != -1) dp[node][col] = true ;

        col = (col == 1? 2 : 1) ;

        for(auto nxt : graph[node]){
            if(!dp[nxt][col]){
                dfs(nxt,col) ;
            }            
        }
    }

    void solve(){
        scanf("%d%d",&N,&M) ;

        for(int i = 0 ; i < M ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;
            graph[u].push_back(v) ;
            graph[v].push_back(u) ;
        }


        dfs(1,-1) ;

        int answer = 0 ;

        for(int i = 1 ; i <= N ; i++) answer += (dp[i][2] == true) ;

        printf("%d\n",answer) ;
    }
};


int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d: ",i) ;
        TC x ;
        x.solve();
    }

    return 0 ;
}
