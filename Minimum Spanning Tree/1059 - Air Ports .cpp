
/**
 *    author        : Saurav-Paul 
 *    created       : September 19, 2020 11:07 AM
 *    Problem Name  : 1059 - Air Ports
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1059
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

    int N , M ;
    vector<vector<pair<int,int>>> graph ;
    priority_queue<Edge> edges ;
    vector<int> parent ;

    long long cost = 0 , A ;

    int find_parent(int node){
        if(parent[node] == node) return node ;
        return parent[node] = find_parent(parent[node]) ;
    }

    void MST(){

        while(!edges.empty()){
            Edge curr = edges.top() ;
            edges.pop() ;

            int u_parent = find_parent(curr.u) ;
            int v_parent = find_parent(curr.v) ;

            if(u_parent != v_parent){
                cost += curr.cost ;
                parent[u_parent] = v_parent ;
            }

        }
    }


    public :
    void solve(){

        scanf("%d%d%lld",&N,&M,&A) ;
        parent.assign(N+1,0) ;

        for(int i = 1 ; i <= M ; i++){
            int u , v , w;
            scanf("%d%d%d",&u,&v,&w) ;

            if(w < A){
                edges.push(Edge(u,v,w)) ;
            }
        }

        for(int i = 1 ; i <= N ; i++) parent[i] = i ;

        MST() ;

        map<int,int> cnt ;

        for(int i = 1; i <= N ; i++){
            cnt[find_parent(i)] ++ ;
        }

        long long number_of_airport_needed = cnt.size() ;
        cost += (A*number_of_airport_needed) ;

        printf("%lld %lld\n",cost , number_of_airport_needed) ;

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
