#include<iostream>
using namespace std;
char lands[21][21];
int isvisited[21][21];
int tcase, w,h;
int x,y;
int cnt=0;
int case_no=1;
void checkland(int px,int py);
int main()
{

    cin>>tcase;
    while(tcase--)
    {
        cin>>w>>h;
        for(int i=0; i<h; i++)
        {

            for(int j=0; j<w; j++)
            {

                cin>>lands[i][j];
                if(lands[i][j]=='@')
                {
                    x=j; 
                    y=i;
                }

            }


        }
        // cout<<"10 3="<<lands[10][3]<<endl;
        checkland(y,x);
        cout<<"Case "<<case_no++<<": "<<cnt<<endl;
        cnt=0;



        for(int i=0; i<h; i++)
        {

            for(int j=0; j<w; j++)
            {

                lands[i][j]='#';
                isvisited[i][j]=0;

            }
        }


    }

    return 0;
}
void checkland(int px,int py)
{
    if(px<0 || py<0 || px==h || py==w)
        return ;
    cnt++;

    isvisited[px][py]=1;
    if(lands[px+1][py]=='.' &&isvisited[px+1][py]==0 )
        checkland(px+1,py);

    if(lands[px-1][py]=='.' &&isvisited[px-1][py]==0)
        checkland(px-1,py);

    if(lands[px][py+1]=='.' &&isvisited[px][py+1]==0)
        checkland(px,py+1);

    if(lands[px][py-1]=='.' &&isvisited[px][py-1]==0)
        checkland(px,py-1);

}
