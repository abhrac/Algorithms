#include <iostream>

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

int main()
{
    Graph=NULL;
    int n, i, e, s, d;
    cout<<"Please enter the number of vertices in the graph:"<<endl;
    cin>>n;
    vertexList(n);
    cout<<"Please enter the number of edges in the graph:"<<endl;
    cin>>e;
    cout<<"Please enter the edges:"<<endl;
    for(i=0; i<e; i++)
    {
        cin>>s>>d;
        addEdge(s, d);
    }
    printGraph(n);
    if(detectCycle(n))
    {
        cout<<"Cycle present!"<<endl;
    }
    else
    {
        cout<<"No cycle!"<<endl;
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
    temp->data=d;
    temp->next=Graph[s].next;
    Graph[s].next=temp;
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

bool* recstack;
bool cycle=false;

bool detectCycle(int n)
{
    bool* visited=new (bool[n]);
    recstack=new (bool[n]);
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
        recstack[i]=false;
    }
    DFS(0, visited);
    return cycle;
}

void DFS(int s, bool* visited)
{
    visited[s]=true;
    recstack[s]=true;
    Node* temp=Graph[s].next;
    while(temp!=NULL)
    {
        if(recstack[temp->data])
        {
            cycle=true;
        }
        if(!visited[temp->data])
        {
            DFS(temp->data, visited);
        }
        temp=temp->next;
    }
    recstack[s]=false;
}
