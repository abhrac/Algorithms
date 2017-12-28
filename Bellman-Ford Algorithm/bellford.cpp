#include <iostream>
#define INF 10000
using namespace std;

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

void relax(int* d, int u, int v, int w)
{
  if(d[v]>d[u]+w)
  {
    d[v]=d[u]+w;
  }
}

void bellman_ford(int n)
{
  int* d=new int[n];
  for(int i=0; i<n; i++)
  {
    d[i]=INF;
  }
  d[0]=0;
  for(int count=0; count<n; count++)
  {
    for(int i=0; i<n; i++)
    {
      Node* temp=Graph[i].next;
      while(temp!=NULL)
      {
        relax(d, Graph[i].data, temp->data, temp->weight);
        temp=temp->next;
      }
    }
  }
  for(int i=0; i<n; i++)
  {
    Node* temp=Graph[i].next;
    while(temp!=NULL)
    {
      if(d[temp->data]>d[Graph[i].data]+temp->weight)
      {
        cout<<"The Graph contains a negative cycle. Thus, shortest paths are undefined."<<endl;
        return;
      }
      temp=temp->next;
    }
  }
  cout<<"Shortest paths applying Bellman-Ford Algorithm:"<<endl;
  for(int i=0; i<n; i++)
  {
    cout<<(i+1)<<"("<<d[i]<<") ";
  }
  cout<<endl;
}

int main()
{
  int n, e, u, v, w;
  cout<<"Enter the number of vertices:"<<endl;
  cin>>n;
  vlist(n);
  cout<<"Enter the number of edges:"<<endl;
  cin>>e;
  cout<<"Enter the edges:"<<endl;
  for(int i=0; i<e; i++)
  {
    cin>>u>>v>>w;
    u=u-1;
    v=v-1;
    addedge(u, v, w);
    //addedge(v, u, w);
  }
  display(n);
  bellman_ford(n);
  return 0;
}
