
/**
 *    author        : Saurav Paul 
 *    created       : August 27, 2020 9:34 PM
 *    Problem Name  : 1221 - Travel Company
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1221
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class Edge{
    public :
        int u , v, cost ;
        Edge(int _u , int _v , int _cost){
            u = _u , v = _v , cost = _cost;
        }
};

class TC{

    int N , R , P ;
    vector<Edge> graph ;
    vector<int> dist ;

    void bellman_ford(){

        dist.assign(N+1,0) ;
        bool negative_cycle = false ;

        for(int i = 0 ; i < N ; i++){
            negative_cycle = false ;

            for(auto e : graph){
                int new_value = dist[e.u] + e.cost ;
                if(dist[e.v] > new_value){
                    dist[e.v] = new_value ;
                    negative_cycle = true ;
                }
            }

            if(!negative_cycle) break ;
        }

        puts(negative_cycle?"YES":"NO") ;

    }

    public :
    void solve(){
        scanf("%d%d%d",&N,&R,&P) ;

        for(int t = 0 ; t < R ; t++){
            int u , v, i , e ;
            scanf("%d%d%d%d",&u,&v,&i,&e) ;
            graph.emplace_back(Edge(u,v,P*e-i)) ;
        }

        bellman_ford() ;
        
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
