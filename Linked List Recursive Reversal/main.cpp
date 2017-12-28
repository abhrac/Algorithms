#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head;

void Insert(int x);
void Print();
void Reverse(Node* p);

int main()
{
    int x, n, i;
    head=NULL;
    cout<<"Please enter the number of elements in the linked list:"<<endl;
    cin>>n;
    cout<<"Please enter the elements:"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    Print();
    Reverse(head);
    cout<<"After reversing:"<<endl;
    Print();

    return 0;
}

void Insert(int data)
{
    if(head==NULL)
    {
        Node* temp=new (struct Node);
        temp->data=data;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        Node* temp1=new(struct Node);
        Node* temp=head;
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

void Print()
{
    Node* temp=head;
    cout<<"The elements of the linked list are: ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Reverse(Node* p)
{
    Node* temp=p;
    if(temp->next==NULL)
    {
        head=p;
        return;
    }
    Reverse(p->next);
    Node* q=p->next;
    q->next=p;
    p->next=NULL;
}
