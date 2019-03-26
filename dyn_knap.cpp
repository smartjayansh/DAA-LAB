#include<iostream>
using namespace std;
int main()
{
    int weight,size;
    cout<<"Enter weight of knapsack\n";
    cin>>weight;
    cout<<"Enter no. of items\n";
    cin>>size;
    int arr[size+1,weight+1];
    int i,j;
    for(i=0;i<=size;i++)
        for(i=0;i<=weight;i++)
        {
            if(i==0 || j==0)
                arr[i][j]=0;
            else
            {
                
            }
            
        }



return 0;
}