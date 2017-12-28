#include <iostream>

using namespace std;

class stack
{
private:

    struct Node
    {
        int data;
        Node* next;
    };

    Node* top=NULL;
    int count=1;

public:

    void push(int data)
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
            cout<<"Stack is empty! "<<endl;
        }
        else
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    void Top()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty: "<<endl;
        }
        else
        {
            cout<<top->data<<endl;
        }
    }

    bool IsEmpty()
    {
        if(top==NULL)
        {
            return 1;
        }
        return 0;
    }

    void print()
    {
        execprint(top);
    }

    void execprint(Node* t)
    {
        if(count==1)
        {
           count=count+1;
           cout<<"The elements in the stack are: ";
           execprint(t->next);
           cout<<t->data<<" ";
           cout<<endl;
        }
        else
        {
            if(t->next!=NULL)
            {
                count=count+1;
                execprint(t->next);
            }
            cout<<t->data<<" ";
            count=count-1;
        }
    }
};

int main()
{
    stack a;
    cout<<a.IsEmpty()<<endl;
    a.push(7);
    a.push(11);
    a.push(19);
    a.Top();
    a.print();
    a.pop();
    a.push(29);
    cout<<a.IsEmpty()<<endl;
    a.push(31);
    a.Top();
    a.print();

    return 0;
}
