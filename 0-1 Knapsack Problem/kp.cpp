#include <iostream>
using namespace std;

int max(int a, int b)
{
  if(a>b)
  {
    return a;
  }
  return b;
}

int knapsack(int* wt, int* val, int n, int W)
{
  int** k=new int*[n+1];
  for(int i=0; i<=n; i++)
  {
    k[i]=new int[W+1];
  }
  for(int i=0; i<=n; i++)
  {
    for(int j=0; j<=W; j++)
    {
      if(i==0 || j==0)
      {
        k[i][j]=0;
      }
      else if(wt[i-1]<=j)
      {
        k[i][j]=max((val[i-1]+k[i-1][j-wt[i-1]]), k[i-1][j]);
      }
      else
      {
        k[i][j]=k[i-1][j];
      }
    }
  }
  return k[n][W];
}

int main()
{
  int n, W, k;
  cout<<"Enter the number of items:"<<endl;
  cin>>n;
  int* val=new int[n];
  int* wt=new int[n];
  cout<<"Enter the weights:"<<endl;
  for(int i=0; i<n; i++)
  {
    cin>>wt[i];
  }
  cout<<"Enter the values:"<<endl;
  for(int i=0; i<n; i++)
  {
    cin>>val[i];
  }
  cout<<"Enter the capacity of the Knapsack:"<<endl;
  cin>>W;
  k=knapsack(wt, val, n, W);
  cout<<"Maximum value="<<k<<endl;
  return 0;
}
