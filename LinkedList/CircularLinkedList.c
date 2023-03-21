#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void insertBegin()
{
    struct Node *currNode;
    int new_data;

    //Dynamically allocating space for linkedlist
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //If linkedlist is empty
    if(newNode == NULL)
    {
        printf("\nOverflow");
    }

    else 
    {
        //Taking new data as input
        printf("\nEnter the node data: ");
        scanf("%d",&new_data);

        //Assising new data as data for newNode
        newNode->data = new_data;

        //When there are no nodes in it
        if(head == NULL)
        {
            //Assining head as newNode
            head = newNode;

            //Pointing next of node to itself
            newNode->next = head;
        }
        else
        {
            //Poninting currNode at head to iterate it lastNode (head)
            currNode = head;

            //Iterate till last or head back as it is circular
            while(currNode->next != head)
            {
                currNode = currNode->next;
            }
            //head will be next of newNode
            newNode->next = head;

            //And newNode will be next of currNode (which is at end)
            currNode->next = newNode;
            
            //Making newNode as new head
            head = newNode;
        }
        printf("\nNode inserted");
    }
}

void insertLast()
{
    struct Node *currNode;
    int new_data;

    //Dynamically allocating space for newnode
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //If no empty space in list
    if (newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        //Taking new_data as input
        printf("\nEnter the node data: ");
        scanf("%d",&new_data);

        //Assining new_data to newNode
        newNode->data = new_data;

        //when are no nodes in list
        if(head == NULL)
        {
            //Making newNode as head
            head = newNode;

            //Pointing next of newNode to itself
            newNode->next = head;
        }
        else
        {
            //Pointing currNode at head to iterate till last node
            currNode = head;

            //Iterating till next node is not head (i.e till last node)
            while(currNode->next != head)
            {
                currNode = currNode->next;
            }
            //Making newNode as next of currNode , which is last node
            currNode->next = newNode;

            //and head will next of newNode
            newNode->next = head;
        }
        printf("\nNode inserted");
    }
}

void deleteBegin()
{
    struct Node *currNode;

    //If list is empty
    if(head == NULL)
    {
        printf("\nUnderflow");
    }
    //If there is only 1 node
    else if(head->next == NULL)
    {
        //Making head as NULL
        head = NULL;

        //And deallocating the head
        free(head);

        printf("\nNode deleted");
    }
    //More than 1 element
    else
    {
        //Pointing Node to head
        currNode = head;

        //Iterating till end of list
        while(currNode->next != head)
        {
            currNode = currNode->next;
        }
        //making next of head as next of node at end
        currNode->next = head->next;
        
        //Dynamically deallocating the head
        free(head);

        //making new head as next of currNode(at end)
        head = currNode->next;

        printf("\nNode deleted");
    }
}

void deleteLast()
{
    struct Node *currNode, *prevNode;

    //When list is empty
    if(head == NULL)
    {
        printf("\nUnderflow");
    }
    //when there is only one element
    else if(head->next == head)
    {
        //Make head as NULL
        head = NULL;

        //And deallocete the space occupied by head
        free(head);

        printf("\nNode deleted");
    }
    //More than one node
    else
    {
        //Point currNode at head to iterate till end
        currNode = head;

        //Iterating till end
        while(currNode != head)
        {
            //Assining prevNode as currNode
            prevNode = currNode;

            //and iterating currNode
            currNode = currNode->next;
        }
        //Making next of currNode as next of prevNode
        prevNode->next = currNode->next;

        //Deallocatiig space of currNode
        free(currNode);

        printf("\nNode deleted");
    }
}

void display()
{
    struct Node *currNode;

    //pointing currNode to head
    currNode = head;

    //If list is empty
    if(head == NULL)
    {
        printf("\nNothing to print");
    }
    else
    {
        printf("\nPrinting values: ");

        //Iterate through the list
        do
        {
            printf("%d ",currNode->data);
            currNode = currNode->next;
        } while(currNode->next != head);
    }
}

int main()
{
    int ch;
    printf("\n1.Insert node from start.\n2.Insert node at end.\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Exit");
    do{
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insertBegin();
            break;
            case 2: insertLast();
            break;
            case 3: deleteBegin();
            break;
            case 4: deleteLast();
            break;
            case 5: display();
            break;
            case 6: exit(0);
            break;
            default:printf("\nInvalid input");
        }
    } while (ch != 8);

    return 0;
}