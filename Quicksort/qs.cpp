#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
  if(*a==*b)
  {
    return;
  }
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
}

int partition(int* a, int l, int u)
{
  int pivot=a[u], pIndex=l;
  for(int i=l; i<u; i++)
  {
    if(a[i]<pivot)
    {
      swap(&a[i], &a[pIndex]);
      pIndex=pIndex+1;
    }
  }
  swap(&a[pIndex], &a[u]);
  return pIndex;
}

void quicksort(int* a, int l, int u)
{
  if(u<=l)
  {
    return;
  }
  int pIndex;
  pIndex=partition(a, l, u);
  quicksort(a, l, pIndex-1);
  quicksort(a, pIndex+1, u);
}

int main()
{
  int n;
  cout<<"Enter the number of elements in the array:"<<endl;
  cin>>n;
  int* a=new int[n];
  cout<<"Enter the elements"<<endl;
  for(int i=0; i<n; i++)
  {
    cin>>a[i];
  }
  quicksort(a, 0, n-1);
  cout<<"Sorted array:"<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
  return 0;
}
