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
std::vector<ll> nodes[105];
ll cost[105][105];
ll l=0;
ll r=0;
bool isvisited[105][105];
void dfs(ll node){

    ll sz=nodes[node].size();
    for(int i=0; i<sz ; i++){
        ll temp=nodes[node][i];
        if(!isvisited[node][temp]){
            isvisited[node][temp]=1;
            isvisited[temp][node]=1;
            l+=cost[temp][node];
            r+=cost[node][temp];
            dfs(temp);
        }
    }
}
int main()
{

    FAST_IO();
    ////////////////////////
    ll cnt=0;
    tcase(){
        ll n;
        cin>>n;
        l=0;
        r=0;
        for(int i=0; i<=n ; i++)
            nodes[i].clear();
        memset(cost,0,sizeof(cost));
        memset(isvisited,0,sizeof(isvisited));
        for(int i=0; i<n ; i++){
            ll u, v , w;
            cin>>u>>v>>w;
            nodes[u].pb(v);
            cost[u][v]=0;
            nodes[v].pb(u);
            cost[v][u]=w;
        }
        for(int i=1; i<=n ; i++){
           
                dfs(i);
        }
        cout<<"Case "<<++cnt<<": ";
        cout<<min(l,r)<<endl;
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
