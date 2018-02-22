#include<iostream>
using namespace std;
int main(){
int tcase,n;
cin>>tcase;
while(tcase--){
        cin>>n;
 if(n<11){
    cout<<"0 "<<n<<endl;
 }
else
    cout<<n-10<<" "<<10<<endl;
}
return 0;
}
