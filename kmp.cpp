#include<iostream>
using namespace std;
void algo(int arr[],int pat[],int size1,int size2)
{
    int pre[size2],k=0,i,j;
    pre[0]=0;
    for(i=1;i<size2;i++)
    {
        if(pat[i]==pat[k])
        {
            k++;
            pre[i]=k;
        }
        else
        {
            k=0;
            pre[i]=0;
        }
        
    }
    for(int i=0;i<size2;i++)
        cout<<pre[i]<<" ";
    cout<<endl;

    i=0;j=0;k=0; 
    // while(i<size2)
    // {
    //     if(pat[i]!=arr[j] && i==0)
    //     {
        
    //     }
    //     else
    //     {
    //         if(pat[i]==arr[j])
    //         {
    //             i++;
    //         }
    //         else
    //         {
    //             i=pre[i-1];
    //         }
            
    //     }
    //     j++;
    //     k=j-1;
    // }
    // int m=size2-1;
    // for(k;k>j-size2;k--,m--)
    // {
    //     if(pat[m]!=arr[k])
    //         break;
    // }
    // if(m==0)
    //     cout<<"pattern found\n";
    // else
    // {
    //         cout<<"pattern not found\n";
    // }
    
    for(i;i<size1;i++)
    {
        if(arr[i]==pat[j])
        {
            j++;
        }
        else
        {
            if(j==0)
            {}
            else
            {
                j=pre[j-1];
            }
        }
        if(j==size2)
            break;
    }
    if(i==size1 && j!=size2)
        cout<<"pattern not found\n";
    else
        cout<<"pattern found at index "<<i-size2<<endl;
}

int main()
{
    int arr[13]={1,2,1,2,1,4,1,2,1,2,1,2,4};
    int pat[6]={1,2,1,2,1,3};
    algo(arr,pat,13,6);
return 0;
}