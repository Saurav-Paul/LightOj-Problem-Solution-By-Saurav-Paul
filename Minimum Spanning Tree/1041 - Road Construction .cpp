
/**
 *    author        : Saurav-Paul 
 *    created       : September 18, 2020 11:25 PM
 *    Problem Name  : 1041 - Road Construction
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1041
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    static const int nax = 55 ;
    map<string,int> index ;
    vector<bool> taken ;
    int N , cost = 0, counter = 0;
    vector<pair<int,int>> graph[nax];

    void MST(int mul=-1){
        taken.assign(counter+1,false) ;

        priority_queue<pair<int,int>> PQ ;
        PQ.push({0,1});

        while(!PQ.empty()){
            pair<int,int> curr = PQ.top() ;
            PQ.pop() ;

            int node = curr.second ;
            if(taken[node]) continue ;

            cost += (curr.first * mul) ;
            taken[node] = true;

            for(auto to : graph[node]){
                if(taken[to.first] == false){
                    PQ.push({to.second*mul,to.first}) ;
                }
            }
        }

    }

    public :
    void solve(){
        cin >> N ;

        for(int i = 1; i <= N ; i++){
            string u , v ;
            int w ;
            cin >> u >> v >> w;
            int id1 = id(u);
            int id2 = id(v) ;
            graph[id1].emplace_back(id2,w) ;
            graph[id2].emplace_back(id1,w) ;
        }
        MST() ;

        bool ok = true ;

        for(int i = 1 ; i <= counter ; i++){
            if(taken[i] == false){
                ok = false ;
                break ;
            }
        }

        if(ok) cout << cost << endl ;
        else cout << "Impossible" << endl ;

    }

    int id(string s){
        if(index[s] == 0){
            counter ++ ;
            index[s] = counter ;
            return counter ;
        }
        return index[s] ;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    int testcase ;
    cin >> testcase ;

    for(int i = 1 ; i <= testcase ; i++){
        cout << "Case " << i <<": " ;
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
