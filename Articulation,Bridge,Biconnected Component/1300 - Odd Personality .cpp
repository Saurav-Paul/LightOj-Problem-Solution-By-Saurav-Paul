
/**
 *    author        : Saurav Paul 
 *    created       : August 29, 2020 2:07 PM
 *    Problem Name  : 1300 - Odd Personality
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1300
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    int N , M ;
    static const int nax = 10011 ;
    vector<int> graph[nax] ;

    int timer = 0 ;
    bool vis[nax] ;
    int color[nax] ;
    vector<int> tin , low ;
    set<pair<int,int>> cut_bridge ;
    set<int> visit_holo ;

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
                low[node] = min(low[node],low[to]) ;
                if(low[to] > tin[node]){
                    addBridge(node, to)  ;
                }
            }
        }
    }

    void addBridge(int u , int v){
        if(u > v) swap(u,v) ;
        cut_bridge.insert({u,v}) ;
    }

    bool check(int u , int v){
        if(u > v) swap(u,v) ;
        if(cut_bridge.count({u,v})) return true ;
        return false ;
    }

    bool check_bicolor(int node,int col = 1 , int par = -1){
        vis[node] = true ;
        color[node] = col ;
        visit_holo.insert(node) ;

        int nxt_col = (col == 1? 2 : 1) ;
        bool ok = false ;
        for(auto to : graph[node]){
            if(to == par || check(node,to)){
                continue ;
            }
            if(color[to] == col){
                ok = true ;
            }
            else if(color[to] == nxt_col){
                continue ;
            }
            else{
                ok |= check_bicolor(to,nxt_col,node) ;
            }
        }

        return ok ;
    }

    void find_cut_bridges(){
        memset(vis,false,sizeof vis);
        tin.assign(N,-1) ;
        low.assign(N,-1) ;

        for(int i = 0; i < N ; i++){
            if(!vis[i])
                dfs(i) ;
        }

        memset(vis,false,sizeof vis) ;
        memset(color,-1,sizeof color) ;

        int cnt = 0 ;


        for(int i = 0 ; i < N ; i++){
            if(!vis[i]){
                visit_holo.clear() ;
                bool ok = check_bicolor(i,1,-1) ;
                if(ok){
                    cnt += visit_holo.size() ;
                }
            }
        }

        printf("%d\n",cnt) ;

    }

    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        for(int i = 0; i < M ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;
            graph[u].emplace_back(v) ;
            graph[v].emplace_back(u) ;
        }

        find_cut_bridges() ;
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
