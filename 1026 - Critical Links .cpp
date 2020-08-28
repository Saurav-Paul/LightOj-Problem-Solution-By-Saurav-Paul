
/**
 *    author        : Saurav Paul 
 *    created       : August 28, 2020 12:06 PM
 *    Problem Name  : 1026 - Critical Links
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1026
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    int N ;
    vector<vector<int>> graph ;

    int timer = 0 ;
    vector<int> tin , low ;
    set<pair<int,int>> cut_bridges ;
    vector<bool> vis ;

    void dfs(int node, int par = -1){
        vis[node] = true ;
        low[node] = tin[node] = timer++ ;

        for(int to : graph[node]){
            if(to == par) continue ;
            if(vis[to]){
                low[node] = min(low[node] , tin[to]) ;
            }
            else{
                dfs(to,node) ;
                low[node] = min(low[node],low[to]) ;
                if(low[to] > tin[node]){
                    int _u = node, _v = to ;
                    if(_u > _v) swap(_u,_v) ;
                    cut_bridges.insert({_u,_v}) ;
                }
            }
        }
    }

    void find_cut_bridge(){
        vis.assign(N+1,false) ;
        tin.assign(N+1,-1) ;
        low.assign(N+1,-1) ;

        for(int i = 0 ; i < N ; i++){
            if(!vis[i])
                dfs(i) ;
        }

        int found = cut_bridges.size() ;
        printf("%d critical links\n",found) ;
        for(auto bridge : cut_bridges){
            printf("%d - %d\n",bridge.first,bridge.second) ;
        }
    }

    public :
    void solve(){

        cin >> N ;
        graph = vector<vector<int>>(N+1) ;

        for(int i = 0 ; i < N ; i++){
            int u , n , v;
            scanf("%d (%d)",&u,&n) ;

            while(n--){
                scanf("%d",&v) ;
                graph[u].emplace_back(v) ;
            }
        }
        find_cut_bridge() ;
    }
    TC(int _caseno){
        printf("Case %d:\n",_caseno) ;
    }
};

int main(){

    int testcases ;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i++){
        TC tc(i);
        tc.solve() ;
    }

    return 0 ;
}
