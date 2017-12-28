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
    string s, res="";
    cin>>s;
    stack a;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            res=res+s[i];
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='(' || s[i]==')')
        {
            if(a.IsEmpty())
            {
                a.push(s[i]);
            }
            else
            {
                if(s[i]=='/' || s[i]=='(')
                {
                    a.push(s[i]);
                }
                else if(s[i]=='*')
                {
                    if(a.Top()=='/')
                    {
                        while(!a.IsEmpty() && a.Top()=='/' && a.Top()!='(')
                        {
                            res=res+a.Top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                    else
                    {
                        a.push(s[i]);
                    }
                }
                else if(s[i]=='+')
                {
                    if(a.Top()!='-')
                    {
                        while(!a.IsEmpty() && a.Top()!='-' && a.Top()!='(')
                        {
                            res=res+a.Top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                    else
                    {
                        a.push(s[i]);
                    }
                }
                else if(s[i]=='-')
                {
                   if(a.Top()!='-')
                    {
                        while(!a.IsEmpty() && a.Top()!='-' && a.Top()!='(')
                        {
                            res=res+a.Top();
                            a.pop();
                        }
                        a.push(s[i]);
                    }
                    else
                    {
                        a.push(s[i]);
                    }
                }
                else if(s[i]==')')
                {
                    while(a.Top()!='(')
                    {
                        res=res+a.Top();
                        a.pop();
                    }
                    a.pop();
                }
            }
        }
    }
    while(!a.IsEmpty())
    {
        res=res+a.Top();
        a.pop();
    }
    cout<<res;

    return 0;
}
