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
void InorderSuccessor(Node* head, int data);
int FindMin(Node* root);

int main()
{
    int n, x, i, e;
    cout<<"Please enter the number of elements in the Binary Search tree:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    cout<<"Please enter an element:"<<endl;
    cin>>e;
    cout<<"Inorder successor of the given element is:"<<endl;
    InorderSuccessor(root, e);

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

void InorderSuccessor(Node* head, int data)
{
    if(head==NULL)
    {
        cout<<NULL<<endl;
        return;
    }
    if(data<head->data)
    {
        InorderSuccessor(head->left, data);
    }
    else if(data>head->data)
    {
        InorderSuccessor(head->right, data);
    }
    else
    {
        if(head->right!=NULL)
        {
            cout<<FindMin(head->right);
        }
        else
        {
            Node* successor=NULL;
            Node* ancestor=root;
            while(ancestor!=head)
            {
                if(data<ancestor->data)
                {
                    successor=ancestor;
                    ancestor=ancestor->left;
                }
                else
                {
                    ancestor=ancestor->right;
                }
            }
            if(successor!=NULL)
            {
                cout<<successor->data<<endl;
            }
        }
    }
}

int FindMin(Node* root)
{
    if(root->left==NULL)
    {
        return (root->data);
    }
    FindMin(root->left);
}
