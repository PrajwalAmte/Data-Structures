#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head;

void push()
{
    int value;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //Overflow condition
    if (newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d",&value);

        //If list is empty
        if(head == NULL)
        {
            newNode->data = value;
            newNode->next = NULL;
            head = newNode;
        }
        else
        {
            newNode->data = value;
            newNode->next = head;
            head = newNode;
        }
        printf("\nItem pushed");
    }
}

void pop()
{
    int item;
    struct Node *newNode;
    if (head == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        item = head->data;
        newNode = head;
        head = head->next;
        free(newNode);
        printf("\nItem Popped");
    }
}

void display()
{
    int i;
    struct Node *newNode;
    newNode = head;

    if(newNode == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        while(newNode != NULL)
        {
            printf("\n%d", newNode->data);
            newNode = newNode->next;
        }
    }
}

int main()
{
    int ch;
    printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");

    while (ch != 4)
    {
    printf("\n\nEnter the choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: push();
        break;
        case 2: pop();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        break;
        default: printf("\nInvalid input");
    }

    }
}