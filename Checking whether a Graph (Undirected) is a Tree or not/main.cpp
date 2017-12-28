#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* Graph;

void vertexList(int n);
void addEdge(int s, int d);
void printGraph(int n);
bool detectCycle(int n);
void DFS(int s, bool* visited);
bool IsConnected(int n);

int main()
{
    int n, i, e, s, d;
    cout<<"Please enter the number of vertices in the graph:"<<endl;
    cin>>n;
    vertexList(n);
    cout<<"Please enter the number of edges in the Graph:"<<endl;
    cin>>e;
    cout<<"Please enter the edges:"<<endl;
    for(i=0; i<e; i++)
    {
        cin>>s>>d;
        addEdge(s, d);
    }
    printGraph(n);
    if(!detectCycle(n) && IsConnected(n))
    {
        cout<<"The Graph is a Tree!"<<endl;
    }
    else
    {
        cout<<"The Graph is not a Tree!"<<endl;
    }

    return 0;
}

void vertexList(int n)
{
    Graph=new (struct Node[n]);
    for(int i=0; i<n; i++)
    {
        Graph[i].data=i;
        Graph[i].next=NULL;
    }
}

void addEdge(int s, int d)
{
    Node* temp=new (struct Node);
    Node* temp1=new (struct Node);
    temp->data=d;
    temp->next=Graph[s].next;
    Graph[s].next=temp;
    temp1->data=s;
    temp1->next=Graph[d].next;
    Graph[d].next=temp1;
}

void printGraph(int n)
{
    cout<<"Adjacency List of the Graph:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<Graph[i].data<<"--> ";
        Node* temp=Graph[i].next;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

stack<int> a;
bool cycle;

bool detectCycle(int n)
{
    cycle=false;
    bool* visited=new (bool[n]);
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    a.push(0);
    DFS(0, visited);
    return cycle;
}

void DFS(int s, bool* visited)
{
    visited[s]=true;
    Node* temp=Graph[s].next;
    while(temp!=NULL)
    {
        if(!a.empty() && temp->data!=a.top() && visited[temp->data])
        {
            cycle=true;
        }
        if(!visited[temp->data])
        {
            a.push(s);
            DFS(temp->data, visited);
        }
        temp=temp->next;
    }
    a.pop();
}

bool IsConnected(int n)
{

    bool* visited=new (bool[n]);
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    DFS(0, visited);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;
}
