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
using namespace std;
bool file=0,rt=0;
clock_t tStart ;
void FAST_IO();
////////////////////////
double ara[1000003];
int main()
{
 
    FAST_IO();
    ////////////////////////
    ll cnt=0;
    tcase(){
        ll tnum;
        cin>>tnum;
        ll min=INT_MAX;
        ll max=0;
        memset(ara,0,sizeof(ara));
        cout<<"Case "<<++cnt<<": ";
        for(int i=0;i<tnum;i++){
            ll temp;
            cin>>temp;
            temp++;
            ara[temp]++;
            if(temp>max)
                max=temp;
            if(temp<min)
                min=temp;
           
        }
        ll ans=0;
        for(int i=min;i<=max;i++){
            if(ara[i]){
                ll temp=(ceil(ara[i]/i))*i;
                ans+=temp;
               // cout<<"-> "<<ans<<" "<<i<<endl;  
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
 
