#include <iostream>

using namespace std;

class queue
{
private:

    int a[3];
    int front=-1, rear=-1;
    int count=0;

public:

    void enqueue(int x)
    {
        if(front==-1)
        {
            count=count+1;
            a[0]=x;
            front=front+1;
            rear=rear+1;
        }
        else if(count==3)
        {
            cout<<"Queue is full!"<<endl;
            return;
        }
        else
        {
            count=count+1;
            rear=(rear+1)%3;
            a[rear]=x;
        }
    }

    void dequeue()
    {

        if(front==-1)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else if(front==rear)
        {
            count=count-1;
            front=-1;
            rear=-1;
        }
        else
        {
            count=count-1;
            front=(front+1)%3;
        }
    }

    void Front()
    {
        if(front==-1)
        {
            cout<<"Queue is empty!"<<endl;
        }
        else
        {
            cout<<a[front]<<endl;
        }
    }

    int IsEmpty()
    {
        if(front==-1)
        {
            cout<<"Empty!"<<endl;
            return 1;
        }
        else
        {
            cout<<"Not Empty!"<<endl;
            return 0;
        }

    }

    void print()
    {
        int i;
        cout<<"The elements in the queue are: ";
        for(i=front; i!=rear; i=(i+1)%3)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[rear]<<" ";
        cout<<endl;
    }
};

int main()
{
    queue d;
    d.IsEmpty();
    d.enqueue(7);
    d.enqueue(11);
    d.enqueue(13);
    d.Front();
    d.IsEmpty();
    d.print();
    d.dequeue();
    d.Front();
    d.dequeue();
    d.enqueue(19);
    d.print();
    d.enqueue(23);
    d.Front();
    d.print();
    d.enqueue(31);
    d.dequeue();
    d.enqueue(31);
    d.Front();
    d.print();

    return 0;
}
