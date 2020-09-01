
/**
 *    author        : Saurav Paul 
 *    created       : August 26, 2020 12:03 PM
 *    Problem Name  : 1281 - New Traffic System
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1281
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 90 ;

class Edge{
    public :
        int v, w ;
        bool extra ;
        Edge(int _v , int _w , bool _extra){
            v = _v , w = _w , extra = _extra ;
        }
};

class Node{
    public :
        int node , cost ,  extra ;
        Node(int _node ,int _cost, int _extra){
            node = _node ,cost = _cost ,extra = _extra ;
        }

};

bool operator<(Node a , Node b){
    return a.cost > b.cost ;
}

class TC{

    vector<vector<Edge>> graph ;
    int N , M , K , D ;
    int answer = INF ;
    vector<vector<int>> dist ;

    void dijkstra(){
        for(int i = 0 ; i <= N ;i++){
            for(int j = 0 ; j <= D ; j++){
                dist[i][j] = INF ;
            }
        }

        dist[1][0] = 0 ;

        priority_queue<Node> PQ ;
        PQ.push(Node(1,0,0)) ;

        while(!PQ.empty()){
            Node curr = PQ.top() ;
            PQ.pop() ;
            int node = curr.node ;
            int cost = curr.cost ;
            int extra = curr.extra ;

            if(dist[node][extra] != cost) continue ;

            for(Edge e : graph[node]){
                int nxt = e.v , w = e.w , ex = (e.extra) ;
                if(extra+ex > D) continue ;

                if(extra+ex <= D && dist[nxt][extra+ex] > cost + w ){
                    dist[nxt][extra+ex] = cost + w ;
                    PQ.push(Node(nxt,cost+w,extra+ex)) ;
                }
            }
        }

    }

    public :
    void solve(){
        scanf("%d%d%d%d",&N,&M,&K,&D) ;

        graph = vector<vector<Edge>>(N+1) ;
        dist = vector<vector<int>> (N+1, vector<int>(D+1)) ;

        for(int i = 0 ; i < M ; i++){
            int u , v, w ;
            scanf("%d%d%d",&u,&v,&w) ;
            ++ u , ++ v;
            graph[u].emplace_back(Edge(v,w,false)) ;
        }

        for(int i = 0 ; i < K ; i++){
            int u , v, w ;
            scanf("%d%d%d",&u,&v,&w) ;
            ++ u , ++ v;
            graph[u].emplace_back(Edge(v,w,true)) ;

        }

        dijkstra() ;

        for(int i = 0 ; i <= D ; i++) answer = min(answer, dist[N][i]) ;
        if(answer == INF) puts("Impossible") ;
        else printf("%d\n",answer) ;
    }

};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc ;
        printf("Case %d: ",i) ;
        tc.solve() ;
    }

    return 0 ;
}
