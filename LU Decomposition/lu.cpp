#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of equations:"<<endl;
    cin>>n;
    cout<<"Enter the elements of the matrix A:"<<endl;
    float** a=new float*[n];
    float** l=new float*[n];
    float** u=new float*[n];
    float* b=new float[n];
    float* y=new float[n];
    float* x=new float[n];
    for(int i=0; i<n; i++)
    {
        a[i]=new float[n];
        l[i]=new float[n];
        u[i]=new float[n];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the constant terms:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>b[i];
    }
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(i<=j)
            {
                u[i][j]=a[i][j];
                for(int k=0; k<i-1; k++)
                {
                    u[i][j]=u[i][j]-(l[i][k]*u[k][j]);
                }
                if(i==j)
                {
                    l[i][j]=1;
                }
                else
                {
                    l[i][j]=0;
                }
            }
            else
            {
                l[i][j]=a[i][j];
                for(int k=0; k<j; k++)
                {
                    l[i][j]=l[i][j]-(l[i][k]*u[k][j]);
                }
                l[i][j]=(l[i][j]/u[j][j]);
                u[i][j]=0;
            }
        }
    }
    cout<<endl<<"L:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"U:"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<u[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Y:"<<endl;
    for(int i=0; i<n; i++)
    {
        y[i]=b[i];
        for(int j=0; j<i; j++)
        {
            y[i]=y[i]-(l[i][j]*y[j]);
        }
        cout<<y[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1; i>=0; i--)
    {
        x[i]=y[i];
        for(int j=i+1; j<n; j++)
        {
            x[i]=x[i]-(u[i][j]*x[j]);
        }
        x[i]=(x[i]/u[i][i]);
    }
    cout<<"Solution to the given equations:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<fixed<<setprecision(3)<<x[i]<<" ";
    }
    cout<<endl;
    return 0;
}
