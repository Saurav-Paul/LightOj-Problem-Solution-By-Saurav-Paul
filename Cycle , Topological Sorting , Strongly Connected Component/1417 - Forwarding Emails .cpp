
/**
 *    author        : Saurav Paul 
 *    created       : September 03, 2020 4:14 PM
 *    Problem Name  : 1417 - Forwarding Emails
 *    Problem Limit : 3000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1417
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;


using ll = long long int ;

class TC{
    static const int nax = 5e4 + 10 ;

    vector<int> graph[nax] , graph_rev[nax] ;
    vector<vector<int>> scc ;
    int N ;

    vector<bool> vis ;
    vector<int> order, component , which_scc , cnt ;

    void dfs_1(int node){
        vis[node] = true ;

        for(auto to : graph[node]){
            if(!vis[to]) dfs_1(to) ;
        }

        order.push_back(node) ;
    }

    void dfs_2(int node){
        vis[node] = true ;
        component.push_back(node) ;

        for(auto to : graph_rev[node]){
            if(!vis[to]) dfs_2(to) ;
        }
    }

    int dfs_3(int node){
        vis[node] = true ;

        int c = 1 ;
        for(auto to : graph[node]){
            if(which_scc[to] != -1){
                c += cnt[to] ;
            }
            else if(vis[to]){
                c += cnt[to] ;
            }
            else {
                c += dfs_3(to) ;
            }
        }
        return cnt[node] = c ;
    }

    void find_scc(){
        
        vis.assign(N+1,false) ;
        for(int i = 1 ; i <= N ; i++){
            if(!vis[i]){
                dfs_1(i) ;
            }
        }

        vis.assign(N+1,false) ;
        int counter = 0 ;
        which_scc.assign(N+1,-1) ;
        cnt.assign(N+1,0) ;
        for(int i = order.size() - 1 ; i >= 0 ; i--){
            int to = order[i] ;
            if(!vis[to]){
                component.clear() ;
                dfs_2(to) ;
                scc.push_back(component) ;

                int p = component.size() ;
                if(p == 1) continue ;

                counter++ ;
                for(auto c : component) {
                    which_scc[c] = counter ;
                    cnt[c] = p ;
                }
            }
        }

        vis.assign(N+1,false) ;
        for(int i = 1 ; i <= N ; i++){
            if(!vis[i] && cnt[i] == 0){
                dfs_3(i) ;
            }
        }

    }
        

    public :
    void solve(){
        scanf("%d",&N) ;

        for(int i = 1 ; i <= N ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;

            graph[u].emplace_back(v) ;
            graph_rev[v].emplace_back(u) ;
        }

        find_scc() ;

        int ans = -1 , mx = -1 ;

        for(int i = 1; i <= N ; i++){
            if(cnt[i] > mx){
                ans = i ;
                mx = cnt[i] ;
            }
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
