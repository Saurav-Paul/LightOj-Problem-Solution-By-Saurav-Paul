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
std::vector<Pair> nodes[30005];
ll mem[30005];
ll maxNode = 0;
Pair p;
void bfs(ll node){

    queue<ll> q;
    q.push(node);
    mem[node]=0;
    while(!q.empty()){
        ll  tnode= q.front();
        q.pop();
        ll sz=nodes[tnode].size();
        for(int i=0 ; i< sz ; i++){
            ll tn= nodes[tnode][i].F;
            ll tw= nodes[tnode][i].S;

            if(mem[tn]==-1){
                mem[tn]=mem[tnode]+tw;

                if(mem[tn]>=mem[maxNode])
                    maxNode=tn;
                q.push(tn);
            }
        }
    }

}
int main()
{

    FAST_IO();
    ////////////////////////
    ll tcase,n,temp;
    cin>>tcase;
    ll cnt=0;
    while(tcase--){
        cin>>n;
        for(int i=0 ; i<=n ; i++)
            nodes[i].clear();
        for(int i=0; i< n-1 ; i++){
            ll a , b, w;
            cin>>a>>b>>w;
            nodes[a].pb(make_pair(b,w));
            nodes[b].pb(make_pair(a,w));
        }

        cout<<"Case "<<++cnt<<": ";
        memset(mem,-1,sizeof(mem));
        maxNode=0;
        bfs(maxNode);

        memset(mem,-1,sizeof(mem));
        bfs(maxNode);
        cout<<mem[maxNode]<<endl;
        for(int i=0 ; i<=n ; i++)
            nodes[i].clear();
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
