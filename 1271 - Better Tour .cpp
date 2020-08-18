
/**
 *    author        : Saurav Paul 
 *    created       : August 18, 2020 10:30 AM
 *    Problem Name  : 1271 - Better Tour
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1271
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

const int nax = 5e4 + 10 ;
int N ;
vector<int> graph[nax+1] ;
int V[nax+1] ;
bool vis[nax+1] ;
int Prev[nax+1] ;

void clear(){

    for(int i = 0 ; i <= nax ; i++){
        graph[i].clear() ;
        Prev[i] = -1 ;
    }
    memset(vis,false,sizeof vis) ;

}

void bfs(int node){
    queue<int> Q ;
    Q.push(node) ;
    vis[node] = true ;

    while(!Q.empty()){
        int curr = Q.front() ;
        Q.pop() ;
        
        for(int neighbour : graph[curr]){
            if(vis[neighbour] == false){
                Prev[neighbour] = curr ;
                Q.push(neighbour) ;
                vis[neighbour] = true ;
            }
        }

    }
}

void solve(){
    clear() ;

    scanf("%d",&N) ;
    for(int i = 1 ; i <= N ; i++) scanf("%d",&V[i]) ;

    for(int i = 2;  i <= N ; i++){
        int u = V[i-1] ;
        int v = V[i] ;

        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    for(int i = 1; i <= nax ; i++){
        sort(graph[i].begin(),graph[i].end()) ;
    }

    int start = V[1]  ;
    int end = V[N] ;
    bfs(start) ;

    vector<int> answer_path ;

    for(int p = end ; p != -1 ; p = Prev[p]){
        answer_path.push_back(p) ;
    }

    for(int now = answer_path.size() - 1 ; now >= 0 ; now --){
        printf("%d%s",answer_path[now],(now?" ":"\n")) ;
    }

}


int main(){

    int T ;
    scanf("%d",&T) ;

    for(int t = 1 ; t <= T ; t++){
        printf("Case %d:\n",t) ;
        solve() ;
    }
}
