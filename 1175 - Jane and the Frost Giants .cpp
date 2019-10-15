
				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

using pii = pair<int,int >;

#define jane 1
#define frost 2

void solve() {

    int n, m ;
    scanf("%d%d",&n,&m);
    char grid[n+1][m+1];

    for(int i = 0 ; i< n ; i++){
        scanf("%s",grid[i]) ;
    }
    pii J , F ;
    vector<pii> F_all ;
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j]=='J'){
                J = {i,j};
            }
            else if(grid[i][j]=='F'){
                F_all.emplace_back(i,j);
            }
        }
    }
    vector< vector<int> > occupied(n+1 , vector<int> (m+1 ));
    vector< vector<int> > cnt(n+1 , vector<int> (m+1 ));
    queue<pii> Q ;
    for(auto F : F_all){
       Q.push(F);
       occupied[F.first][F.second] = frost;
    }

    Q.push(J);
    occupied[J.first][J.second] = jane;
    cnt[J.first][J.second] = 1;
    bool ok = false ;
    int ans = 0;
    while(!Q.empty()){
        pii x = Q.front() ;
        Q.pop() ;


        if(x.first == 0 or x.first == n-1 or x.second == 0 or x.second == m-1){
            if(occupied[x.first][x.second]==jane and grid[x.first][x.second]=='.' or
                grid[x.first][x.second]=='J'){
                ok = true ;
                ans = cnt[x.first][x.second];
                break ;
            }
        }
        int curr = (occupied[x.first][x.second]==jane? jane : frost) ;

        int xx = x.first , yy = x.second ;
        if(curr==jane){

            int have = cnt[xx][yy] + 1;
            if(xx > 0 and grid[xx-1][yy] == '.' and occupied[xx-1][yy]==0){
                occupied[xx-1][yy] = curr ;
                cnt[xx-1][yy] = have ;
                Q.push({xx-1,yy});
            }
            if(yy > 0 and grid[xx][yy-1] == '.' and occupied[xx][yy-1]==0){
                occupied[xx][yy-1] = curr ;
                cnt[xx][yy-1] = have ;
                Q.push({xx,yy-1});
            }
            if(xx < n-1 and grid[xx+1][yy] == '.' and occupied[xx+1][yy]==0){
                occupied[xx+1][yy] = curr ;
                cnt[xx+1][yy] = have ;
                Q.push({xx+1,yy});
            }
            if(yy < m-1 and grid[xx][yy+1] == '.' and occupied[xx][yy+1]==0){
                occupied[xx][yy+1] = curr ;
                cnt[xx][yy+1] = have ;
                Q.push({xx,yy+1});
            }


        }
        else if(curr==frost){

            if(xx > 0 and grid[xx-1][yy] == '.' and occupied[xx-1][yy] ==0){
                occupied[xx-1][yy] = curr ;
                Q.push({xx-1,yy});
            }
            if(yy > 0 and grid[xx][yy-1] == '.' and occupied[xx][yy-1]==0){
                occupied[xx][yy-1] = curr ;
                Q.push({xx,yy-1});
            }
            if(xx < n-1 and grid[xx+1][yy] == '.' and occupied[xx+1][yy]==0){
                occupied[xx+1][yy] = curr ;
                Q.push({xx+1,yy});
            }
            if(yy < m-1 and grid[xx][yy+1] == '.' and occupied[xx][yy+1]==0){
                occupied[xx][yy+1] = curr ;
                Q.push({xx,yy+1});
            }


        }
        else assert(false) ;


    }

    if(ok){
        printf("%d\n",ans);
    }
    else puts("IMPOSSIBLE");
}

int main()
{

    int testcase ;
    scanf("%d",&testcase);
    for(int t = 1; t <= testcase ; t++){
        printf("Case %d: ",t);
        solve() ;
    }
    return 0;
}
