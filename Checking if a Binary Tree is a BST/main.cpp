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
bool IsBST(Node* root);
bool IsLesser(Node* root, int value);
bool IsGreater(Node* root, int value);

int main()
{
    int n, x, i;
    cout<<"Please enter the number of elements in the Binary Tree:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    if(IsBST(root))
        cout<<"Binary Search Tree!"<<endl;
    else
        cout<<"Not a Binary Search Tree!"<<endl;

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
        if(data<root->data)
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

bool IsBST(Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        if(IsBST(root->left) && IsBST(root->right) && IsLesser(root->left, root->data) && IsGreater(root->right, root->data))
        {
            return true;
        }
        return false;
    }
}

bool IsLesser(Node* root, int value)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        if(root->data<value && IsLesser(root->left, value) && IsLesser(root->right, value))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool IsGreater(Node* root, int value)
{
    if(root==NULL)
    {
        return true;
    }
    else
    {
        if(root->data>value && IsGreater(root->left, value) && IsGreater(root->right, value))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
