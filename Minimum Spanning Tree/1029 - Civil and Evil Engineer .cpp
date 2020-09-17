
/**
 *    author        : Saurav Paul 
 *    created       : September 17, 2020 11:07 PM
 *    Problem Name  : 1029 - Civil and Evil Engineer
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1029
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    int N ;
    static const int nax = 105 ;

    vector<pair<int,int>> graph[nax] ;

    int minimum_spanning_tree(int mul){
priority_queue<pair<int,int>> PQ ;

        for(auto to : graph[0]){
            PQ.push({to.second*mul,to.first}) ;
        }

        vector<int> taken(N+10,false) ;

        int khoroch = 0 ;

        taken[0] = true ;

        while(!PQ.empty()){
            pair<int,int> p = PQ.top() ;
            PQ.pop() ;

            int cost = p.first * mul ;
            int curr = p.second ;

            if(taken[curr]) continue ;

            taken[curr] = true ;
            khoroch += cost ;

            for(auto to : graph[curr]){
                PQ.push({to.second * mul , to.first}) ;
            }
        }

        return khoroch ;

    }

    public :
    void solve(){

        scanf("%d",&N) ;
        while(true){
            int u, v , w ;
            scanf("%d%d%d",&u,&v,&w) ;
            if( u == v && v == w && w == 0 ) break ;

            graph[u].emplace_back(v,w) ;
            graph[v].emplace_back(u,w) ;

        }

        int best  = minimum_spanning_tree(-1) ;
        int worst = minimum_spanning_tree(1) ;

        int ans = best + worst ;

        if(ans&1){
            printf("%d/2\n",ans);
        }
        else{
            printf("%d\n",ans/2) ;
        }

    }
};

int main(){

    int testcases = 1;
    scanf("%d",&testcases) ;
    for(int i = 1 ; i <= testcases ; i ++){
        printf("Case %d: ", i) ;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
