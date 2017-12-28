#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

void display(int n);
void addedge(int u, int v);
void vlist(int n);
int detectCycle(int n);
int DFS(int root, int parent);

Node* Graph;

int main()
{
  int n, e, u, v;
  cout<<"Enter the number of vertices"<<endl;
  cin>>n;
  vlist(n);
  cout<<"Enter the number of edges"<<endl;
  cin>>e;
  for(int i=0; i<e; i++)
    {
      cin>>u>>v;
      u=u-1;
      v=v-1;
      addedge(u, v);
      addedge(v, u);
    }
  display(n);
  if(detectCycle(n))
    {
      cout<<"Cycle is present"<<endl;
    }
  else
    {
      cout<<"No cycle present"<<endl;
    }
  return 0;
}

void vlist(int n)
{
  Graph=new Node[n];
  for(int i=0; i<n; i++)
    {
      Graph[i].data=i;
      Graph[i].next=NULL;
    }
}

void addedge(int u, int v)
{
  Node* temp=new Node;
  temp->data=v;
  temp->next=Graph[u].next;
  Graph[u].next=temp;
}

void display(int n)
{
  for(int i=0; i<n; i++)
    {
      Node* temp=(Graph+i);
      while(temp!=NULL)
	{
	  cout<<((temp->data)+1)<<"->";
	  temp=temp->next;
	}
      cout<<endl;
    }
}

int* visited;

int detectCycle(int n)
{
  visited=new int[n];
  for(int i=0; i<n; i++)
    {
      visited[i]=0;
    }
  return DFS(0, 0);
}

int DFS(int root, int parent)
{
  if(visited[root]==1)
    {
      cout<<"At vertex "<<(root+1)<<endl;
      return 1;
    }
  int f=0, gp;
  visited[root]=1;
  gp=parent;
  parent=root;
  Node* temp=Graph[root].next;
  while(temp!=NULL)
    {
      if(temp->data!=gp)
	{
	  f=DFS(temp->data, parent);
	}
      if(f==1)
	{
	  return f;
	}
      temp=temp->next;
    }
  visited[root]=0;
  return f;
}

