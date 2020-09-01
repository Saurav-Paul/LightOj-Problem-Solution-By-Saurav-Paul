
/**
 *    author        : Saurav Paul 
 *    created       : August 27, 2020 7:46 PM
 *    Problem Name  : 1074 - Extended Traffic
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1074
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class Edge{
    public :
        int u , v;
        Edge(int _u, int _v){
            u = _u , v = _v ;
        }
};

class TC{
    static const int nax = 210 ;
    const int INF = 1e9 + 90 ;
    int N , M ;
    vector<int> busyness, dist;
    vector<Edge> graph ;

    void bellman_ford(){

        dist.assign(N+1,INF) ;
        dist[1] = 0 ;

        for(int i = 0 ; i < N ; i++){
            bool ar_nai = true ;
            for(Edge e : graph){
                int curr = e.u , nxt = e.v ;
                if(dist[curr] == INF) continue ;
                int cost = busyness[nxt] - busyness[curr] ;
                cost = (cost*cost*cost) ;
                int new_value = dist[curr]+cost ;

                if(dist[nxt] > new_value){
                    dist[nxt] = max(-INF , new_value) ;
                    ar_nai = false ;
                }
            }
            if(ar_nai) break ;
        }

    }

    public :
    void solve(){
        scanf("%d",&N) ;
        
        busyness.push_back(0) ;
        for(int i = 0 ; i < N ; i++){
            int busy ;
            scanf("%d",&busy) ;
            busyness.emplace_back(busy) ;
        }

        scanf("%d",&M) ;

        for(int i = 0 ; i < M ; i++){
            int u , v;
            scanf("%d%d",&u,&v) ;
            graph.emplace_back(Edge(u,v)) ;
        }

        bellman_ford() ;

        int Q;
        scanf("%d",&Q) ;
        while(Q--){
            int zunction ;
            scanf("%d",&zunction) ;
            int cost = dist[zunction] ;
            if(cost == INF || cost < 3) puts("?") ;
            else printf("%d\n",cost) ;
        }
    }
};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d:\n",i) ;
        TC tc ;
        tc.solve() ;
    }

    return 0 ;
}
