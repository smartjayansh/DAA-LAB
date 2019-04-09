//To find position of queens
#include<iostream>
#define n 8
using namespace std;
void print(int board[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
        
}
bool isSafe(int board[n][n],int row,int col)
{
    int i,j;
    for(i=0;i<col;i++)
        if(board[row][i])
            return false;
    
    for(i=row,j=col;j>=0 && i>=0;i--,j--)
        if(board[i][j])
            return false;

    for(i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j])
            return false;

    return true;
}
bool solvenq(int board[n][n],int col)
{
    if(col>=n)
        return true;

    for(int i=0;i<n;i++)
    {
        if(isSafe(board,i,col))
        {
            board[i][col]=1;
            if(solvenq(board,col+1))
                return true;
        
            board[i][col]=0;
        }
        
    }

    return false;
}
bool solve(int board[n][n])
{
    if(!solvenq(board,0))
    {
        cout<<"Solution does not exist"<<endl;
        return false;
    }
    print(board);
    return true;

}

int main()
{
    int board[n][n] = { {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
    }; 
    solve(board);
return 0;
}