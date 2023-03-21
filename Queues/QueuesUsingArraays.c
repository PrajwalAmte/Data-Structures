#include<stdio.h>
#include<stdlib.h>
#define maxsize 5

int front = -1, rear = -1;
int queue[maxsize];

void insert()
{
    int item;
    printf("\nEnter the element: ");
    scanf("%d",&item);

    if(rear == maxsize-1)
    {
        printf("\nOverflow");
    }
    else
    {
        if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = rear+1;
        }
        queue[rear] = item;
        printf("\nValue inserted");
    }
}

void delete()
{
    int item;
    if(front == -1 || front > rear)
    {
        printf("\nUnderflow");
    }
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front +1;
        }
        printf("\nValue deleted");
    }
}

void display()
{
    int i;
    if(rear == -1)
    {
        printf("\nEmpty queue");
    }
    else
    {
        for(i = front; i <= rear; i++)
        {
            printf("\n%d ",queue[i]);
        }
    }
}

int main()
{
    int ch;
    printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit");
    while(ch != 4)
    {
        printf("\n\nEnter the choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert();
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: exit(0);
            break;
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}