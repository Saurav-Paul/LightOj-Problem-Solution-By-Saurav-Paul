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
const ll INF = 2e18 + 99;
typedef pair<ll,ll> Pair;
typedef vector<ll> vll;
bool file=0,rt=0;
clock_t tStart ;
void FAST_IO();
////////////////////////
void build_tree(vll &tree , vll &ara, ll st, ll en, ll at){
    if(st>=en){
        tree[at]=ara[st];
        return ;
    }
    ll mid= (en+st)/2;
    build_tree(tree,ara,st,mid,2*at+1);
    build_tree(tree,ara,mid+1,en,2*at+2);
    tree[at]=min(tree[2*at+1],tree[2*at+2]);

}
ll tree_query(vll &tree , ll l , ll r, ll at, ll L , ll R){
   ;
    if(r<L || l>R){
        return INT_MAX ;
    }
    if(L>=l && R<=r){
        return tree[at];
    }
    ll mid=(L+R)/2;
    ll x=tree_query(tree, l,r, 2*at+1,L,mid);
    ll y=tree_query(tree,l,r, 2*at+2,mid+1,R);
    return min(x,y) ;
}
int main()
{

    FAST_IO();
    ////////////////////////
    ll tcase,cnt=0; scanf("%lld", &tcase);
    while(tcase--){

        ll n, q; scanf("%lld%lld", &n, &q);
        vll ara, tree(4*n,0); 
     
  
        for(int i=0,temp ; i<n ; i++) {

            scanf("%d", &temp);
            ara.pb(temp);
        }
        build_tree(tree,ara , 0, n-1,0);
        printf("Case %lld:", ++cnt);
        printf("\n");
        while(q--){
            ll l,r; scanf("%lld%lld", &l, &r);
            printf("%lld", tree_query(tree,l-1,r-1,0,0,n-1));
            printf("\n");

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
   // ios_base::sync_with_stdio(0);
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
