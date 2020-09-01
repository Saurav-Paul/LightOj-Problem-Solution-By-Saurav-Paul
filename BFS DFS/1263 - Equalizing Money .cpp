				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

const int nax = 1e3 + 5 ;
vector< vector<int> > graph(nax,vector<int> ());
vector<int> money(nax);
bool isvisited[nax] ;
int Node, Edge;
int cnt = 0;

void clear_out(){
    for(int i= 1 ; i <= Node ; i++){
        graph[i].clear() ;
        isvisited[i] = false;
    }
}
int dfs(int node){

    cnt ++;
    isvisited[node] = true;
    int total = money[node];
    for(auto x : graph[node]){
        if(isvisited[x]==false)
            total += dfs(x);
    }
    return total ;
}
void solve(){

    scanf("%d%d",&Node,&Edge);
    clear_out() ;
    for(int i = 1 ; i <= Node ; i++){
        scanf("%d",&money[i]);
    }

    for(int i = 0 ; i < Edge ; i++){
        int u , v;
        scanf("%d%d",&u,&v);

        graph[u].emplace_back(v);
        graph[v].emplace_back(u);

    }
    int got =  - 1;
    bool ok = true ;


    for(int i = 1 ; i<= Node ; i++){

        if(isvisited[i]==false){
            cnt = 0;
            int total = dfs(i);

            if(total%cnt != 0){
                ok = false ;
                break ;
            }
            else{
                total = total / cnt ;
                if(got == -1){
                    got = total ;
                }
                else if(got != total){
                    ok = false ;
                    break ;
                }
            }


        }

    }
    if(ok) puts("Yes");
    else puts("No");

}

int main()
{

    int testcase ;
    scanf("%d",&testcase);
    for(int t = 1 ; t <= testcase ; t++){
        printf("Case %d: ",t);
        solve() ;
    }

    return 0;
}
