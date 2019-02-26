#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
void brute(int text[],int pattern[])
{
    // cout<<text<<endl<<pattern<<endl;
    int st,sp;
    st = 5;     //text.length();
    sp = 2;     //pattern.length();
    int i,j;
    for(i=0;i<=st-sp;i++)
    {
        for(j=0;j<sp;j++)
        {
            if(text[i+j]!=pattern[j])
                break;
        }

        if(j==sp)
        {
            cout<<"Pattern Found\n";
            break;
        }
       
    }
    if(j!=sp)
        cout<<"Pattern not found\n";
    
}
void rabin(int text[],int pattern[])
{
    int st,sp;
    st = 5; //text.length();
    sp = 2; //pattern.length();
    int i,j=0;
    int dect=0,decp=0;
    for(i=sp-1;i>=0;i--)
    {
        decp+=pattern[i]*pow(10,j);
        j++;
    }
    decp=decp%7;
    j=0;
    int k=0;
    for(i=0;i<=st-sp;i++)
    {
        if(i==0)
        {
            for(k=sp-1;k>=0;k--)
            {
                dect+=text[i+k]*pow(10,j);
                j++;
            }
        }
        else
        {
            dect=(dect-text[i-1]*pow(10,sp-1))*pow(10,sp-2) + text[i+sp-1];
        }
        int dectm;
        dectm= dect%7;
        
        if(dectm==decp)
         {
    //     string temp="";
        //     for(int l=0;l<sp;l++)
        //     {
        //         temp+=text[i+l];
        //     } 
            int temp[2];
            for(int l=0;l<sp;l++)
                temp[l]=text[i+l];
            brute(temp,pattern);
            // int temp=i,len=0;
            //     for(temp;temp<=st-sp;temp++)
            //     {
            //         for(len=0;len<sp;len++)
            //         {
            //             if(text[temp+len]!=pattern[len])
            //                 break;
            //         }

            //         if(len==sp)
            //         {
            //             cout<<"Pattern Found\n";
            //             break;
            //         }
            //         else
            //         {
            //             cout<<"Pattern Not Found\n";
            //         }
            //     }
        }
       
    }
}
int main()
{
    string text,pattern;
    int arr[5]={1,2,3,4,5},brr[2]={1,1};
    // cout<<"Enter the text\n";
    // getline(cin,text);
    // cout<<"Enter the pattern\n";
    // getline(cin,pattern);    
    cout<<"What method do you want to apply\n 1) Brute Force \n2) Rabin Karp\n";
    int opt;
    cin>>opt;
    switch (opt)
    {
        case 1:
            brute(arr,brr);
            break;
    
        case 2:
            rabin(arr,brr);
            break;
    }
return 0;
}