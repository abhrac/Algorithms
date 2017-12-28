#include <iostream>
#define INF 10000
using namespace std;

struct HNode
{
  int key;
  int value;
};

class Heap
{
  HNode* h;
  int size, end;
  int* pos;
public:
  Heap(int n)
  {
    size=n;
    end=n;
    h=new HNode[n];
    pos=new int[n];
    for(int i=0; i<n; i++)
    {
      h[i].key=i;
      h[i].value=INF;
      pos[i]=i;
    }
  }
  void swap(int* a, int* b)
  {
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
  }
  int empty()
  {
    if(end==0)
    {
      return 1;
    }
    return 0;
  }
  int parent(int i)
  {
    return (((i+1)/2)-1);
  }
  void heapify(int root)
  {
    int min=root;
    if(((2*root)+1)<end && h[((2*root)+1)].value<h[min].value)
    {
      min=(2*root)+1;
    }
    if(((2*root)+2)<end && h[((2*root)+2)].value<h[min].value)
    {
      min=(2*root)+2;
    }
    if(min!=root)
    {
      swap(&h[root].key, &h[min].key);
      swap(&h[root].value, &h[min].value);
      pos[h[root].key]=root;
      pos[h[min].key]=min;
      heapify(min);
    }
  }
  HNode extractmin()
  {
    HNode m=h[0];
    h[0]=h[end-1];
    end=end-1;
    pos[h[0].key]=0;
    heapify(0);
    return m;
  }
  void deckey(int k, int v)
  {
    int i=pos[k];
    if(h[i].value<v)
    {
      return;
    }
    h[i].value=v;
    while(i>0 && h[i].value<h[parent(i)].value)
    {
      swap(&h[i].key, &h[parent(i)].key);
      swap(&h[i].value, &h[parent(i)].value);
      pos[h[i].key]=i;
      pos[h[parent(i)].key]=parent(i);
      i=parent(i);
    }
  }
  void display()
  {
    cout<<"Heap:"<<endl;
    for(int i=0; i<end; i++)
    {
      cout<<h[i].key<<"("<<h[i].value<<")"<<" ";
    }
    cout<<endl<<"Positions:"<<endl;
    for(int i=0; i<size; i++)
    {
      cout<<pos[i]<<" ";
    }
    cout<<endl;
  }
};

int main()
{
  Heap h(5);
  h.deckey(3, 10);
  h.display();
  h.deckey(4, 5);
  h.display();
  h.deckey(2, 8);
  h.deckey(0, 7);
  h.deckey(1, 3);
  h.display();
  while(!h.empty())
  {
    HNode m=h.extractmin();
    cout<<m.key<<"("<<m.value<<")"<<endl;
    h.display();
  }
  return 0;
}
