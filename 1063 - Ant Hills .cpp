
/**
 *    author        : Saurav Paul 
 *    created       : August 28, 2020 2:03 PM
 *    Problem Name  : 1063 - Ant Hills
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1063
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{
    int N , M ;
    vector<vector<int>> graph ;
    
    int timer = 0 ;
    vector<bool> vis , cut_point;
    vector<int> tin , low ;


    void dfs(int node , int par = -1){
        vis[node] = true ;
        low[node] = tin[node] = timer++ ;

        int child = 0 ;
        for(int to : graph[node]){
            if(par == to) continue ;
            if(vis[to]){
                low[node] = min(low[node],tin[to]) ;
            }
            else{
                ++ child ;
                dfs(to,node) ;
                low[node] = min(low[node],low[to]);

                if(low[to] >= tin[node] && par != -1){
                    cut_point[node] = true ;
                }
            }
        }

        if(par == -1 && child > 1) cut_point[node] = true ;
    }

    void find_cut_points(){
        vis.assign(N+1,false);
        cut_point.assign(N+1,false);
        low.assign(N+1,-1) ;
        tin.assign(N+1,-1) ;

        for(int i = 1; i <= N ; i++){
            if(!vis[i])
                dfs(i) ;
        }

        int cnt = 0 ;
        for(int i = 1 ; i <= N ; i++){
            cnt += (cut_point[i]) ;
        }
        printf("%d\n",cnt) ;
    }

    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        graph = vector<vector<int>>(N+1) ;

        for(int i = 0 ; i < M ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;

            graph[u].emplace_back(v) ;
            graph[v].emplace_back(u) ;
        }

        find_cut_points() ;
    }
};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d: ",i) ;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
