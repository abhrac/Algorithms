#include <iostream>

using namespace std;

struct Node
{
    int v;
    Node* next;
};

Node* Graph=NULL;

void vertexList(int n);
void adjList(int s, int d);
void printGraph(int n);
void DFS(int s, int n);
void DFSutil(bool* visited, int s);

int main()
{
    int n, x, i, s, d, e;
    cout<<"Please enter the number of vertices in the Graph:"<<endl;
    cin>>n;
    vertexList(n);
    cout<<"Please enter the number of edges in the Graph:"<<endl;
    cin>>e;
    cout<<"Please enter the edges:"<<endl;
    for(i=0; i<e; i++)
    {
        cin>>s>>d;
        adjList(s, d);
    }
    printGraph(n);
    cout<<"After performing Depth First Search:"<<endl;
    DFS(0, n);
    cout<<endl;

    return 0;
}

void vertexList(int n)
{
    Graph=new (struct Node[n]);
    for(int i=0; i<n; i++)
    {
        Graph[i].v=i;
        Graph[i].next=NULL;
    }
}

void adjList(int s, int d)
{
    if(Graph[s].next==NULL)
    {
        Node* temp=new (struct Node);
        temp->v=d;
        temp->next=NULL;
        Graph[s].next=temp;
    }
    else
    {
        Node* temp=new (struct Node);
        temp->v=d;
        temp->next=Graph[s].next;
        Graph[s].next=temp;
    }
}

void printGraph(int n)
{
    cout<<"Adjacency List of the Graph:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<Graph[i].v<<"--> ";
        Node* temp=Graph[i].next;
        while(temp!=NULL)
        {
            cout<<temp->v<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void DFS(int s, int n)
{
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    DFSutil(visited, s);
}

void DFSutil(bool* visited, int s)
{
    if(visited[s]==true)
    {
        return;
    }
    visited[s]=true;
    cout<<s<<" ";
    Node* temp=Graph[s].next;
    while(temp!=NULL)
    {
        DFSutil(visited, temp->v);
        temp=temp->next;
    }
}
