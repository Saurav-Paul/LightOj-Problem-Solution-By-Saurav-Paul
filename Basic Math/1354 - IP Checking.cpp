#include<bits/stdc++.h>
#define endl '\n'
#define ll unsigned long long int
using namespace std;
 
 ll bin (ll num){
 
    if(num==0){
       return 0;
    }
    else{
        return (num%2+10*(bin(num/2)));
    }
 
 
}
int main()
{
 
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a,b,c,d,A,B,C,D;
        char ch;
        cin>>a>>ch>>b>>ch>>c>>ch>>d;
        cin>>A>>ch>>B>>ch>>C>>ch>>D;
        bin(a);
        cout<<"Case "<<i<<": ";
        if(bin(a)!=A){
            cout<<"No";
        }
        else if(bin(b)!=B){
            cout<<"No";
        }
        else if(bin(c)!=C){
            cout<<"No";
        }
        else if(bin(d)!=D){
            cout<<"No";
        }
        else
            cout<<"Yes";
        cout<<endl;
 
    }
 
 
 
    return 0;
   }
 
