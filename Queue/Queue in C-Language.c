#include<stdio.h>
#define QUEUE_SIZE 5

typedef struct{
int head,tail;
int data[QUEUE_SIZE+1];

}Queue;

void enqueue(Queue *s,int item)
{
    if((s->tail+1)%(QUEUE_SIZE+1)==s->head)
    {
        printf("Queue is Full!\n");
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
        printf("Queue is Empty!\n");
        return -1;
    }
    item=s->data[s->head];
    s->head=(s->head+1)%(QUEUE_SIZE+1);
    return item;
}

int main()
{
    Queue obj;
    obj.head=0;obj.tail=0;

    enqueue(&obj,10);
    enqueue(&obj,20);
    enqueue(&obj,30);
    enqueue(&obj,40);
    enqueue(&obj,50);

    printf("%d\n",dequeue(&obj));
    printf("%d\n",dequeue(&obj));
    printf("%d\n",dequeue(&obj));

    enqueue(&obj,50);
    enqueue(&obj,55);
    enqueue(&obj,60);

    printf("\n%d\n",dequeue(&obj));
    printf("%d\n",dequeue(&obj));
    printf("%d\n",dequeue(&obj));
    printf("%d\n",dequeue(&obj));
    printf("%d\n",dequeue(&obj));


    return 0;



}
