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
Node* Delete(Node* root, int data);
int FindMin(Node* root);
void Inorder(Node* root);
int main()
{
    int n, x, i, del;
    cout<<"Please enter the number of elements in the Binary Search Tree:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    cout<<"After performing Inorder Traversal:"<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"Please enter the data to be deleted:"<<endl;
    cin>>del;
    root=Delete(root, del);
    cout<<"Value Deleted!"<<endl;
    cout<<"After performing Inorder Traversal:"<<endl;
    Inorder(root);

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

Node* Delete(Node* root, int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(data<root->data)
    {
        root->left=Delete(root->left, data);
    }
    else if(data>root->data)
    {
        root->right=Delete(root->right, data);
    }
    else if(data==root->data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            Node* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL)
        {
            Node* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else
        {
            root->data=FindMin(root->right);
            root->right=Delete(root->right, root->data);
            return root;
        }
    }
}

int FindMin(Node* root)
{
    if(root->left==NULL)
    {
        return root->data;
    }
    else
    {
        FindMin(root->left);
    }
}

void Inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
