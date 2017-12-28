#include <iostream>
using namespace std;

class fib
{
  int a, b;
public:
  fib()
  {
    a=0;
    b=1;
  }
  void findseries(int n)
  {
    if(n==1)
      {
	cout<<a;	
      }
    else if(n==2)
      {
	cout<<a<<" "<<b;
      }
    else if(n>2)
      {
	int i, c;
	cout<<a<<" "<<b<<" ";
	c=a+b;
	for(i=0; i<n-2; i++)
	  {
	    c=a+b;
	    cout<<c<<" ";
	    a=b;
	    b=c;
	  }
      }
    cout<<endl;
  }
};

int main()
{
  int n;
  cout<<"Enter the number of terms in the Fibonacci series:"<<endl;
  cin>>n;
  fib f;
  f.findseries(n);
  
  return 0;
}

