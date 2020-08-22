
/**
 *    author        : Saurav Paul 
 *    created       : August 23, 2020 12:09 AM
 *    Problem Name  : 1377 - Blade and Sword
 *    Problem Limit : 3000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1377
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

vector<string> grid ;
int N , M ;
pair<int,int> start , destination ;
vector<pair<int,int>> direction = {{0,1},{1,0},{0,-1},{-1,0}} ;
const int INF = 1e6 + 90 ;
int answer ;

class Prop{
    public :
        int x , y , cost ;

        void update(int a, int b , int c){
            x = a , y = b , cost = c ;
        }
}curr, temp;

vector<Prop> P_star, D_star ;

void bfs(bool from_start){

    queue<Prop> Q ;

    char target = 'D' ;

    if(from_start){
        temp.update(start.first,start.second, 0) ;
    }
    else{
        temp.update(destination.first,destination.second, 0) ;
        target = 'P' ;
    }
    Q.push(temp) ;

    bool vis[N+10][M+10] = {} ;

    auto check = [&](){
        int x = temp.x , y = temp.y ;
        if(x < 0 || y < 0) return false ;
        if(x >= N || y >= M) return false ;
        if(grid[x][y] == '#') return false ;
        return true ;
    };

    while(!Q.empty()){
        curr = Q.front() ;
        Q.pop() ;

        if(grid[curr.x][curr.y] == target){
            answer = min(answer, curr.cost) ;
            break ;
        }

        if(grid[curr.x][curr.y] == '*'){
            if(from_start){
                P_star.push_back(curr) ;
            }
            else{
                D_star.push_back(curr) ;
            }
            /* curr.cost += 1; */
            continue ;
        }


        for(auto d : direction){
            temp.update(curr.x+d.first,curr.y+d.second, curr.cost+1) ;
            if(check()){
                if(vis[temp.x][temp.y] == true) continue ;
                vis[temp.x][temp.y] = true ;
                Q.push(temp) ;
            }
        }
        
    }

}

void solve(){
    cin >> N >> M ;
    grid = vector<string>(N) ;
    answer = INF ;
    bool a , b;
    a = b = false ;
    P_star.clear() ;
    D_star.clear() ;

    int total_star = 0 ;
    for(int i = 0 ; i < N ; i++){
        cin >> grid[i] ;
        for(int j = 0 ; j < M ; j++){
            if(grid[i][j] == 'P')
                start = make_pair(i,j), a = true ;
            else if( grid[i][j] == 'D' )
                destination = make_pair(i,j) , b = true;
            else if(grid[i][j] == '*') total_star ++ ;
        }
    }

    if(!(a && b)) {
        cout << "impossible" << endl ;
        return ;
    }

    bfs(true) ;
    bfs(false) ;

    for(auto x : P_star){
        for(auto y : D_star){
            if(x.x == y.x && x.y == y.y){
                if(total_star > 1){
                    answer = min(answer, x.cost+y.cost+2) ;
                }
                continue ;
            }
            else
                answer = min(answer, x.cost+y.cost+1) ;
        }
    }

    if(answer == INF) cout << "impossible" << endl ;
    else cout << answer << endl ;

}

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        cout << "Case " << i << ": " ;
        solve();
    }

    return 0 ;
}
