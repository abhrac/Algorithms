#include <iostream>
using namespace std;

int check=0;

int issafe(int** board, int n, int row, int col)
{
    for(int i=0; i<=row; i++)
    {
        if(board[i][col])
        {
            return 0;
        }
    }
    for(int i=row, j=col; (i>=0 && j>=0); i--, j--)
    {
        if(board[i][j])
        {
            return 0;
        }
    }
    for(int i=row, j=col; (i>=0 && j<n); i--, j++)
    {
        if(board[i][j])
        {
            return 0;
        }
    }
    return 1;
}

void printsoln(int** board, int n)
{
    static int count=1;
    cout<<endl<<"Solution "<<(count++)<<":"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int queens(int** board, int n, int row)
{
    if(row==n)
    {
        printsoln(board, n);
        check=1;
        return 1;
    }
    for(int col=0; col<n; col++)
    {
        if(issafe(board, n, row, col))
        {
            board[row][col]=1;
            queens(board, n, row+1);
            board[row][col]=0;
        }
    }
    return check;
}

void solvenqueens(int n)
{
    int** board=new int*[n];
    for(int i=0; i<n; i++)
    {
        board[i]=new int[n];
    }
    int f;
    f=queens(board, n, 0);
    if(!f)
    {
        cout<<"No feasible solution."<<endl;
        return;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of queens:"<<endl;
    cin>>n;
    solvenqueens(n);
    return 0;
}
