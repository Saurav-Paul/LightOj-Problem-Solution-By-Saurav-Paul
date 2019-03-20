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
bool isPrime[1200];
bool check[1200];
std::vector<int> factor[1001];
bool flag=false;
ll n;
int mem[1500][1500];
void sieve(ll n){
   isPrime[2]=1;
    for(int i=4; i<=n ; i+=2)
        check[i]=1;
    for(int i=3; i<=n ; i+=2){
        if(!check[i]){
            isPrime[i]=1;
            for(int j=i*i ; j<=n ; j+=i){
                check[j]=1;
            }
        }
    }
 
}
void find_factor(ll n){
    for(int i=2; i<n ;i++){
        if(n%i==0 && isPrime[i]){
            factor[n].pb(i);
        }
    }
 
}
ll find_ans(ll a, ll b){
 
    ll temp=INT_MAX;
   
    if(a==b){
        flag=true ;
       
        return 0;
    }
    if(a>b){
        return INT_MAX;
    }
    if(mem[a][b]!=-1)
        return mem[a][b];
    ll sz=factor[a].size();
    if(sz==0){
        find_factor(a);
        sz=factor[a].size();
    }
    for(int i=0; i< sz ; i++){
        // cout<<a<<" "<<a+factor[a][i]<<endl;
        temp=min(temp,find_ans(a+factor[a][i],b)+1);
    }
 
    return mem[a][b]=temp;
}
int main()
{
 
    FAST_IO();
    ////////////////////////
    sieve(1200);
    ll tcase,cnt=0;
    cin>>tcase;
    while(tcase--){
        flag=false;
        memset(mem, -1 , sizeof(mem));
    ll b;
    cin>>n>>b;
    cout<<"Case "<<++cnt<<": ";
    if(b<n){
        cout<<-1<<endl;
        continue;
    }
   
    find_factor(n);
   
    ll ans=find_ans(n,b);
    if(flag)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
 
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
 
