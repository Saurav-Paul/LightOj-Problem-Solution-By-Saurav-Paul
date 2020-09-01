
/**
 *    author        : Saurav Paul 
 *    created       : August 31, 2020 12:11 AM
 *    Problem Name  : 1308 - Ant Network
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1308
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    int N , M ;
    vector<vector<int>> graph;

    int timer = 0 ;
    vector<int> low , tin ;
    vector<bool> vis , cut;
    set<int> paisi;
    unsigned long long temp ;

    void dfs(int node, int par = -1){
        vis[node] = true ;
        tin[node] = low[node] = timer ++ ;

        int child = 0 ;
        for(int to : graph[node]){
            if(to == par) continue;
            if(vis[to]){
                low[node] = min(low[node],tin[to]) ;
            }
            else{
                child ++ ;
                dfs(to,node) ;
                low[node] = min(low[node],low[to]) ;

                if(tin[node] <= low[to] && par != -1){
                    cut[node] = true ;
                }
            }
        }

        if(par == -1 && child > 1){
            cut[node] = true ;
        }
    }

    int find_component(int node, int par = -1){
        vis[node] = true ;

        int cnt = 0 ;
        for(int to : graph[node]){
            if(cut[to]){
                paisi.insert(to) ;
                continue ;
            }
            if(to == par || vis[to]) continue ;
            cnt += find_component(to,node) ;
        }
        return cnt + 1;
    }

    void find_cut_points(){
        low.assign(N,-1) ;
        tin.assign(N,-1) ;
        vis.assign(N,false) ;
        cut.assign(N,false) ;

        for(int i = 0 ; i < N ; i++){
            if(!vis[i])
                dfs(i) ;
        }

        long long need = 0;
        unsigned long long way = 1 ;
        int number_of_cut = 0 ;
        for(auto x : cut){
            number_of_cut += (x) ;
        }

        if(!number_of_cut){
            need = 2;
            way = (N-1) * N ;
            way /= 2 ;
        }
        else{
            vis.assign(N,false) ;
            for(int i = 0; i < N ; i++){
                if(vis[i] || cut[i]) continue ;

                paisi.clear() ;
                temp = find_component(i) ;

                if(paisi.size() <= 1){
                    need ++ ;
                    way *= temp ;
                }
            }
        }

        printf("%lld %llu\n",need,way) ;
    }

    public :
    void solve(){

        scanf("%d%d",&N,&M) ;
        graph.assign(N,vector<int>()) ;

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
        printf("Case %d: ",i);
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
