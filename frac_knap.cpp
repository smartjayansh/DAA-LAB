#include<iostream>
using namespace std;
void swap(int *a,int *b,int *c,int *d,float *e,float *f,int *g,int *h)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    temp=*c;
    *c=*d;
    *d=temp;
    temp=*e;
    *e=*f;
    *f=temp;
    temp=*g;
    *g=*h;
    *h=temp;
    
}
void sor(float rat[],int inp[],int val[],int id[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(rat[j]<rat[j+1])
                swap(&inp[j],&inp[j+1],&val[j],&val[j+1],&rat[j],&rat[j+1],&id[j],&id[j+1]);
}
int main()
{
    int weight,size;
    cout<<"Enter max weight\n";
    cin>>weight;
    cout<<"Enter the size of input array\n";
    cin>>size;
    int inp[size],val[size],i,id[size];
    float rat[size];
    for(i=0;i<size;i++)
    {
        id[i]=i+1;
        cout<<"Enter weight of item "<<i+1<<endl;
        cin>>inp[i];
        cout<<"Enter value of item "<<i+1<<endl;
        cin>>val[i];
        rat[i]=val[i]/inp[i];
    }
    sor(rat,inp,val,id,size);
    i=0;
    int sum=0;
    while(weight>=0)
    {
        if(inp[i]<=weight)
        {
            sum+=val[i];
            weight-=inp[i];
            cout<<"Item "<<id[i]<<" is taken full"<<endl;
        }
        if(inp[i]>weight)
        {
            sum+=rat[i]*weight;
            cout<<"Item "<<id[i]<<" is taken "<< weight<<"/"<<inp[i]<<endl;
            weight=-1;
        }
        i++;
    }
    cout<<"Remaining items are not taken\n";
    cout<<"The maximum value of knapsack is "<<sum<<endl;
return 0;
}

