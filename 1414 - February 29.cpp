#include<bits/stdc++.h>
#define endl '\n'
#define _time_ clock_t tStart = clock();
#define _show_ printf("Time taken: %.6fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
#define ll long long int
#define loop(a,b)           for(int i=a;i<=b;++i)
#define count_1(n)            __builtin_popcountll(n)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define sv()                  ll t,n; scanf("%lld",&t);n=t; while(t--)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);

using namespace std;
void FAST_IO();

int main()
{
   // _time_
   //FAST_IO();
   
   ll tcase,x,y;
   cin>>tcase;
   ll cnt=1;
   while(tcase--){
   string month1,month2;
   ll st,sp,day1,day2;
   char c;
   cin>>month1>>day1>>c>>st;
   cin>>month2>>day2>>c>>sp;
   st--;
   cout<<"Case "<<cnt++<<": ";
   ll st4,st100,st400,sp4,sp100,sp400;
   st4=st/4;
   st100=st/100;
   st400=st/400;
   st++;
   sp4=sp/4;
   sp100=sp/100;
   sp400=sp/400;

   ll c4=sp4-st4;
   ll c100=sp100-st100;
   ll c400=sp400-st400;

   ll notLeapyear=c100-c400;
   ll leapYear=c4-notLeapyear;
   
   if( (st%400==0) || (st%4==0 && st%100!=0)){
    
    if(month1=="January"  || month1=="February"){
        ;
    }
    else{
        leapYear--;
    }

   }
if( (sp%400==0) || (sp%4==0 && sp%100!=0)){
    
    if(month2=="January"  || month2=="February"){
        
        if(month2=="February" && day2<29 )
            leapYear--;
        else if(month2=="January")
            leapYear--;

    }
    
   }



   cout<<leapYear<<endl;
   }

    //_show_
    return 0;
   }

void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //cout.setf(ios::fixed);
    //cout.precision(2);
#ifndef _offline
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
