				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using pi = pair<int,int> ;


void solve () {
    int node , edge , s , t;
    long long  p ;
    scanf("%d%d%d%d%lld",&node,&edge,&s,&t,&p) ;
    vector< pair<pi,int>  > edges ;
    vector< pi > graph[node + 1] , rev_graph[node + 1];

    for(int i = 0 ; i < edge ; i ++){
        int u , v, c ;
        scanf("%d%d%d",&u,&v,&c) ;
        pi temp = {u,v} ;
        edges.emplace_back(temp,c) ;
        graph[u].emplace_back(v,c) ;
        rev_graph[v].emplace_back(u,c) ;
    }
    vector < int> scost(node + 1, INT_MAX) , tcost(node + 1 , INT_MAX) ;
    scost[s] = 0 ;

    queue<int> Q; 
    Q.push(s);
    while(!Q.empty()){
        int top = Q.front() ;
        Q.pop() ;


        for(auto x : graph[top]){
            long long  v = x.first , c = x.second ;
            if(scost[top] + c < scost[v]&& scost[top]+c <= p){
                scost[v] = scost[top] + c;
                Q.push(v) ;
            }
        }
    }
    
    tcost[t] = 0 ;
    Q.push(t) ;
    while(!Q.empty()){
        int top = Q.front() ;
        Q.pop() ;


        for(auto x : rev_graph[top]){
            long long  v = x.first , c = x.second ;
            if(tcost[top] + c < tcost[v]&& tcost[top]+c <= p){
                tcost[v] = tcost[top] + c;
                Q.push(v) ;
            }
        }
    }
    
    long long  mx = -1 ;
    for(auto x : edges){
        long long  u  = x.first.first , v = x.first.second , c = x.second ;
        if(scost[u]+c+tcost[v] <= p){
            mx = max(mx,c) ;
        }
    }
    printf("%lld\n",mx) ;
}

int main(){
    int testcase ;
    scanf("%d",&testcase) ;
    for(int t = 1; t <= testcase ; ++t){
        printf("Case %d: ",t);
        solve () ;
    }

    return 0;
}
