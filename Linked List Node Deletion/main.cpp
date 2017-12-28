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
void Delete(int pos);
int main()
{
    head=NULL;
    int n, x, i, pos;
    cout<<"Please enter the number of elements in the linked list"<<endl;
    cin>>n;
    cout<<"Please enter the elements"<<endl;
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    Print();
    cout<<"Please enter the position of the node to be deleted"<<endl;
    cin>>pos;
    Delete(pos);
    cout<<"After deleting:"<<endl;
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
    cout<<"The elements in the linked list are:"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void Delete(int pos)
{
    if(pos==0)
    {
        Node* temp=head;
        head=temp->next;
        delete temp;
    }

    else
    {
        Node* temp=head;
        Node* temp1;
        int n=0;
        while(n<(pos-1))
        {
            temp=temp->next;
            n=n+1;
        }
        temp1=temp;
        temp1=temp1->next;
        temp->next=temp1->next;
        delete temp1;
    }

}
