#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void permutation(string text,int left,int right);
int main()
{
    int tcase,caseno=1;
    cin>>tcase;
    while(tcase--)
    {
        int total;
        int maxi;
        cin>>total>>maxi;

        string text;
        char c='A';
        for(int i=0; i<total; i++)
            text.push_back(c+i);
        cout<<"Case "<<caseno++<<":"<<endl;
        while(maxi--){
                cout<<text<<endl;
         if(!next_permutation(text.begin(),text.end()))
            break;
        }
    }

    return 0;
}
