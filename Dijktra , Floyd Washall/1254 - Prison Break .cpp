/**
 *    author        : Saurav Paul 
 *    created       : August 27, 2020 12:06 AM
 *    Problem Name  : 1254 - Prison Break
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1254
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class Node{
    public :
        int node , cost , fuel ;
        Node(int _node , int _cost , int _fuel){
            node = _node , cost = _cost , fuel = _fuel ;
        }
};

bool operator<(Node a , Node b){
    return a.cost > b.cost ;
}

class TC{
    static const int INF = 1e9+90 ;
    static const int nax = 111 ;
    int N , M , Q ;
    vector<pair<int,int>> graph[nax] ;
    vector<int> fuel_cost;
    int dist[nax][nax] ;

    void dijkstra(int c, int s , int t){
        for(int i = 0; i < nax ; i++){
            for(int j = 0 ; j < nax ; j++){
                dist[i][j] = INF ;
            }
        }
        dist[s][0] = 0 ;

        priority_queue<Node> PQ ;
        PQ.push(Node(s,0,0)) ;

        while(!PQ.empty()){
            Node curr = PQ.top() ;
            PQ.pop() ;

            if(curr.node == t) break ;
            if(curr.cost != dist[curr.node][curr.fuel]) continue ;

            int f_cost = fuel_cost[curr.node] ;
            if(curr.fuel + 1 <= c){ 
                if(dist[curr.node][curr.fuel+1] > curr.cost + f_cost){
                     dist[curr.node][curr.fuel+1] = curr.cost + f_cost ;
                     PQ.push(Node(curr.node,curr.cost + f_cost , curr.fuel+1)) ;
                }
            }

            for(auto x : graph[curr.node]){
                int nxt = x.first , w = x.second ;
                if(curr.fuel < w) continue ;
                if(dist[nxt][curr.fuel-w] > curr.cost){
                    dist[nxt][curr.fuel-w] = curr.cost ;
                    PQ.push(Node(nxt,curr.cost,curr.fuel - w)) ;
                }
            }
        }

        if(dist[t][0] == INF) puts("impossible") ;
        else printf("%d\n",dist[t][0]) ;
    }
    
    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        for(int i = 0 ; i < N ; i++){
            int w ;
            scanf("%d",&w) ;
            fuel_cost.emplace_back(w) ;
        }
        for(int i = 0 ; i < M ; i++){
            int u , v , w;
            scanf("%d%d%d",&u,&v,&w) ;

            graph[u].emplace_back(v,w) ;
            graph[v].emplace_back(u,w) ;
        }
        
        scanf("%d",&Q) ;
        while(Q--){
            int c,s,t;
            scanf("%d%d%d",&c,&s,&t) ;
            dijkstra(c,s,t) ;
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
