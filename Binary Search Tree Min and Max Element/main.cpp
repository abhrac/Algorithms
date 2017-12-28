#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* root=NULL;

Node* Insert(Node* root, int data);
int FindMin(Node* root);
int FindMax(Node* root);

int main()
{
    int n, x, i;
    cout<<"Please enter the number of elements in the Binary Search Tree:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    FindMin(root);
    FindMax(root);

    return 0;
}

Node* Insert(Node* root, int data)
{
    if(root==NULL)
    {
        Node* temp=new (struct Node);
        temp->data=data;
        temp->right=NULL;
        temp->left=NULL;
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

int FindMin(Node* root)
{
    if(root->left==NULL)
    {
        cout<<"Minimum element="<<root->data<<endl;
        return root->data;
    }
    int min=FindMin(root->left);
    return min;
}

int FindMax(Node* root)
{
    if(root->right==NULL)
    {
        cout<<"Maximum element="<<root->data<<endl;
        return root->data;
    }
    int max=FindMax(root->right);
    return max;
}
