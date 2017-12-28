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
void Preorder(Node* root);
void Inorder(Node* root);
void Postorder(Node* root);

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
    cout<<"After performing Preorder Traversal:"<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"After performing Inorder Traversal:"<<endl;
    Inorder(root);
    cout<<endl;
    cout<<"After performing Postorder Traversal:"<<endl;
    Postorder(root);
    cout<<endl;

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

void Preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
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

void Postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}
