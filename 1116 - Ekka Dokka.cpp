#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long int
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //cout.tie(NULL);
    ll n;
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        ll num;
        cin>>num;
        ll m,n;
        ll x,y;
        bool flag=0,flg=0;
        double t=sqrt(num);
        ll root=t+1;
        cout<<"Case "<<cnt++<<": ";
        if(num&1)
        {
 
            ;
        }
        else
        for(int i=2;i<=root;i++){
            if(num%i==0){
                ll temp=num/i;
                if(temp%2==1 && i%2==0){
                    m=i;
                    n=temp;
                    flag=1;
                    break;
                }
                if(temp%2==0 && i%2==1){
                    x=i;
                    y=temp;
                    flg=1;;
 
                }
 
            }
        }
        if(flag)
            cout<<n<<" "<<m<<endl;
        else if(flg)
            cout<<x<<" "<<y<<endl;
        else
            cout<<"Impossible"<<endl;
 
    }
 
 
 
    return 0;
   }
 
