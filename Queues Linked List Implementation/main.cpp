#include <iostream>

using namespace std;

class queue
{
private:

    struct Node
    {
        int data;
        Node* next;
    };
    Node* front=NULL;
    Node* rear=NULL;

public:

    void enqueue(int data)
    {
        if(front==NULL)
        {
            Node* temp=new (struct Node);
            temp->data=data;
            temp->next=NULL;
            front=temp;
            rear=temp;
        }
        else
        {
            Node* temp=new (struct Node);
            temp->data=data;
            temp->next=NULL;
            rear->next=temp;
            rear=temp;
        }
    }

    void dequeue()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else if(front==rear)
        {
            Node* temp=front;
            front=NULL;
            rear=NULL;
            delete temp;
        }
        else
        {
            Node* temp=front;
            front=front->next;
            delete temp;
        }
    }

    void Front()
    {
        if(front==NULL)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else
        {
            cout<<front->data<<endl;
        }
    }

    bool IsEmpty()
    {
        if(front==NULL)
        {
            cout<<"Empty!"<<endl;
            return true;
        }
        cout<<"Not Empty!"<<endl;
        return false;
    }

    void print()
    {
        Node* temp=front;
        cout<<"The elements in the queue are: ";
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    queue a;
    a.IsEmpty();
    a.enqueue(1);
    a.enqueue(2);
    a.enqueue(3);
    a.Front();
    a.print();
    a.dequeue();
    a.Front();
    a.print();
    a.enqueue(5);
    a.IsEmpty();
    a.enqueue(7);
    a.Front();
    a.print();

    return 0;
}
