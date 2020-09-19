
/**
 *    author        : Saurav-Paul 
 *    created       : September 19, 2020 2:21 PM
 *    Problem Name  : 1123 - Trail Maintenance
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1123
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class Edge{
    public :
        int u , v , cost ;
        Edge(int _u , int _v , int _cost){
            u = _u , v = _v , cost = _cost ;
        }
};

bool operator<(Edge a , Edge b){
    return a.cost > b.cost ;
}

class TC{

    static const int nax = 210 ;
    int N, M;
    priority_queue<Edge> edges , PQ ;
    vector<int> parent ; 
    long long cost = 0 ;

    int find_parent(int node){
        if(parent[node] == node) return node ;
        return parent[node] = find_parent(parent[node]) ;
    }

    void MST(){

        PQ = edges;
        edges = priority_queue<Edge> () ;

        cost = 0 ;
        for(int i = 1 ; i <= N ; i++) parent[i] = i ;

        int counter = 0 ;
        while(!PQ.empty()){
            Edge curr = PQ.top() ;
            PQ.pop() ;

            int u_parent = find_parent(curr.u) ;
            int v_parent = find_parent(curr.v) ;

            if(u_parent != v_parent){
                cost += curr.cost ;
                parent[v_parent] = u_parent ;
                edges.push(curr) ;
                counter ++ ;
            }
            if(counter == N-1) break ;
        }

        if(counter < N-1) puts("-1") ;
        else printf("%lld\n",cost) ;
    }


    public :
    void solve(){
        scanf("%d%d",&N,&M) ;

        parent.assign(N+1,0) ;

        for(int i = 1; i <= M ; i++){
            int u , v, w ;
            bool ok = false ;
            scanf("%d%d%d",&u,&v,&w) ;
            edges.push(Edge(u,v,w)) ;
            MST() ;
        }
    }
};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d:\n",i) ;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
