package queue.in.java.language;

import java.util.Scanner;

public class QueueInJavaLanguage {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        Queue obj=new Queue();
        int x;
        
        obj.set_value(0, 0);
        
        obj.enqueue(obj, 10);
        obj.enqueue(obj, 20);
        obj.enqueue(obj, 30);
        
        System.out.println(obj.dequeue(obj));
        System.out.println(obj.dequeue(obj));
        
        for(int i=0;i<2;i++)
        {
            System.out.print("Enter enqueue value= ");
            x=input.nextInt();
            obj.enqueue(obj, x);
        }
        
        System.out.println(obj.dequeue(obj));
        System.out.println(obj.dequeue(obj));
        System.out.println(obj.dequeue(obj));
        System.out.println(obj.dequeue(obj));
       
    }
    
}
