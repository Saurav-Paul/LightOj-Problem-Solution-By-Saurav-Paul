#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vl                    vector<ll>
#define SZ(x)                 (x).size()
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
using namespace std;
typedef pair<ll,ll> Pair;
bool file=0,rt=0;
clock_t tStart ;
void FAST_IO();
////////////////////////
char grid[505][505];
bool isvisited[505][505];
ll mem[505][505];
ll row,col,m;
ll ans=0;
ll knt[1005];
ll dfs(ll x, ll y,ll tcnt){
    ll temp=0;
    if(isvisited[x][y])
        return 0;
 
    isvisited[x][y]=1;

    if(mem[x][y]!=-1)
        return knt[mem[x][y]];

    if(grid[x][y]=='C')
       temp++;
    if(grid[x][y]=='#')
        return 0;
    temp+=dfs(x,y+1 , tcnt);
    temp+=dfs(x,y-1, tcnt);
    temp+=dfs(x+1,y, tcnt);
    temp+=dfs(x-1,y, tcnt);
    mem[x][y]=tcnt;
    return temp;
}
int main()
{
 
    FAST_IO();
    ////////////////////////
    ll cnt=0;
    tcase(){
        cout<<"Case "<<++cnt<<":"<<endl;
        cin>>row>>col>>m;
        for(int i=0; i<row+5;i++)
            for(int j=0; j<col+5;j++)
                grid[i][j]='#';
 
        for(int i=1; i<=row ; i++){
            for(int j=1; j<=col ; j++){
                cin>>grid[i][j];
            }
        }
        memset(mem,-1,sizeof(mem));
        memset(knt,0,sizeof(knt));
        ll tcnt=0;
        while(m--){
            ll x, y;
            ans=0;
            cin>>x>>y;
            memset(isvisited,0,sizeof(isvisited));
            ans=dfs(x,y,tcnt++);
            knt[tcnt-1]=ans;
            cout<<ans<<endl;
        }
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
    // cin.tie(NULL);
    // cout.tie(NULL);
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
 
