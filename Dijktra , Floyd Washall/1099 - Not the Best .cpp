
/**
 *    author        : Saurav Paul 
 *    created       : August 25, 2020 12:36 AM
 *    Problem Name  : 1099 - Not the Best
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1099
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;
const int INF =  1e9 + 90 ;

class Prop{
    public :
         ll f_cost , s_cost , min_edge ;
         Prop(){
             f_cost = s_cost = min_edge = INF ;
         }
         void update(ll af, ll as, ll ame){
             f_cost = af , s_cost = as , min_edge = ame ;
         }
};

class TC{
    static const int nax = 5e3 + 10 ;
    int N,R ;
    vector<pair<int,int>> graph[nax] ;
    vector<Prop> vis;

    void dijkstra(){
        queue<int> Q ;
        Q.push(1) ;

        vis = vector<Prop>(N+1) ;
        vis[1].update(0,INF,INF) ;

        while(!Q.empty()){
            int curr = Q.front() ;
            Q.pop() ;

            ll f_cost = vis[curr].f_cost ;
            ll s_cost = vis[curr].s_cost ;
            ll min_edge = vis[curr].min_edge ;

            for(auto x : graph[curr]){
                int nxt = x.first ;
                ll cost = x.second ;

                if(vis[nxt].f_cost > f_cost + cost){
                    vis[nxt].s_cost = min({vis[nxt].f_cost, s_cost + cost,f_cost + cost + 2 * min_edge}) ;
                    vis[nxt].f_cost = f_cost + cost ;
                    vis[nxt].min_edge = min({vis[nxt].min_edge, min_edge,cost}) ;
                    Q.push(nxt) ;
                }
                else if(vis[nxt].s_cost > f_cost + cost){
                    if(vis[nxt].f_cost == f_cost + cost){
                        vis[nxt].s_cost = min({vis[nxt].s_cost,f_cost + cost + 2 * min_edge, s_cost + cost}) ;
                    }
                    else {
                        vis[nxt].s_cost = f_cost + cost ;
                    }
                    vis[nxt].min_edge = min({vis[nxt].min_edge, min_edge,cost}) ;
                    Q.push(nxt) ;
                }
            }
        }
        printf("%lld\n",vis[N].s_cost) ;
    }

    public :
    void solve(){
        scanf("%d%d",&N,&R) ;

        for(int i = 0 ; i < R ; i++){
            int u , v, w ;
            scanf("%d%d%d",&u,&v,&w) ;

            graph[u].push_back({v,w}) ;
            graph[v].push_back({u,w}) ;
        }

        dijkstra() ;
    }

};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d: ",i) ;
        TC tc ;
        tc.solve() ;
    }

    return 0 ;
}
