                /*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
  
void solve(){
    int n , k ; scanf("%d%d",&n,&k);
    k ++ , n ++;
    int low = 0 , high = 0 , mx = 0;
    vector<int> hill(n), t;
    for(int i = 0 ; i < n; i++) scanf("%d",&hill[i] ), high+=hill[i] ;
   
    while(low < high){
        int mid = low + ((high-low) >> 1 ) ;
        t.clear();
        int temp = 0 ;
        bool ok = false;
        int tmx = 0;
        for(int i = 0 ; i <= n; i++){
            if(i==n){
                t.emplace_back(temp);
                tmx = max(tmx,temp);
            }
            else{
               
                if(temp + hill[i] > mid){
                    t.emplace_back(temp);
                    tmx = max(tmx,temp);
                    temp = 0;
                }
               
                temp += hill[i];
            }
           
        }
        ok = ((int)t.size() <= k ) ;
        if(ok)
            high = mid , mx = tmx;
        else
            low = mid+1;
    }
    printf("%d\n",mx);
    
    int temp = 0;
    for(int i = 0 ; i <= n; i ++){
        if(i==n){
            printf("%d\n",temp);
            break ;
        }
        if(k-1==n-i)
            printf("%d\n",temp),temp=0,k--;
        else{
            if(temp + hill[i] > mx){
                printf("%d\n",temp);
                temp = 0;
                k--;
            }
        }
        temp += hill[i];
    }
   
}
int main()
{
   
    int t ; scanf("%d",&t);
    for(int i = 1 ; i <= t ; i++){
        printf("Case %d: ",i);
        solve();
    }

    return 0;
}
