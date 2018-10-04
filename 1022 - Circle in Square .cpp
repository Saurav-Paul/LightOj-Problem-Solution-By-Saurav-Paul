#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define PI 2*acos(0.0)
int main(){

int tcase, caseno =1;
cin>>tcase;
while(tcase--){
    cout<<"Case "<<caseno++<<": ";
    double r,ans;
    scanf("%lf",&r);
    ans=((2.0*r)*(2.0*r))-(PI*r*r);
    printf("%.2lf\n",ans);
}
return 0;
}
