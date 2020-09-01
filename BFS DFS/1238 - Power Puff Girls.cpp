#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(a,b)             for(int i=a;i<=b;++i)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
using namespace std;
bool file=0,rt=1;
clock_t tStart ;
void FAST_IO();
////////////////////////
char grid[25][25];
bool isvisited[25][25];
ll level[25][25];
typedef pair<ll,ll> Pair ;
Pair pa ,pb , pc , ph;
ll bfs(ll x, ll y);
int main()
{

    FAST_IO();
    ////////////////////////
    ll cnt=0;
    tcase(){
        for(int i=0 ;i<25; i++)
            for(int j=0; j<25; j++)
                grid[i][j]='#';
        memset(isvisited,1,sizeof(isvisited));
        memset(level,0,sizeof(level));
        ll row, col ;
        cin>>row>>col;
        cout<<"Case "<<++cnt<<": ";
        for(int i=1;i<=row; i++){
            for(int j=1;j<=col ; j++){
                char c;
                cin>>c;
                if(c=='#' || c=='m')
                    continue ;
                grid[i][j]=c ;
                if(c=='a')
                    pa=make_pair(i,j);
                else if(c=='b')
                    pb=make_pair(i,j);
                else if(c=='c')
                    pc=make_pair(i,j);
                else if(c=='h')
                    ph=make_pair(i,j);
            }
            
        }

        cout<<bfs(ph.F,ph.S)<<endl;
    
    }


    ////////////////////////
    if(rt && file){
     printf("\nTime taken: %.6fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    }
    return 0;
   }

void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //cout.tie(NULL);
    //cout.setf(ios::fixed);
    //cout.precision(2);
    if(rt && file){ tStart = clock(); }
    if(file){
    #ifndef _offline
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    }
}

ll bfs(ll x, ll y){

    bool a=0, b=0 , c=0;
    level[x][y]=0;
    ll tx, ty;
    Pair pi;
    queue<Pair> Q;
    Q.push(make_pair(x,y));
    while(!Q.empty()){

        pi=Q.front();
        Q.pop();
        tx=pi.F;
        ty=pi.S;
        ll clevel=level[tx][ty];
        char ch=grid[tx][ty];
        if(ch=='a')
            a=1;
        if(ch=='b')
            b=1;
        if(ch=='c')
            c=1;
        if(a && b && c)
            break ;

        ch=grid[tx][ty+1];
        if(ch!='#' && level[tx][ty+1]==0){
            level[tx][ty+1]=clevel+1 ;
            Q.push(make_pair(tx,ty+1));
        }

        ch=grid[tx][ty-1];
        if(ch!='#' && level[tx][ty-1]==0){
            level[tx][ty-1]=clevel+1;
            Q.push(make_pair(tx,ty-1));
        }

        ch=grid[tx+1][ty];
        if(ch!='#' && level[tx+1][ty]==0){
            level[tx+1][ty]=clevel+1;
            Q.push(make_pair(tx+1,ty));
        }

        ch=grid[tx-1][ty];
        if(ch!='#' && level[tx-1][ty]==0){
            level[tx-1][ty]=clevel+1;
            Q.push(make_pair(tx-1,ty));
        }

    }
    return level[tx][ty];
}
