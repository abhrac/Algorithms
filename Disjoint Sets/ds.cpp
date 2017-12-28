#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* rep;
  Node* next;
};

void create(int n);
void setunion(int u, int v);
void display(int n);
Node* find(Node* x);

Node* a;

int main()
{
  int n, e, u, v;
  cout<<"Enter the number of vertices"<<endl;
  cin>>n;
  create(n);
  cout<<"Enter the number of edges"<<endl;
  cin>>e;
  cout<<"Enter the edges"<<endl;
  for(int i=0; i<e; i++)
    {
      cin>>u>>v;
      setunion(u, v);
    }
  display(n);
  return 0;
}

void create(int n)
{
  a=new Node[n];
  for(int i=0; i<n; i++)
    {
      a[i].data=i;
      a[i].rep=a+i;
      a[i].next=NULL;
    }
}

void setunion(int u, int v)
{
  if(find(a+u)==find(a+v))
    {
      return;
    }
  Node* temp=a+u;
  while(temp->next!=NULL)
    {
      temp=temp->next;
    }
  a[v].rep=a[u].rep;
  temp->next=a+v;
}

Node* find(Node* x)
{
  return x->rep;
}

void display(int n)
{
  for(int i=0; i<n; i++)
    {
      if(a[i].rep->data==a[i].data)
	{
	  Node* temp=(a+i);
	  while(temp!=NULL)
	    {
	      cout<<temp->data<<" ";
	      temp=temp->next;
	    }
	  cout<<endl;
	}
    }
}



