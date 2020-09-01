#include<stdio.h>
int main(){
long long int a,b,c,d,e,f,caseno=1,cases,n;
long long int ara[10000];
scanf("%lld",&cases);
while(cases--){
    scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
    ara[0]=a;
    ara[1]=b;
    ara[2]=c;
    ara[3]=d;
    ara[4]=e;
    ara[5]=f;
    for(int i=6;i<=n;i++){
        ara[i]=(ara[i-1]+ara[i-2]+ara[i-3]+ara[i-4]+ara[i-5]+ara[i-6])%10000007;
    }
     printf("Case %lld: %lld\n", caseno++, ara[n] % 10000007);
}
return 0;
}
 
