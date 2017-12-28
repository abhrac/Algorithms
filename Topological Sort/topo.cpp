#include <iostream>
#include <stack>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

Node* Graph;

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

int* visited;
stack<int> st;

void toposort_util(int i)
{
  if(visited[i]==1)
  {
    return;
  }
  visited[i]=1;
  Node* temp=Graph[i].next;
  while(temp!=NULL)
  {
    toposort_util(temp->data);
    temp=temp->next;
  }
  st.push(i);
}

void toposort(int n)
{
  visited=new int[n];
  for(int i=0; i<n; i++)
  {
    visited[i]=0;
  }
  for(int i=0; i<n; i++)
  {
    if(visited[i]==0)
    {
      toposort_util(i);
    }
  }
  while(!st.empty())
  {
    cout<<((st.top())+1)<<" ";
    st.pop();
  }
  cout<<endl;
}

int main()
{
  int n, e, u, v;
  cout<<"Enter the number of vertices:"<<endl;
  cin>>n;
  vlist(n);
  cout<<"Enter the number of edges:"<<endl;
  cin>>e;
  cout<<"Enter the edges:"<<endl;
  for(int i=0; i<e; i++)
  {
    cin>>u>>v;
    u=u-1;
    v=v-1;
    addedge(u, v);
  }
  display(n);
  cout<<"Topological Sorting:"<<endl;
  toposort(n);
  return 0;
}
