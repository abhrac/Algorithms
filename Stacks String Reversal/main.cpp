#include <iostream>

using namespace std;

class stack
{

private:

    struct Node
    {
        char data;
        Node* next;
    };

    Node* top=NULL;

public:

    void push(char data)
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
            cout<<"Stack is empty!";
        }
        else
        {
            Node* temp=top;
            top=top->next;
            delete temp;
        }
    }

    int Top()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty!";
            return 0;
        }
        else
        {
            return top->data;
        }
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
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    int i;
    string s;
    cout<<"Please enter a string:"<<endl;
    cin>>s;
    stack a;
    for(i=0; i<s.length(); i++)
    {
        a.push(s[i]);
    }
    i=0;
    while(!a.IsEmpty())
    {
        s[i]=a.Top();
        a.pop();
        i++;
    }
    cout<<"The reversed string is:"<<endl<<s<<endl;

    return 0;
}
