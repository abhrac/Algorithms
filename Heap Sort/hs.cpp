#include <iostream>
using namespace std;

int* h;
int pos;

void heapsort(int n);
int parent(int i);
void insert(int n);
void heapify(int root);
int extractmax();
void swap(int* a, int* b);

int main()
{
  int n, x;
  cout<<"Enter the number of array elements"<<endl;
  cin>>n;
  cout<<"Enter the array elements"<<endl;
  h=new int[n];
  pos=0;
  for(int i=0; i<n; i++)
    {
      cin>>x;
      insert(x);
    }
  cout<<endl;
  heapsort(n);
  cout<<"Sorted array:"<<endl;
  for(int i=0; i<n; i++)
    {
      cout<<h[i]<<" ";
    }
  cout<<endl;
  return 0;
}

void heapsort(int n)
{
  int m;
  while(pos>0)
    {
      m=extractmax();
      h[pos]=m;
    }
}

int parent(int i)
{
  return (((i+1)/2)-1);
}

void insert(int n)
{
  h[pos]=n;
  pos=pos+1;
  int i;
  i=pos-1;
  while(h[i]>h[parent(i)] && i>0)
    {
      swap(&h[i], &h[parent(i)]);
      i=parent(i);
    }
}

void heapify(int root)
{
  int l=(root*2)+1;
  int r=l+1;
  int max=root;
  if(l<pos && h[l]>h[root])
    {
      max=l;
    }
  if(r<pos && h[r]>h[max])
    {
      max=r;
    }
  if(max!=root)
    {
      swap(&h[root], &h[max]);
      heapify(max);
    }
}

int extractmax()
{
  int temp=h[0];
  h[0]=h[pos-1];
  pos=pos-1;
  heapify(0);
  return temp;
}

void swap(int* a, int* b)
{
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
}


	    
