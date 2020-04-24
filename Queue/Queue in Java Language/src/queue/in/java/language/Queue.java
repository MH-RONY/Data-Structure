package queue.in.java.language;



public class Queue {
    
    private final int QUEUE_SIZE=5;
    private int head,tail;
    private int[] data=new int[QUEUE_SIZE+1];
    
    void set_value(int head,int tail)
    {
        this.head=head;
        this.tail=tail;
    }
    
    void enqueue(Queue s,int item)
    {
        if((tail+1)%(QUEUE_SIZE+1)==head)
        {
            System.out.println("Queue is Full!");
            return;
        }
        data[tail]=item;
        tail=(tail+1)%(QUEUE_SIZE+1);
    }
    
    int dequeue(Queue s)
    {
        if(head==tail)
        {
            System.out.println("Queue is Empty!");
            return -1;
        }
        int item=data[head];
        head=(head+1)%(QUEUE_SIZE+1);
        return item;
    }
    
}
