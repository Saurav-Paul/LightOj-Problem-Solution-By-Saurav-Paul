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
bool file=0,rt=0;
clock_t tStart ;
void FAST_IO();
////////////////////////
std::vector<ll> graph[20003];
bool isvisited[20003];
bool color[2000005];
ll edge , u ,v ;
queue<ll> Q ;
ll bfs(ll root);
int main()
{

    FAST_IO();
    ////////////////////////
    ll cnt=0;
    ll tcase;
    cin>>tcase;
    while(tcase--){
        memset(isvisited,0,sizeof(isvisited));
        memset(graph,0,sizeof(graph));
        memset(color,0,sizeof(color));
        cin>>edge ;
        ll node=0;
        cout<<"Case "<<++cnt<<": ";
        for(int i=0; i < edge ; i++){
            cin>>u>>v;
            graph[u].pb(v);
            graph[v].pb(u);
            node=max(u,node);
            node=max(v,node);

        }
        ll ans=0;
        for( int i=1 ; i<=node ; i++){
            if(isvisited[i]==0){
                ans+=(bfs(i));
                
            }

        }
        
        cout<<ans<<endl;

    }

    ////////////////////////
    if(rt && file){
     printf("\nTime taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
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

ll bfs(ll root){
    if(graph[root].size()==0)
        return 0;

    color[root]=1;
    ll tvamp=1 , tvy= 0;

    isvisited[root]=1;
    Q.push(root); 
    while( !Q.empty()){
        ll temp =0 ;
        ll t= Q.front();
        
        
        Q.pop();
        
        ll sz=graph[t].size();
        for(int i=0 ; i<sz ; i++){
            ll node= graph[t][i];
            if(isvisited[node]==0){
                isvisited[node]=1;
               
                if(color[t]==1){
                    tvy++;
                    color[node]=0;
                }
                else{
                    tvamp++;
                    color[node]=1;
                }
                Q.push(node);
            }

        }

    }
    return max(tvamp,tvy);

}
