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
        Node* temp=new (struct Node);
        temp->data=data;
        temp->next=top;
        top=temp;
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

    char Top()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty!"<<endl;
            return NULL;
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
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    stack a;
    int f=0;
    string s;
    cout<<"Please enter a string of parentheses:"<<endl;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            a.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}' || s[i]==']')
        {
            if(a.IsEmpty()==true)
            {
                f=1;
                break;
            }
            else if((s[i]==')' && a.Top()!='(') || (s[i]=='}' && a.Top()!='{') || (s[i]==']' && a.Top()!='['))
            {
                f=1;
                break;
            }
            else
            {
                a.pop();
            }
        }
    }
    if(f==1 || a.IsEmpty()==false)
    {
        cout<<"Parentheses are not balanced!"<<endl;
    }
    else
    {
        cout<<"Parentheses are balanced!"<<endl;
    }

    return 0;
}
