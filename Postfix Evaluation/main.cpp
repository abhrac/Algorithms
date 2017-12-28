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
            cout<<"Stack is empty!"<<endl;
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
        else
        {
            return false;
        }
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
    string s;
    stack a;
    int res, num=0;
    cin>>s;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            while(s[i]!=',' && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/')
            {
                num=(num*10)+((int)s[i]-48);
                i++;
            }
            i--;
            a.push((num));
            num=0;
        }
        else if(s[i]==',')
        {
            continue;
        }
        else
        {
            int op2=a.Top();
            a.pop();
            int op1=a.Top();
            a.pop();
            if(s[i]=='+')
            {
                res=op1+op2;
                a.push(res);
            }
            else if(s[i]=='-')
            {
                res=op1-op2;
                a.push(res);
            }
            if(s[i]=='*')
            {
                res=op1*op2;
                a.push(res);
            }
            if(s[i]=='/')
            {
                res=op1/op2;
                a.push(res);
            }
        }
    }
    cout<<res<<endl;

    return 0;
}
