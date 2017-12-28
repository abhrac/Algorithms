#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* root;

Node* Insert(Node* root, int data);
int Search(Node* root, int x);
int main()
{
    root=NULL;
    int n, x, i, q;
    cout<<"Please enter the number of elements in the Binary Search Tree:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    cout<<"Please enter the element to be searched: ";
    cin>>q;
    Search(root, q);

    return 0;
}

Node* Insert(Node* root, int data)
{
    if(root==NULL)
    {
        Node* temp=new (struct Node);
        temp->data=data;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        return root;
    }
    else
    {
        if(data<=root->data)
            root->left=Insert(root->left, data);

        else
            root->right=Insert(root->right, data);

        return root;
    }
}

int Search(Node* root, int x)
{
    if(root==NULL)
    {
        cout<<"Element not found!"<<endl;
        return 0;
    }
    else if(x==root->data)
    {
        cout<<"Element found!"<<endl;
        return 1;
    }

    else if(x<root->data)
    {
       int a=Search(root->left, x);
       if(a==1)
       {
           cout<<"Parent node: "<<root->data<<endl;
           return 0;
       }
       return 0;
    }
    else if(x>root->data)
    {
        int a=Search(root->right, x);
        if(a==1)
        {
            cout<<"Parent node: "<<root->data<<endl;
            return 0;
        }
        return 0;
    }
}
