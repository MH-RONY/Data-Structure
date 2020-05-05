#include<stdio.h>
int left_child(int parent_index)
{
    return 2*parent_index;
}
int right_child(int parent_index)
{
    return (2*parent_index)+1;
}
int parent(int child)
{
    return child/2;
}

void max_heapify(int heap[],int heap_size,int parent_index)
{
    int l,r,largest,t;
    l=left_child(parent_index);
    r=right_child(parent_index);
    if(l<=heap_size && heap[l]>heap[parent_index])
    {
        largest=l;
    }
    else
    {
        largest=parent_index;
    }
    if(r<=heap_size && heap[r]>heap[largest])
    {
        largest=r;
    }

    if(largest!=parent_index)
    {
        t=heap[parent_index];
        heap[parent_index]=heap[largest];
        heap[largest]=t;

        max_heapify(heap,heap_size,largest);
    }
}

void mini_heapify(int heap[],int heap_size,int parent_index)
{
    int l,r,smallest,t;
    l=left_child(parent_index);
    r=right_child(parent_index);
    if(l<=heap_size && heap[l]<heap[parent_index])
    {
        smallest=l;
    }
    else
    {
        smallest=parent_index;
    }
    if(r<=heap_size && heap[r]<heap[smallest])
    {
        smallest=r;
    }
    if(smallest!=parent_index)
    {
        t=heap[parent_index];
        heap[parent_index]=heap[smallest];
        heap[smallest]=t;

        mini_heapify(heap,heap_size,smallest);
    }
}

void build_max_heapify(int heap[],int heap_size)
{
    int parent_index=heap_size/2;
    for(int i=parent_index;i>=1;i--)
    {
        max_heapify(heap,heap_size,i);
    }
}

void build_mini_heapify(int heap[],int heap_size)
{
    int parent_index=heap_size/2;
    for(int i=parent_index;i>=1;i--)
    {
        mini_heapify(heap,heap_size,i);
    }
}

 void heap_max_sort(int heap[],int heap_size)
 {
     build_max_heapify(heap,heap_size);
     int i=heap_size,t;
     while(i>=1)
     {
         t=heap[i];
         heap[i]=heap[1];
         heap[1]=t;
         i--;
         max_heapify(heap,i,1);
     }
 }

 void heap_mini_sort(int heap[],int heap_size)
 {
     build_mini_heapify(heap,heap_size);
     int i=heap_size,t;
     while(i>=1)
     {
         t=heap[i];
         heap[i]=heap[1];
         heap[1]=t;
         i--;
         mini_heapify(heap,i,1);
     }
 }

 void print(int heap[],int heap_size)
 {
     for(int i=1;i<=heap_size;i++)
     {
         printf("%d ",heap[i]);
     }
 }

 int main()
 {
     int heap[]={0,40,38,20,29,35,19,17,26,21};
     int heap_size=(sizeof(heap)/sizeof(heap[0]))-1;
     print(heap,heap_size);
     printf("\n");

     heap_max_sort(heap,heap_size);
     print(heap,heap_size);
     printf("\n");

     heap_mini_sort(heap,heap_size);
     print(heap,heap_size);
     printf("\n");

 }
