#include <iostream>

using namespace std;

struct Node1
{
    int data;
    Node1* next;
};

class stack
{
private:

struct Node
{
    Node1* data;
    Node* next;
};

    Node* top=NULL;

public:

    void push(Node1* data)
    {
        if(top==NULL)
        {
            Node* temp=new (struct Node);
            temp->data=data;
            temp->next=NULL;
            top=temp;
        }
        else
        {
            Node* temp=new (struct Node);
            temp->data=data;
            temp->next=top;
            top=temp;
        }
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty!"<<endl;
        }
        else
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    Node1* Top()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty!"<<endl;
            return 0;
        }
        return top->data;
    }

    bool IsEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        Node* temp=top;
        cout<<"Stack: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

void Insert(int data);
void print();
void reverse();

Node1* head;

int main()
{
    head=NULL;
    int n, x, i;
    cout<<"Please enter the number of elements in the linked list:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    print();
    reverse();
    cout<<"After reversing:"<<endl;
    print();

    return 0;
}

void Insert(int data)
{
    if(head==NULL)
    {
        Node1* temp=new (struct Node1);
        temp->data=data;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        Node1* temp1=new (struct Node1);
        Node1* temp=head;
        temp1->data=data;
        temp1->next=NULL;
        while(temp!=NULL)
        {
            if(temp->next==NULL)
            {
                temp->next=temp1;
                temp=temp->next;
            }
            temp=temp->next;
        }
    }
}

void print()
{
    Node1* temp=head;
    cout<<"The elements of the linked list are: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse()
{
    Node1* temp=head;
    stack a ;
    while(temp!=NULL)
    {
        a.push(temp);
        temp=temp->next;
    }
    head=a.Top();
    while(!a.IsEmpty())
    {
        temp=a.Top();
        a.pop();
        if(a.IsEmpty())
        {
            temp->next=NULL;
            break;
        }
        temp->next=a.Top();
    }
}
