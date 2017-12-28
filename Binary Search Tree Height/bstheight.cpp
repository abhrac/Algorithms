#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* root=NULL;
Node* Insert(Node* head, int data);
int FindHeight(Node* root);

int main()
{
    int n, x, i;
    cout<<"Please enter the number of elements in the Binary Search Tree:"<<endl;
    cin>>n;
    cout<<"Please enter the numbers:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    cout<<"Height of the Binary Search Tree="<<FindHeight(root)<<endl;
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
        {
            root->left=Insert(root->left, data);
        }
        else
        {
            root->right=Insert(root->right, data);
        }
        return root;
    }
}

int FindHeight(Node* root)
{
    if(root==NULL)
    {
        return (-1);
    }
    int m=max(FindHeight(root->left), FindHeight(root->right));
    return m+1;
}
