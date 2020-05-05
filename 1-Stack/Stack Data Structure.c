#include<stdio.h>
#define STACK_MAX 3

typedef struct{
    int top;
    int data[STACK_MAX];
}Stack;

void push(Stack *s,int item)
{
    if(s->top < (STACK_MAX-1))
    {
        s->top=s->top+1;
        s->data[s->top]=item;
    }
    else
    {
        printf("Stack is Full!\n");
    }
}

int pop(Stack *s)
{
    int item;

    if(s->top >= 0)
    {
        item=s->data[s->top];
        s->top=s->top-1;
        return item;
    }

    return -1;
}

int main()
{
    Stack my_stack;
    int receiver;

    my_stack.top=-1;

    push(&my_stack,5);
    push(&my_stack,7);
    push(&my_stack,4);
    push(&my_stack,8); //Since STACK_MAX=3,so print Stack is Full!

    printf("Return Value= %d\n",receiver=pop(&my_stack));
    printf("Return Value= %d\n",receiver=pop(&my_stack));
    printf("Return Value= %d\n",receiver=pop(&my_stack));
    printf("Return Value= %d\n",receiver=pop(&my_stack));  //top is not possible less than 0,so print -1;

    return 0;
}
