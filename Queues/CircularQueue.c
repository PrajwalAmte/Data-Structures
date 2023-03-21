#include <stdio.h>
#include <stdlib.h>
#define max 6
int queue[max];
int front = -1;
int rear = -1;

void enqueue()
{
    int item;
    printf("\nEnter the item to be inserted: ");
    scanf("%d",&item);

    //If Queue is empty
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = item;
        printf("\n%d enqueued", queue[rear]);
    }
    //If queue is full
    else if((rear+1)%max == front)
    {
        printf("\nOverflow");
    }
    else
    {
        //incrementing raear
        rear = (rear + 1) % max;
        //Assigning a value to the queue
        queue[rear] = item;
        printf("\n%d enqueued", queue[rear]);
    }
}

void dequeue()
{
    //If Queue is empty
    if(front == -1 && rear == -1)
    {
        printf("\nUnderflow");
    }
    else if(front == rear)
    {
        printf("\n%d dequeued", queue[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\n%d dequeued", queue[front]);
        front = (front + 1) % max;
    }
}

void display()
{
    int i = front;
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        while(i <= rear)
        {
            printf("\n%d",queue[i]);
            i = (i + 1) % max;
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
            case 1: enqueue();
            break;
            case 2: dequeue();
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