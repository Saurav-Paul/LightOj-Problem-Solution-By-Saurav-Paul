
/**
 *    author        : Saurav Paul 
 *    created       : July 30, 2020 2:47 PM
 *    Problem Name  : 1039 - A Toy Company
 *    Problem Limit : 2000 ms , 32 MB
 *    Problem Url   : http://lightoj.com/volume_showproblem.php?problem=1039
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

const int FORBIDDEN = -1 ;
const int VISITED = 1 ;
const int NOTVISITED = 0 ;
const int SZ = 26 ;
int vis[SZ][SZ][SZ] ;

inline int cti(char c){
    return int(c - 'a') ;
}

inline char itc(int x){
    return char(x+'a') ;
}

inline void rect(int &x){
    if(x<0) x =  25 ;
    else if(x>25) x = 0;
}

class point{
    public :
        int a , b , c, cnt ;
        point(int aa , int bb , int cc, int ccnt){
            a = aa , b = bb , c = cc ,cnt = ccnt;
        }

        void print(){
            cout << a << " " << b << " " << c <<" " << cnt << endl ;
        }
} ;

void solve(){

    string s , d;
    cin >> s >> d;
    memset(vis,NOTVISITED,sizeof vis) ;
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        string s1, s2 , s3 ;
        cin >> s1 >> s2 >> s3 ;
        for(auto a : s1){
            for(auto b : s2){
                for(auto c : s3){
                    vis[cti(a)][cti(b)][cti(c)] = FORBIDDEN ;
                }
            }
        }
    }
    int ans = 1e9 + 90 ;
    bool ok = false ;
    
    queue<point> Q ;

    point start(cti(s[0]),cti(s[1]),cti(s[2]),0) ;
    Q.push(start) ;

    auto add = [&](int aa,int ab ,int ac,int acnt){
        rect(aa) ;
        rect(ab) ;
        rect(ac) ;

        if(vis[aa][ab][ac] == FORBIDDEN) return ;

        point ptemp(aa,ab,ac,acnt) ;
        Q.push(ptemp) ;
    };

    while(!Q.empty()){
        point p = Q.front() ;
        Q.pop() ;

        if(vis[p.a][p.b][p.c] == FORBIDDEN) continue ;

        if(p.a==cti(d[0]) && p.b==cti(d[1]) && p.c==cti(d[2])){
            cout << p.cnt << endl ;
            return ;
        }
        if(vis[p.a][p.b][p.c] == VISITED) continue ;
        vis[p.a][p.b][p.c] = VISITED ;

        add(p.a+1,p.b,p.c,p.cnt+1) ;
        add(p.a-1,p.b,p.c,p.cnt+1) ;
        add(p.a,p.b+1,p.c,p.cnt+1) ;
        add(p.a,p.b-1,p.c,p.cnt+1) ;
        add(p.a,p.b,p.c+1,p.cnt+1) ;
        add(p.a,p.b,p.c-1,p.cnt+1) ;


    }

    cout <<-1<< endl ;

}

int main(){

    ios_base::sync_with_stdio(false);
    int testcase ;
    cin >> testcase ;

    for(int i = 1; i <= testcase ; i++){
        cout << "Case " << i << ": " ;
        solve() ;
    }


    return 0 ;
}
