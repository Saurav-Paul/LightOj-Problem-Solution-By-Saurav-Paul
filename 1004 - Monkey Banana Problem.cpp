#include<iostream>
using namespace std;
int ara[210][210];
int storemax[210][210];
int n,maxbanana;
void findmax(int i,int j);

int main()
{
    int t_case,casenum=0;
    cin>>t_case;
    while(t_case--)
    {
        int i,j;
        cin>>n;
        for(i=0; i<2*n-1; i++)
        {

            if(i<n)
                for( j=0; j<=i; j++)
                {
                    cin>>ara[i][j];

                }
            else
            {

                for(j=0; j<2*n-i-1; j++)
                {

                    cin>>ara[i][j];

                }
            }


 
        }
        i--;
        j--;

        storemax[i][j]=ara[i][j];
        findmax(i,j);
        cout<<"Case "<<++casenum<<": "<<storemax[0][0]<<endl;

        //printing all variable
        for(int i=0; i<2*n-1; i++)
        {

            for(int j=0; j<n; j++)
            {
                //cout<<ara[i][j]<<" ";
                storemax[i][j]=0;
                ara[i][j]=0;
            }
            //cout<<endl;

        }

    }

    return 0;
}
/*
void findmax(int row,int col)
{

    if(row<0)
        return ;
    if(row==0 && col==0)
    {
        return ;
    }
    if(row>=n)
    {

        int temp=ara[row-1][col]+storemax[row][col];
        if(temp>storemax[row-1][col])
            storemax[row-1][col]=temp;
        findmax(row-1,col);

        if(col+1<=row)
        {
            temp=ara[row-1][col+1]+storemax[row][col];
            if(temp>storemax[row-1][col+1])
                storemax[row-1][col+1]=temp;

            findmax(row-1,col+1);
        }
    }
    else
    {

        int temp=ara[row-1][col]+storemax[row][col];
        if(temp>storemax[row-1][col])
            storemax[row-1][col]=temp;
        findmax(row-1,col);

        if(col-1>=0)
        {
            temp=ara[row-1][col-1]+storemax[row][col];
            if(temp>storemax[row-1][col-1])
                storemax[row-1][col-1]=temp;

            findmax(row-1,col-1);
        }

    }

}
*/


void findmax(int row,int col)
{


    for(row=2*n-2; row>=0; row--)
    {

        for(int col=0; col<n; col++)
        {

            if(row>=n)
            {

                int temp=ara[row-1][col]+storemax[row][col];
                if(temp>storemax[row-1][col])
                    storemax[row-1][col]=temp;


                if(col+1<=row)
                {
                    temp=ara[row-1][col+1]+storemax[row][col];
                    if(temp>storemax[row-1][col+1])
                        storemax[row-1][col+1]=temp;


                }
            }
            else
            {

                int temp=ara[row-1][col]+storemax[row][col];
                if(temp>storemax[row-1][col])
                    storemax[row-1][col]=temp;


                if(col-1>=0)
                {
                    temp=ara[row-1][col-1]+storemax[row][col];
                    if(temp>storemax[row-1][col-1])
                        storemax[row-1][col-1]=temp;


                }

            }


        }


    }

}

