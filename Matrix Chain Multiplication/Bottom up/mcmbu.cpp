#include <iostream>
#define MAX 100000
using namespace std;

int mmc(int* p, int n)
{
  int** m=new int*[n];
  for(int i=0; i<n; i++)
  {
    m[i]=new int[n];
  }
  int j, cost=0;
  for(int l=2; l<n; l++)
  {
    for(int i=0; i<n-l; i++)
    {
      j=i+l;
      m[i][j]=MAX;
      for(int k=i+1; k<j; k++)
      {
        cost=m[i][k]+m[k][j]+(p[i]*p[k]*p[j]);
        if(cost<m[i][j])
        {
          m[i][j]=cost;
        }
      }
    }
  }
  return m[0][n-1];
}

int main()
{
  int n, cost;
  cout<<"Enter the number of elements in the array:"<<endl;
  cin>>n;
  int* a=new int[n];
  cout<<"Enter the elements of the array:"<<endl;
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  cost=mmc(a, n);
  cout<<"Minimum cost of multiplying the matrices="<<cost<<endl;
  return 0;
}
