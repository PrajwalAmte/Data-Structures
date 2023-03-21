#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front;
struct Node *rear;

void insert()
{
    int item;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //Overflow condition
    if(newNode == NULL)
    {
        printf("\nOverflow");
    }
    else{
        printf("\nEnter the value: ");
        scanf("%d",&item);
        newNode->data = item;
        if(front == NULL)
        {
            front = newNode;
            rear = newNode;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear->next = NULL;
        }
        printf("\nNode enqueued");
    }
}

void delete()
{
    struct Node *newNode;

    if(front == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        newNode = front;
        front = front->next;
        free(newNode);
        printf("\nNode dequeued");
    }
}
void display()
{
    struct Node *newNode;
    newNode = front;

    if(front == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        while(newNode != NULL)
        {
            printf("\n%d ", newNode->data);
            newNode = newNode->next;
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