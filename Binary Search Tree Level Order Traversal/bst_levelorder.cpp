#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class queue
{
private:

    struct Node1
    {
        Node* data;
        Node1* next;
    };
    Node1* front=NULL;
    Node1* rear=NULL;

public:

    void push(Node* data)
    {
        if(front==NULL)
        {
            Node1* temp=new (struct Node1);
            temp->data=data;
            temp->next=NULL;
            front=temp;
            rear=temp;
        }
        else
        {
            Node1* temp=new (struct Node1);
            temp->data=data;
            temp->next=NULL;
            rear->next=temp;
            rear=rear->next;
        }
    }
    void pop()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else
        {
            Node1* temp=front;
            front=front->next;
            delete temp;
        }
    }
    Node* Front()
    {
        if(front==NULL)
        {
            return NULL;
        }
        else
        {
            return front->data;
        }
    }
    bool empty()
    {
        if(front==NULL)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        Node1* temp=front;
        cout<<"Queue: "<<endl;
        while(temp!=NULL)
        {
            cout<<temp->data->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

Node* root=NULL;

Node* Insert(Node* root, int data);
void LevelOrder(Node* root);

queue a;

int main()
{
    int n, x, i;
    cout<<"Please enter the number of elements in the Binary Search tree:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        root=Insert(root, x);
    }
    a.push(root);
    cout<<"After performing Level Order Traversal:"<<endl;
    LevelOrder(root);

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

void LevelOrder(Node* root)
{
    if(root->left!=NULL)
    {
        a.push(root->left);
    }
    if(root->right!=NULL)
    {
        a.push(root->right);
    }
    cout<<root->data<<" ";
    a.pop();
    if(!a.empty())
    {
        LevelOrder(a.Front());
    }
}
