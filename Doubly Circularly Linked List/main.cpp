#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
};
Node* head;
void Insert(int x);
void Print();

int main()
{
    head=NULL;
    int n, x, i;
    cout<<"Please enter the number of elements in the Linked List"<<endl;
    cin>>n;
    cout<<"Please enter the elements"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    Print();
    return 0;
}

void Insert(int x)
{
    if(head==NULL)
    {
        Node* temp= new (struct Node);
        head=temp;
        temp->data=x;
        temp->next=head;
        temp->prev=head;
    }
    else
    {
        Node* temp1=new(struct Node);
        Node* temp=head;
        temp1->data=x;
        temp1->next=head;
        temp->prev=temp1;
        while(temp->next!=head)
        {
           temp=temp->next;
        }
        temp->next=temp1;
        temp1->prev=temp;
    }
}

void Print()
{
    Node* temp=head;
    cout<<"The elements of the Linked List are:"<<endl;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=temp->prev;
    cout<<"The elements of the list in reverse order are:"<<endl;
    cout<<temp->data<<" ";
    temp=temp->prev;
    while(temp!=head->prev)
    {
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
