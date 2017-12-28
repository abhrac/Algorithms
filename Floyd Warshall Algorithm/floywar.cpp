#include <iostream>
#include <stack>
#define INF 100000
using namespace std;

int** path;

void Floyd_Warshall(int** d, int n)
{
  path=new int*[n];
  for(int i=0; i<n; i++)
  {
    path[i]=new int[n];
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(d[i][j]!=INF)
      {
        path[i][j]=i;
        continue;
      }
      path[i][j]=-1;
    }
  }
  for(int k=0; k<n; k++)
  {
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        if(d[i][j]>(d[i][k]+d[k][j]))
        {
          d[i][j]=d[i][k]+d[k][j];
          path[i][j]=path[k][j];
        }
      }
    }
  }
  cout<<"All pairs shortest path weights using Floyd Warshall Algorithm:"<<endl;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      cout<<d[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"Shortest paths:"<<endl;
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      cout<<(path[i][j]+1)<<" ";
    }
    cout<<endl;
  }
}

void findpath(int** distance, int s, int d)
{
  if(path[s][d]==-1)
  {
    cout<<"No path between source and destination"<<endl;
    return;
  }
  int x=d;
  stack<int> st;
  st.push(x+1);
  while(x!=s)
  {
    st.push((path[s][x])+1);
    x=path[s][x];
  }
  cout<<"Shortest path from "<<(s+1)<<" to "<<(d+1)<<":"<<endl;
  while(!st.empty())
  {
    cout<<st.top()<<" ";
    st.pop();
  }
  cout<<endl<<"Shortest path weight="<<distance[s][d]<<endl;
}

int main()
{
  int n, u, v, w, e;
  cout<<"Enter the number of vertices:"<<endl;
  cin>>n;
  int** distance=new int*[n];
  for(int i=0; i<n; i++)
  {
    distance[i]=new int[n];
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      if(i!=j)
      {
        distance[i][j]=INF;
      }
    }
  }
  cout<<"Enter the number of edges:"<<endl;
  cin>>e;
  cout<<"Enter the edges:"<<endl;
  for(int i=0; i<e; i++)
  {
    cin>>u>>v>>w;
    distance[u-1][v-1]=w;
  }
  for(int i=0; i<n; i++)
  {
    for(int j=0; j<n; j++)
    {
      cout<<distance[i][j]<<" ";
    }
    cout<<endl;
  }
  Floyd_Warshall(distance, n);
  int c, s, d;
  while(1)
  {
    cout<<"1.Calculate Shortest Path 2.Exit"<<endl;
    cin>>c;
    if(c==1)
    {
      cout<<"Enter source vertex:"<<endl;
      cin>>s;
      cout<<"Enter destination vertex:"<<endl;
      cin>>d;
      findpath(distance, (s-1), (d-1));
    }
    else if(c==2)
    {
      break;
    }
    else
    {
      cout<<"Invalid choice"<<endl;
    }
  }
  return 0;
}
