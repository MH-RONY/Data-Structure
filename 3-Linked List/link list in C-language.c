#include<stdio.h>
typedef struct node Node;

struct node{
int data;
Node *next;
};

Node *create_node(int item,Node *node)  //to create new node.we need two object,that's one is data and other is next node location.
{
    Node *new_node=(Node*) malloc(sizeof(Node));  //we define a memory location(pointer) for create_node.
    if(new_node==NULL)                        // if computer doesn't give memory location.we print error message.
    {
        printf("Error!Memory location doesn't found.");
        exit(1);
    }
    new_node->data=item;
    new_node->next=node;
    return new_node;  //create_node(int item,Node *node) function all time return recently created node address;
}

Node *prepand(int item,Node *head)
{
    Node *new_node=create_node(item,head);
    return new_node;
}

Node *append(int item,Node *head)
{

    Node *new_node=create_node(item,NULL);
    Node *current_node=head;
    if(current_node==NULL)
    {
        printf("Node is Empty\n");
    }
    while(current_node->next != NULL)
    {
        current_node=current_node->next;
    }
    current_node->next =new_node;
    return new_node;
}

void *insert(int item,int n,Node *head)
{
    Node *current_node=head;
    for(int i=1;i<=n-2;i++)
    {
        current_node=current_node->next;
    }
    Node *new_node=create_node(item,current_node->next);
    current_node->next=new_node;
}

Node *remove_node(int n,Node *head)
{
    Node *current_node_previous=head;
    Node *current_node=head;
    int count=0;

    if(n==1)
    {
        current_node=current_node->next;
        free(head);
        return current_node;
    }
    while(current_node!=NULL)
    {
    current_node=current_node->next;
    count++;
    }
    if(n>=2 && n<=count)
    {
        for(int i=1;i<=n-2;i++)
            {
                current_node_previous=current_node_previous->next;
            }

        current_node=current_node_previous->next;
        current_node_previous->next=current_node->next;
        free(current_node);
        return head;
    }
    else
    {
        printf("Invalid.Size of Link list= %d\n",count);
    }
    return head;
}

void linked_list_print(Node *head)
{
    Node *current_node=head;
    if(current_node==NULL)
    {
        printf("There are no Node.");
    }
    while(current_node!=NULL)
    {
        printf("%d ",current_node->data);
        current_node=current_node->next;
    }
    printf("\n");
}

int main()
{
    Node *head;
    head=create_node(5,NULL); //2 no linked list
    head=prepand(3,head); //1 no linked list
    append(8,head);   //4 no linked list
    append(10,head); //5 no linked list
    append(12,head); //6 no linked list
    insert(4,3,head); //3 no linked list
    remove_node(6,head); //2 no node will remove that means value(5);
    linked_list_print(head);
    return 0;
}
