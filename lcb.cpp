#include<iostream>
using namespace std;
void lcb(string a, string b)
{
    int lena = a.length();
    int lenb = b.length();
    int arr[lena+1][lenb+1],brr[lena+1][lenb+1];
    int i,j;
    for(i=0;i<lena+1;i++)
    {
        arr[i][0]=0;
        brr[i][0]=0;

    }
    for(i=0;i<lenb+1;i++)
    {
        arr[0][i]=0;
        brr[0][i]=0;
    }
    
    for(i=1;i<lena+1;i++)
    {
        for(j=1;j<lenb+1;j++)
        {
            if(a[i-1]==b[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
                brr[i][j]=1;

            }
            else
            {
                if(arr[i-1][j]<arr[i][j-1])
                {
                    arr[i][j]=arr[i][j-1];
                    brr[i][j]=2;
                    
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                    brr[i][j]=3;
                    
                }
            }
        }
    }
    int x=lena,y=lenb;
    while(brr[x][y]!=0)
    {
        if(brr[x][y]==1)
        {
            cout<<a[x-1];
            x--;
            y--;
        }
        else if(brr[x][y]==2)
        {
            x--;
        }
        else
            y--;
    }

    // for(i=0;i<lena+1;i++)
    // {
    //     for(j=0;j<lenb+1;j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int main()
{
    string a,b;
    a = "abdcabd";
    b = "adbdcbd";
    lcb(a,b);
return 0;
}