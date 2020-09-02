
/**
 *    author        : Saurav Paul 
 *    created       : September 02, 2020 12:27 PM
 *    Problem Name  : 1210 - Efficient Traffic System
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1210
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    int N , M ;
    vector<vector<int>> graph, rev_graph , scc ;
    vector<int> component ;
    vector<bool> vis ;
    stack<int> order ;

    void dfs1(int node){
        vis[node] = true ;

        for(int to : graph[node]){
            if(!vis[to])
                dfs1(to) ;
        }
        order.push(node) ;
    }

    void dfs2(int node){
        vis[node] = true ;
        component.emplace_back(node) ;
        
        for(auto to : rev_graph[node]){
            if(!vis[to])
                dfs2(to) ;
        }
    }

    void find_scc(){
        vis.assign(N+1,false) ;

        for(int i = 1; i <= N ; i++){
            if(!vis[i]){
                dfs1(i) ;
            }
        }

        vis.assign(N+1,false) ;

        while(!order.empty()){
            int curr = order.top() ;
            order.pop() ;

            if(vis[curr]) continue ;

            component.clear() ;
            dfs2(curr) ;
            scc.emplace_back(component) ;

        }

        int sz = scc.size() ;
        int ans = 0 ;


        if(sz > 1){
            vector<int> indegree(sz),outdegree(sz), parent(N+1) ;
            int a1 = 0 , a2 = 0;

            for(int i = 0 ; i < sz ; i++){
                for(auto x : scc[i]){
                    parent[x] = i ;
                }
            }

            for(int i = 0 ; i < sz ; i++){
                for(auto x : scc[i]){
                    for(auto to : graph[x]){
                        if(parent[to] == i) continue ;
                        indegree[parent[to]] ++ ;
                        outdegree[i] ++ ;
                    }

                }
            }

            for(int i = 0 ; i < sz ; i++){
                if(indegree[i] == 0) a1 ++ ;
                if(outdegree[i] == 0) a2 ++ ;
            }

            ans = max(a1,a2) ;

        }

        printf("%d\n",ans) ;


    }

    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        graph.assign(N+1,vector<int>()) ;
        rev_graph.assign(N+1,vector<int>()) ;
        for(int i = 0 ; i < M ; i++){
            int u , v ;
            scanf("%d%d",&u,&v) ;
            graph[u].emplace_back(v) ;
            rev_graph[v].emplace_back(u) ;
        }

        find_scc() ;
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
