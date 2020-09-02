
/**
 *    author        : Saurav Paul 
 *    created       : September 02, 2020 12:40 AM
 *    Problem Name  : 1034 - Hit the Light Switches
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1034
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{
    int N , M ;
    vector<vector<int>> graph ;
    stack<int> top_order ;
    vector<bool> vis ;

    void dfs(int node,bool take = true){
        vis[node] = true ;

        for(auto to : graph[node]){
            if(!vis[to])
              dfs(to,take) ;
        }
        if(take) top_order.push(node) ;
    }

    void topological_sorting(){
        vis.assign(N+1,false) ;
        top_order  = stack<int> ();

        for(int i = 1; i <= N ; i++){
            if(!vis[i])
                dfs(i) ;
        }
    }

    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        graph.assign(N+1,vector<int>()) ;
        vis.assign(N+1,false) ;
        for(int i = 0 ; i < M ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;
            graph[u].emplace_back(v) ;
        }

        topological_sorting() ;
        int ans = 0 ;
        vis.assign(N+1,false) ;

        while(!top_order.empty()){
            int Top = top_order.top() ;
            top_order.pop() ;

            if(vis[Top]) continue ;
            ++ans ;
            dfs(Top,false) ;
        }

        printf("%d\n",ans) ;

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
