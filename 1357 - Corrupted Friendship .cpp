
/**
 *    author        : Saurav Paul 
 *    created       : August 21, 2020 7:41 PM
 *    Problem Name  : 1357 - Corrupted Friendship
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1357
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;
int N ;
using vi = vector<int> ;
vector<vi> graph ;
vi vis ;
ll answer = 0 ;

int dfs(int node){

    vis[node] = true ;

    int total_child = 0;
    vi childs ;
    for(auto x : graph[node]){
        if(vis[x]) continue ;
        childs.push_back(dfs(x)) ;
        total_child += childs.back() ;
    }

    int sz = childs.size() ;
    if(sz){
        ll temp = 0;
        ll sum = total_child ;
        for(auto x : childs){
            sum -= x;
            temp += x * sum;
        }
        answer += temp ;
    }

    return total_child + 1 ;
}

void solve(){

    cin >> N ;
    graph = vector<vi> (N+1,vi()) ;
    vis = vi(N+1) ;

    for(int i = 1 ;i < N ; i++){
        int u , v ;
        cin >> u >> v;
        graph[u].push_back(v) ;
        graph[v].push_back(u) ;
    }

    answer = 0 ;
    dfs(1) ;
    cout << N-1 << " " << answer << endl ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        cout << "Case "<< i << ": " ;
        solve();
    }

    return 0 ;
}
