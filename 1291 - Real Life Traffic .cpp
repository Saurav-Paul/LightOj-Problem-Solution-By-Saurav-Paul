
/**
 *    author        : Saurav Paul 
 *    created       : August 28, 2020 2:33 PM
 *    Problem Name  : 1291 - Real Life Traffic
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1291
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    int N , M ;
    vector<vector<int>> graph ;

    int timer = 0 ;
    vector<bool> vis ;
    vector<int> low , tin ;
    int cnt = 0 ;
    set<pair<int,int>> cut_bridge;

    int find_it(int node, int par = -1){
        vis[node] = true ;
        int number = 0 ;

        for(int to : graph[node]){
            if(to == par) continue ;
            if(check(node,to)) number ++ ;
            else if(vis[to]) continue ;
            else number += find_it(to,node) ;
        }
        return number ;
    }

    bool check(int u, int v){
        if(u > v) swap(u,v) ;
        if(cut_bridge.count({u,v})) return true ;
        return false ;
    }

    void dfs(int node, int par = -1){
        vis[node] = true ;
        low[node] = tin[node] = timer ++ ;

        for(int to : graph[node]){
            if(to == par) continue ;
            if(vis[to]){
                low[node] = min(low[node],tin[to]) ;
            }
            else{
                dfs(to,node) ;
                low[node] = min(low[node] , low[to]) ;

                if(low[to] > tin[node]){
                    addBridge(node,to) ;
                }
            }
        }
    }

    void addBridge(int u , int v){
        if(u > v) swap(u,v) ;
        cut_bridge.insert({u,v}) ;
    }

    void find_cut_bridge(){
        vis.assign(N,false) ;
        low.assign(N,-1) ;
        tin.assign(N,-1) ;

        for(int i = 0; i < N ; i++){
            if(!vis[i]){
                dfs(i) ;
            }
        }

        vis.assign(N,false) ;

        for(auto bridge : cut_bridge){
            for(auto to : {bridge.first,bridge.second}){
                if(!vis[to])
                    cnt += (find_it(to) == 1) ;
            }
        }

        printf("%d\n",(cnt+1)/2) ;

    }


    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        graph = vector<vector<int>>(N) ;

        for(int i = 0 ; i < M ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;
            graph[u].emplace_back(v) ;
            graph[v].emplace_back(u) ;
        }

        find_cut_bridge() ;

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
