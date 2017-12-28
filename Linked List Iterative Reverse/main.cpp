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
void Reverse();
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
    Reverse();
    cout<<"After reversing:"<<endl;
    Print();
    return 0;
}

void Insert(int x)
{
    if(head==NULL)
    {
        Node* temp=new (struct Node);
        temp->data=x;
        temp->next=NULL;
        head=temp;
    }
    else
    {
        Node* temp1=new (struct Node);
        Node* temp=head;
        temp1->data=x;
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
    cout<<"The elements of the Linked List are:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Reverse()
{
    Node* temp=head;
    Node* current=head;
    Node* temp1;
    temp1=current->next;
    temp->next=NULL;
    current=temp1;
    temp1=temp1->next;
    current->next=temp;
    head=current;
    while(temp1!=NULL)
    {
        temp=current;
        current=temp1;
        temp1=temp1->next;
        if(current->next==NULL)
        {
            current->next=temp;
            head=current;
        }
        current->next=temp;
    }
}
