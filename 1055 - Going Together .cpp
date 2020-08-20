
/**
 *    author        : Saurav Paul 
 *    created       : August 20, 2020 12:08 AM
 *    Problem Name  : 1055 - Going Together
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1055
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class Status{
    public :
        vector<pair<int,int>> robo_pos ;
        int cost = 0;

        void update(vector<pair<int,int>> &a , int b){
            robo_pos = a , cost = b ;
        }

};

class TC{
  public :

      static const int nax = 12 ;
      int N ;
      vector<string> grid ;
      vector<pair<int,int>> target_cell ;
      vector<pair<int,int>> directions{{0,1}, {1,0},{0,-1}, {-1,0}} ;
      int answer = -1 ;

      Status curr, prv ;

      bool vis[nax+1][nax+1][nax+1][nax+1][nax+1][nax+1] = {} ;

      void bfs(vector<pair<int,int>> robot_initial){
          queue<Status> Q;

          curr.update(robot_initial,0) ;

          check(robot_initial) ;
          Q.push(curr) ;

          while(!Q.empty()){
              prv = Q.front() ;
              Q.pop() ;

              if(reached_target(prv.robo_pos)){
                  answer = prv.cost ;
                  break ;
              }

              for(auto d : directions){
                  curr = prv ;
                  for(auto &robot : curr.robo_pos){
                      update(robot,d) ;
                  }
                  adjust_the_positions();

                  if(check(curr.robo_pos)){
                      curr.cost ++ ;
                      Q.push(curr) ;
                  }
              }

          }
      }

      void adjust_the_positions(){

          for(int i = 0 ; i < 3 ; i++){
              int nx = curr.robo_pos[i].first ;
              int ny = curr.robo_pos[i].second ;

              if(nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == '#'){
                  curr.robo_pos[i] = prv.robo_pos[i] ;
              }
          }

          for(int no = 0 ; no < 3 ; no++){
              for(int i = 0 ; i < 3 ; i++){
                  for(int j = 0 ; j < 3 ; j++){
                      if(i == j) continue ;

                      // need to check if they conflict with each other...
                      if(curr.robo_pos[i] == curr.robo_pos[j]){
                          curr.robo_pos[j] = prv.robo_pos[j] ;

                      }

                  }
              }
          }

      }

      bool reached_target(vector<pair<int,int>> &v){

          for(auto x : v){
              if(grid[x.first][x.second]  != 'X') return false ;
          }

          return true ;

      }

      bool check(vector<pair<int,int>> &v){
          int x1 = v[0].first , x2 = v[1].first , x3 = v[2].first ;
          int y1 = v[0].second , y2 = v[1].second , y3 = v[2].second ;

          if(vis[x1][y1][x2][y2][x3][y3]){
              return false ;
          }
          return vis[x1][y1][x2][y2][x3][y3] = true ;
      }

      void update(pair<int,int> &p , pair<int,int> x){
            
          int nx = p.first + x.first ;
          int ny = p.second + x.second ;

          p = make_pair(nx,ny) ;
      }

      void solve(){
            cin >> N ;

            for(int i = 0 ; i < N ; i++){
                string s;
                cin >> s;
                grid.push_back(s) ;
            }

            vector<pair<int,int>> robot_cell ;
            for(int i = 0 ; i < N ;i++){
                for(int j = 0 ; j < N ; j++){
                    char c = grid[i][j] ;
                    if(c == 'X'){
                        target_cell.push_back(make_pair(i,j)) ;
                    }
                    else if(c == 'A' || c == 'B' || c == 'C'){
                        robot_cell.push_back(make_pair(i,j)) ;
                    }
                }
            }

            bfs(robot_cell) ;

            if(~answer) cout << answer << endl ;
            else cout << "trapped" << endl ;

      }

};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;

    for(int i = 1 ; i <= testcases ; i ++){
        cout << "Case "<<i<<": " ;
        TC x ;
        x.solve();
    }

    return 0 ;
}
