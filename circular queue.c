/*
program for circular queue:
o/p:
Enter choices:
1.enqueue 2.dequeue 3.display
1
enter element:
12
Do you want to continue?
1
Enter choices:
1.enqueue 2.dequeue 3.display
1
enter element:
45
Do you want to continue?
1
Enter choices:
1.enqueue 2.dequeue 3.display
1
enter element:
78
Do you want to continue?
1
Enter choices:
1.enqueue 2.dequeue 3.display
3
Entered data is
 12 45 78
Do you want to continue?
0

*/

#include<stdio.h>
#define max 4

int queue[max];
int front =-1,rear=-1;

void enqueue();
void dequeue();
void display();
void main()
{
    int ch,d,y;
    do
    {
        printf("Enter choices:\n");
        printf("1.enqueue 2.dequeue 3.display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            enqueue();
            break;
            
            case 2:
            dequeue();
            
            break;
            
            case 3:
            printf("Entered data is\n");
            display();
            break;
            
        }
        printf("\nDo you want to continue?\n");
        scanf("%d",&y);
        
    }
    while(y==1);
}
void enqueue()
{
    int d;
    printf("enter element:\n");
    scanf("%d",&d);
    if((rear+1)%max == front || (rear == max-1 && front==0))
    {
        printf("Queue is Full\n");
        return;
    }
    else if(rear==-1)
    {
        front=rear=0;
        queue[rear] = d;
        
    }
    else
    {
        rear = (rear+1)%max;
        queue[rear]=d;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Empty\n");
        return;
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front = (front+1)%max;
    }
    //return d;
}
void display()
{
    if(rear>front)
    {
        for(int i=front;i<=rear;i++)
        {
            printf(" %d",queue[i]);
        }
    }
    else if(front>rear)
    {
        for(int i=front;i<max;i++)              //front>rear
        {
           printf(" %d",queue[i]);
           for(int i=0;i<=rear;i++)
           {
               printf(" %d ",queue[i]);
           }
        }
        
    }
    else
    {
        printf("Empty\n");
    }
}
