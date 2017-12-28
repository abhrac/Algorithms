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

struct Node
{
  int data;
  int weight;
  Node* next;
};

Node* Graph;

void vlist(int n)
{
  Graph=new Node[n];
  for(int i=0; i<n; i++)
  {
    Graph[i].data=i;
    Graph[i].weight=0;
    Graph[i].next=NULL;
  }
}

void addedge(int u, int v, int w)
{
  Node* temp=new Node;
  temp->data=v;
  temp->weight=w;
  temp->next=Graph[u].next;
  Graph[u].next=temp;
}

void display(int n)
{
  for(int i=0; i<n; i++)
  {
    Node* temp=Graph+i;
    while(temp!=NULL)
    {
      cout<<((temp->data)+1)<<"("<<temp->weight<<")"<<"->";
      temp=temp->next;
    }
    cout<<endl;
  }
}

void dijkstra(int n)
{
  int* spset=new int[n];
  for(int i=0; i<n; i++)
  {
    spset[i]=0;
  }
  Heap h(n);
  h.deckey(0, 0);
  while(!h.empty())
  {
    HNode m=h.extractmin();
    spset[m.key]=1;
    cout<<(m.key+1)<<"("<<m.value<<")"<<" ";
    Node* temp=Graph[m.key].next;
    while(temp!=NULL)
    {
      if(spset[temp->data]==0)
      {
        int v=m.value+temp->weight;
        h.deckey(temp->data, v);
      }
      temp=temp->next;
    }
  }
  cout<<endl;
}

int main()
{
  int n, e, u, v, w;
  cout<<"Enter the number of vertices"<<endl;
  cin>>n;
  vlist(n);
  cout<<"Enter the number of edges"<<endl;
  cin>>e;
  cout<<"Enter the edges"<<endl;
  for(int i=0; i<e; i++)
  {
    cin>>u>>v>>w;
    u=u-1;
    v=v-1;
    addedge(u, v, w);
    addedge(v, u, w);
  }
  display(n);
  cout<<"Shortest Path using Dijkstra's Algorithm:"<<endl;
  dijkstra(n);
  return 0;
}
