#include<iostream>
using namespace std;
#define STACK_MAX 3
class Stack{

private:
    int top;
    int data[STACK_MAX];
public:
    void set_value(int top)
    {
        this->top=top;
    }

    void push(Stack *s,int item)
    {
        if(top < STACK_MAX-1)
        {
            top=top+1;
            data[top]=item;
        }
        else
            cout<<"Stack is Full!\n";
    }
    int pop(Stack *s)
    {
        int item;
        if(top>=0)
        {
            item=data[top];
            top=top-1;
            return item;
        }
        return -1;
    }
};

int main()
{
    Stack my_stack;
    int receiver;

    my_stack.set_value(-1);

    my_stack.push(&my_stack,5);
    my_stack.push(&my_stack,4);
    my_stack.push(&my_stack,8);
    my_stack.push(&my_stack,1);

    receiver=my_stack.pop(&my_stack);
    cout<<"Return value= "<<receiver<<endl;
    receiver=my_stack.pop(&my_stack);
    cout<<"Return value= "<<receiver<<endl;
    receiver=my_stack.pop(&my_stack);
    cout<<"Return value= "<<receiver<<endl;
    receiver=my_stack.pop(&my_stack);
    cout<<"Return value= "<<receiver<<endl;
}
