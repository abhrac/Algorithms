#include <iostream>
#include <string>
#include <stack>
using namespace std;

void printsequence(int** l, string s1, string s2)
{
  int i=s1.length();
  int j=s2.length();
  stack<char> st;
  while(i>0 && j>0)
  {
    if(s1[i-1]==s2[j-1])
    {
      st.push(s1[i-1]);
      i=i-1;
      j=j-1;
    }
    else
    {
      if(l[i][j-1]>l[i-1][j])
      {
        j=j-1;
      }
      else
      {
        i=i-1;
      }
    }
  }
  cout<<"Longest Common Subsequence:"<<endl;
  while(!st.empty())
  {
    cout<<st.top();
    st.pop();
  }
  cout<<endl;
}

int lcs(string s1, string s2)
{
  int** l=new int*[s1.length()+1];
  for(int i=0; i<=s1.length(); i++)
  {
    l[i]=new int[s2.length()+1];
  }
  for(int i=0; i<=s1.length(); i++)
  {
    for(int j=0; j<=s2.length(); j++)
    {
      if(i==0 || j==0)
      {
        l[i][j]=0;
      }
      else if(s1[i-1]==s2[j-1])
      {
        l[i][j]=l[i-1][j-1]+1;
      }
      else
      {
          l[i][j]=max(l[i][j-1], l[i-1][j]);
      }
    }
  }
  printsequence(l, s1, s2);
  return (l[s1.length()][s2.length()]);
}

int main()
{
  string s1, s2;
  cout<<"Enter two strings:"<<endl;
  cin>>s1>>s2;
  cout<<"Length of longest common subsequence:"<<endl<<lcs(s1, s2)<<endl;
  return 0;
}
