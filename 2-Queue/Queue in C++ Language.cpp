#include<iostream>
using namespace std;
#define QUEUE_SIZE 5

class Queue{

private:
    int head,tail;
    int data[QUEUE_SIZE+1];

public:
    void set_value(int head,int tail)
    {
        this->head=head;
        this->tail=tail;
    }

    void enqueue(Queue *s,int item)
    {
        if((s->tail+1)%(QUEUE_SIZE+1)==s->head)
        {
            cout<<"Queue is Full!"<<endl;
            return;
        }
        s->data[s->tail]=item;
        s->tail=(s->tail+1)%(QUEUE_SIZE+1);
    }

    int dequeue(Queue *s)
    {
        int item;

        if(s->head==s->tail)
        {
            cout<<"Queue is Empty!"<<endl;
            return -1;
        }

        item=s->data[s->head];
        s->head=(s->head+1)%(QUEUE_SIZE+1);
        return item;
    }

};

int main()
{
    Queue obj;
    obj.set_value(0,0);
    int n;

    for(int i=0;i<3;i++)
    {
        cout<<"Enter a Enqueue value= ";
        cin>>n;                                     //if you want to keep input  system
        obj.enqueue(&obj,n);
    }

    cout<<obj.dequeue(&obj)<<endl;
    cout<<obj.dequeue(&obj)<<endl;

    obj.enqueue(&obj,40);                         //Direct initialize value
    obj.enqueue(&obj,50);

    cout<<"\n"<<obj.dequeue(&obj)<<endl;
    cout<<obj.dequeue(&obj)<<endl;
    cout<<obj.dequeue(&obj)<<endl;
    cout<<obj.dequeue(&obj)<<endl;

}
