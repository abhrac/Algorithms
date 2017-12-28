#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int v;
    Node* next;
};

Node* Graph;

void vertexList(int n);
void addEdge(int v, int d);
void printGraph(int n);
void BFS(int s, int n);

int main()
{
    int n, e, v, d;
    cout<<"Please enter the number of nodes in the Graph:"<<endl;
    cin>>n;
    vertexList(n);
    cout<<"Please enter the number of edges in the Graph:"<<endl;
    cin>>e;
    cout<<"Please enter the edges:"<<endl;
    for(int i=0; i<e; i++)
    {
        cin>>v>>d;
        addEdge(v, d);
    }
    printGraph(n);
    BFS(0, n);

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

void addEdge(int v, int d)
{
    if(Graph[v].next==NULL)
    {
        Node* temp=new (struct Node);
        temp->v=d;
        temp->next=NULL;
        Graph[v].next=temp;
    }
    else
    {
        Node* temp=new (struct Node);
        temp->v=d;
        temp->next=Graph[v].next;
        Graph[v].next=temp;
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

void BFS(int s, int n)
{
    cout<<"Performing Breadth First Search on the Graph:"<<endl;
    queue<int> d;
    bool* visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    d.push(Graph[s].v);
    visited[s]=true;
    while(!d.empty())
    {
        Node* temp=Graph[d.front()].next;
        while(temp!=NULL)
        {
            if(!visited[temp->v])
            {
                d.push(temp->v);
                visited[temp->v]=true;
            }
            temp=temp->next;
        }
        cout<<d.front()<<" ";
        d.pop();
    }
    cout<<endl;
}
