// Dijiktras Algorithm

#include<iostream>
#include <limits.h> 
#define V 9
using namespace std;
int min_index(int dist[],bool spset[])
{
    int temp= INT_MAX,min_ind;
    for(int i=0;i<V;i++)
    {
        if(spset[i]==false && temp>=dist[i])
        {
            temp=dist[i];
            min_ind=i;
        }
    }
    return min_ind;
}
void display(int dist[])
{
    for(int i=0;i<V;i++)
    {
        cout<<"Distance of "<<i<<" node from 0th node is "<<dist[i]<<endl;
    }
}
void Dijiktras(int graph[V][V],int src)
{
    bool spset[V];
    int dist[V];
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, spset[i] = false;
    dist[0]=0;

    for(int i=0;i<V-1;i++)
    {
        int min = min_index(dist,spset);
        spset[min]=true;

        for(int j=0;j<V;j++)
        {
            if(spset[j]==false && graph[min][j] && dist[min]!=INT_MAX && dist[min]+graph[min][j]<dist[j])
                dist[j]= dist[min]+graph[min][j];
        }    
    }
    display(dist);
}

int main()
{
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     };
    Dijiktras(graph,0);
return 0;
}
