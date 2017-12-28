#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
Node* head;
Node* head1;
void Insert(int x);
void Print(Node* head);
void Reverse();
int main()
{
    head=NULL;
    head1==NULL;
    int n, x, i;
    cout<<"Please enter the number of elements in the linked list"<<endl;
    cin>>n;
    cout<<"Please enter the elements"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    Print(head);
    cout<<"After reversing:"<<endl;
    Reverse();
    Print(head1);
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

void Print(Node* head)
{
    Node* temp=head;
    cout<<"The elements in the list are"<<endl;
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
    while(temp!=NULL)
    {
        if(head1==NULL)
        {
          Node* temp1=new (struct Node);
          temp1->data=temp->data;
          temp1->next=NULL;
          head1=temp1;
        }
        else
        {
            Node* temp1=new (struct Node);
            temp1->data=temp->data;
            temp1->next=head1;
            head1=temp1;
        }
        temp=temp->next;
    }

}
