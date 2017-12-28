#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

struct el
{
  int data;
  el* rep;
  el* next;
};

Node* Graph;
el* ds;

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
      Node* temp=Graph+i;
      while(temp!=NULL)
	{
	  cout<<((temp->data)+1)<<"->";
	  temp=temp->next;
	}
      cout<<endl;
    }
}

void createsets(int n)
{
  ds=new el[n];
  for(int i=0; i<n; i++)
    {
      ds[i].data=i;
      ds[i].rep=(ds+i);
      ds[i].next=NULL;
    }
}

el* find(int u)
{
  return (ds[u].rep);
}

int Union(int u, int v)
{
  if(find(u)==find(v))
    {
      return 1;
    }
  el* temp=ds+u;
  while(temp->next!=NULL)
    {
      temp=temp->next;
    }
  ds[v].rep=ds[u].rep;
  temp->next=ds+v;
  return 0;
}

void showsets(int n)
{
  for(int i=0; i<n; i++)
    {
      if(ds[i].rep==(ds+i))
	{
	  el* temp=ds+i;
	  while(temp!=NULL)
	    {
	      cout<<((temp->data)+1)<<" ";
	      temp=temp->next;
	    }
	  cout<<endl;
	}
    }
}

int* parent;

int detectCycle(int n)
{
  createsets(n);
  parent=new int[n];
  for(int i=0; i<n; i++)
    {
      parent[i]=-1;
    }
  int f=0;
  for(int i=0; i<n; i++)
    {
      Node* temp=Graph[i].next;
      while(temp!=NULL)
	{
	  if(temp->data!=parent[i])
	    {
	      f=Union(Graph[i].data, temp->data);
	      parent[temp->data]=i;
	      if(f==1)
		{
		  cout<<"At vertex "<<((temp->data)+1)<<endl;
		  return f;
		}
	    }
	  temp=temp->next;
	}
    }
  return f;
}

int main()
{
  int n, e, u, v, f;
  cout<<"Enter the number of vertices"<<endl;
  cin>>n;
  vlist(n);
  cout<<"Enter the number of edges"<<endl;
  cin>>e;
  cout<<"Enter the edges"<<endl;
  for(int i=0; i<e; i++)
    {
      cin>>u>>v;
      u=u-1;
      v=v-1;
      addedge(u, v);
      addedge(v, u);
    }
  display(n);
  f=detectCycle(n);
  if(f==1)
    {
      cout<<"Cycle is present"<<endl;
    }
  else
    {
      cout<<"No cycle found"<<endl;
    }
  cout<<"Disjoint Sets:"<<endl;
  showsets(n);
  return 0;
}

