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
#define SZ(x)                 (x).size()
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
using namespace std;
typedef pair<ll,ll>Pair;
bool file=0,rt=0;
clock_t tStart ;
void FAST_IO();
////////////////////////
std::vector<ll> cities[1005],person;
ll mem[1005];
bool isvisited[1005];
void bfs(ll node){
    queue<ll>q;
    q.push(node);
    memset(isvisited,0,sizeof(isvisited));
    isvisited[node]=1;
    while(!q.empty()){
            ll temp = q.front();
            q.pop();
            mem[temp]++;
            ll sz=cities[temp].size();
            for(int i=0; i< sz ; i++){
                ll t=cities[temp][i];
                if(isvisited[t]==0){
                    q.push(t);
                    isvisited[t]=1;

                }
            }
    }

}
int main()
{

    FAST_IO();
    ////////////////////////
    ll tcase, K,N,M,cnt=0,temp;
    cin>>tcase;
    while(tcase--){
        memset(mem,0,sizeof(mem));
        person.clear();
        cin>>K>>N>>M;
        cout<<"Case "<<++cnt<<": ";
        for(int i=0; i<= N ; i++)
            cities[i].clear();

        for(int i=0; i< K ; i++){
            cin>>temp;
            person.pb(temp);
        }
        for(int i=0; i< M; i++){
            ll a, b;
            cin>> a >> b;
            cities[a].pb(b);
        }
        for(int i=0; i< K ; i++){
            ll p=person[i];
            bfs(p);
        }
        ll cnt=0;
        for(int i=0; i<=N ; i++){
            if(mem[i]>=K)
                cnt++;
        }
        cout<<cnt<<endl;
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
