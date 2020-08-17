
/**
 *    author        : Saurav Paul 
 *    created       : August 18, 2020 12:13 AM
 *    Problem Name  : 1046 - Rider
 *    Problem Limit : 1000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1046
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;


using ll = long long int ;
int N , M ;
vector<string> grid ;
vector<pair<int,int>> riders ;
vector<vector<pair<int,int>>> value ;
vector<pair<int,int>> dimensions({{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}}) ;

bool check(int i , int j){
    if(i < 0 || i >= N) return false ;
    if(j < 0 || j >= M) return false ;
    return true ;
}

class prop{
    public :
        int x, y, k, mv ;

        prop(int a , int b , int c, int d){
            x = a , y = b , k = c , mv = d; 
        }
        void update(int a , int b , int c, int d){
            x = a , y = b , k = c , mv = d; 
        }
        
};

void bfs(pair<int,int> rider){
    // bfs initializing
    int i = rider.first , j = rider.second ;
    int rider_k = grid[i][j] - '0' ;

    bool vis[N+1][M+1] = {} ;
    queue<prop> Q ;

    prop temp(i,j,rider_k+1,1) ;
    Q.push(temp) ;

    while(!Q.empty()){
        temp = Q.front() ;
        Q.pop() ;

        int x = temp.x , y = temp.y , k = temp.k , mv = temp.mv;

        if(vis[x][y]){
            continue ;
        }
        vis[x][y] = true ;

        if(k == 0){
            mv ++ ;
            k = rider_k ;
        }
        
        // updating value array
        value[x][y].first ++ ;
        if(x != i || y != j)
            value[x][y].second += mv ;

        for(auto d : dimensions){
            int nx = x + d.first , ny = y + d.second ;

            if(check(nx,ny)){
                temp.update(nx,ny,k-1,mv) ;
                Q.push(temp) ;
            }
        }

    }
}

void solve(){

    cin >> N >> M ;

    grid = vector<string> (N) ;
    riders = vector<pair<int,int>> () ;
    value = vector<vector<pair<int,int>>> (N,vector<pair<int,int>>(M)) ;
    for(int i = 0; i < N ;i++){
        cin >> grid[i] ;
    }

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            if((grid[i][j] - '0') > 0){
                riders.push_back({i,j}) ;
            }
        }
    }

    // bfs to every rider to find every possible position they can get using minimum cost
    for(auto x : riders){
        bfs(x) ;
    }

    int answer = -1 ;

    // getting the answer 
    int total = riders.size() ;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            if(value[i][j].first == total){
                if(answer == -1){
                    answer = value[i][j].second ;
                }
                else{
                    answer = min(answer,value[i][j].second) ;
                }
            }
        }
    }

    cout << answer << endl ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        cout << "Case "<<i << ": " ;
        solve();
    }

    return 0 ;
}
