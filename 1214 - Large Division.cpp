#include<bits/stdc++.h>
#define endl '\n'
#define ll  long long int
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
bool division (string a, ll b){
    ll temp=0;
    ll sz=a.size();
    if(a[0]=='-')
        a[0]='0';
    for(ll i=0;i<sz;i++)
        temp=( (temp*10) + (a[i]-'0') )%b;
   
    if(temp)
        return 1;
    else
        return 0;
}
int main()
{
 
    FAST_IO();
    ////////////////////////
    ll cnt=0;
    tcase(){
        string a;
        ll b;
        cin>>a>>b;
       
        cout<<"Case "<<++cnt<<": ";
        if(!division(a,b))
            cout<<"divisible"<<endl;
        else
            cout<<"not divisible"<<endl;
 
 
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
 
