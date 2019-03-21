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
bool file=1,rt=0;
clock_t tStart ;
void FAST_IO();
////////////////////////

std::vector<Pair> nodes[300005];
ll maxNode = 0;
void bfs(ll node, ll mem[]){

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

    // FAST_IO();
    ////////////////////////
    ll cnt=0;
    ll tcase;
    cin>>tcase;
    while(tcase--){
        cout<<"Case "<<++cnt<<":"<<endl;
    ll node;
    cin>>node;
    for(int i=0; i<=node ; i++){
        nodes[i].clear();
    }
    for(int i=1; i< node; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        nodes[u].pb(make_pair(v,w));
        nodes[v].pb(make_pair(u,w));
    }
    //bfs calling
        ll dist1[300005];
        ll dist2[300005];
        memset(dist1,-1,sizeof(dist1));
        memset(dist2,-1,sizeof(dist2));
        bfs(0,dist1);
        memset(dist1,-1,sizeof(dist1));
        bfs(maxNode,dist1);
        bfs(maxNode,dist2);
        for(int i=0 ; i< node ; i++)
            cout<<max(dist1[i],dist2[i])<<endl;
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
