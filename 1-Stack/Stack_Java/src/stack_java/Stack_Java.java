package stack_java;

public class Stack_Java {

    public static void main(String[] args) {
        int receiver;
         Stack ob=new Stack();
         ob.top=-1;
         
         ob.push(ob, 12);
         ob.push(ob, 14);
         ob.push(ob, 45);
         ob.push(ob, 28);
         
         System.out.println("Return value= "+(receiver=ob.pop(ob)));
         System.out.println("Return value= "+(receiver=ob.pop(ob)));
         System.out.println("Return value= "+(receiver=ob.pop(ob)));
         System.out.println("Return value= "+(receiver=ob.pop(ob)));
         
       
    }
}
    
    class Stack{
        final int STACK_MAX=3;
        int top;
        int[] data=new int[STACK_MAX];
        
        void push(Stack s,int item)
        {
            if(top<STACK_MAX-1)
            {
                top=top+1;
                data[top]=item;
            }
            else
                System.out.println("Stack is Full!\n");
        }
        
        int pop(Stack s)
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
    }
