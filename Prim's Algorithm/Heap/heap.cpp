#include <iostream>
#define INF 10000
using namespace std;

struct HNode
{
  int key;
  int label;
};  

class Heap
{
  HNode* h;
  int pos, size;
  int* position;
public:
  Heap(int n)
  {
    pos=0;
    size=n;
    h=new HNode[n];
    position=new int[n];
    for(int i=0; i<n; i++)
      {
	h[i].key=i;
	h[i].label=INF;
      }
  }
  
  int parent(int i)
  {
    return (((i+1)/2)-1);
  }

  void swap(int* a, int* b)
  {
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
  }
  
  void insert(int x, int k)
  {
    h[pos].key=x;
    h[pos].label=k;
    pos=pos+1;
    int i=pos-1;
    position[x]=i;
    while(i>0 && h[i].label<h[parent(i)].label)
      {
	swap(&h[i].key, &h[parent(i)].key);
	swap(&h[i].label, &h[parent(i)].label);
	position[h[i].key]=i;
	position[h[parent(i)].key]=parent(i);
	i=parent(i);
      }
  }

  void heapify(int root)
  {
    int min=root;
    if(((2*root)+1)<pos && h[(2*root)+1].label<h[min].label)
      {
	min=(2*root)+1;
      }
    if(((2*root)+2)<pos && h[(2*root)+2].label<h[min].label)
      {
	min=(2*root)+2;
      }
    if(min!=root)
      {
	swap(&h[root].key, &h[min].key);
	swap(&h[root].label, &h[min].label);
	heapify(min);
      }
    position[h[root].key]=root;
    position[h[min].key]=min;
  }

  HNode extractmin()
  {
    HNode temp=h[0];
    position[h[0].key]=-1;
    h[0].key=h[pos-1].key;
    h[0].label=h[pos-1].label;
    pos=pos-1;
    heapify(0);
    return temp;
  }

  void deckey(int x, int l)
  {
    int i=position[x];
    h[i].label=l;
    while(i>0 && h[i].label<h[parent(i)].label)
      {
	swap(&h[i].key, &h[parent(i)].key);
	swap(&h[i].label, &h[parent(i)].label);
	position[h[i].key]=i;
	position[h[parent(i)].key]=parent(i);
	i=parent(i);
      }
  }
  
  void display()
  {
    for(int i=0; i<pos; i++)
      {
	cout<<h[i].key<<","<<h[i].label<<" ";
      }
    cout<<endl;
    cout<<"Positions"<<endl;
    for(int i=0; i<size; i++)
      {
	cout<<position[i]<<" ";
      }
    cout<<endl;
  }
};

int main()
{
  Heap h(5);
  h.insert(0, 10);
  h.insert(1, 6);
  h.insert(2, 7);
  h.insert(3, 1);
  h.insert(4, 3);
  h.display();
  HNode a=h.extractmin();
  cout<<a.key<<" "<<a.label<<endl;
  h.display();
  h.deckey(0, 5);
  h.display();
  return 0;
}

