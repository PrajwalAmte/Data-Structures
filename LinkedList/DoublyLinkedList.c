#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int data;
};

struct Node *head;

//insert the data from beginning
void insertBegin()
{
    struct Node *newNode;
    int data;
    //Dynamically allocating space for newNode
    newNode = (struct Node *) malloc(sizeof(struct Node));

    //When there is no free space in list 
    if (newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter data value: ");
        scanf("%d", &data);
    
    //If list is empty
    if(head == NULL)
    {
        //Assigning next and previous nodes as NULL
        newNode->next = NULL;  
        newNode->prev = NULL;

        //Assigning data to newNode
        newNode->data = data;

        //Assigning head as newNode
        head = newNode;
    }

    else
    {
        newNode->data = data;

        //Assigning previos of newNode as NULL
        newNode->prev = NULL;

        //Assiging head as next of newNode
        newNode->next = head;

        //Assigning previos of head as newNode
        head->prev = newNode;

        //Assigning head as newNode
        head = newNode;
    }

    }

    printf("\nNode inserted");
}

//Inserting data from last
void insertLast()
{
    struct Node *newNode, *currNode;
    int data;
    //Dynamically allocating space for newNode
    newNode = (struct Node *) malloc(sizeof(struct Node));

    //When there is no free space in list 
    if (newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter data value: ");
        scanf("%d", &data);

        //Assigning data to newNode
        newNode->data = data;

        //If list is empty
        if(head == NULL)
        {
           //Assigning next and previous nodes as NULL
           newNode->next = NULL;  
           newNode->prev = NULL;

           //Assigning head as newNode
           head = newNode;
        }
        else 
        {
            //pointing current node at head , to iterate till end of list
            currNode = head;

            while(currNode->next != NULL)
            {
                currNode = currNode->next;
            }
            //Inserting new Node at end
            currNode->next = newNode;

            //connecting it with previos node
            newNode->prev = currNode;
            
            //As it is last node it's next is null
            newNode->next = NULL;
        }
    }    
    printf("\nNode inserted");
}

//Inserting node before the specified location
void insertSpecified ()
{
    struct Node *newNode, *currNode;
    int data, loc, i;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    //When there is no free space in list
    if (newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        //pointing current node at head, which is later used to iterate till location
        currNode = head;
        printf("\nEnter the location: ");
        scanf("%d", &loc);

        //Iterating to location
        for(i = 0; i <loc; i++)
        {
            currNode = currNode->next;

            if (currNode == NULL)
            {
                printf("\nThere are less than %d elements", loc);
                return;
            }
        }
        printf("\nEnter value: ");
        scanf("%d", &data);

        //assigning data to newNode
        newNode->data = data;

        //conneting newNode to list 
        newNode->next = currNode->next;

        //current node will be previous node for newNode
        newNode->prev = currNode;

        //And vice-verca
        currNode->next = newNode;

        currNode->next->prev = newNode;

        printf("\nNode inserted");

    }
}

void deleteBeigin ()
{
    struct Node *newNode;
 
    //If list is empty
    if(head == NULL)
    {
        printf("\nUnderflow");
    }

    //If there is only one element in list
    else if (head->next == NULL)
    {
        head = NULL;

        //freeing up the space of head
        free(head);

        printf("\nNode deleted");
    }
    else
    {
        //Asssigning newNode as head
        newNode = head;

        //Next of head will be new node
        head = head->next;

        head->prev = NULL;

         //freeing up the space of newNode
        free(newNode);

        printf("\nNode deleted");
    }
}


void deleteLast ()
{
    struct Node *newNode;

    //If list is empty
    if(head == NULL)
    {
        printf("\nUnderflow");
    }

    //If list has only one element
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted");
    }

    else
    {
        //Pointing newNode to head
        newNode = head;

        //Finding the last node and pointing newNode to it
        while (newNode->next != NULL)
        {
            newNode = newNode->next;
        }
        
        //Making previous and next of newNode NULL 
        newNode->prev->next = NULL;
        
        //Freeing up space of newNode
        free(newNode);

        printf("\nNode deleted");

    }
}

void deleteSpecified ()
{
    struct Node *newNode, *currNode;
    int data;

    printf("\nEnter the data after which the node is to be deleted: ");
    scanf("%d", &data);

    //Pointing newNode to head
    newNode = head;

    //Iteraating till previous of newNode (Which is to be deleted)
    while(newNode->data != data)
    {
        newNode = newNode->next;
    }

    //If only one node
    if (newNode->next == NULL)
    {
        printf("\nCan't delete");
    }

    //If only two nodes
    else if (newNode->next->next == NULL)
    {
        newNode->next = NULL;
    }

    else
    {
        //pointing to node , which is to be deleted
        currNode = newNode->next;

        //connecting previous of node deleted to next node
        newNode->next = currNode->next;
        currNode->next->prev = newNode;

        //Freeing up space of newNode
        free(newNode);

        printf("\nNode deleted");
    }
}

void display()
{
    struct Node *newNode;
    printf("\nPrinting values...");

    newNode = head;

    //iterating over all the nodes
    while(newNode != NULL)
    {
        printf("\n%d", newNode->data);
        newNode = newNode->next;
    }
}

int main ()
{
    int ch;
    printf("\n1.Insert in front\n2.Insert in last\n3.Insert at any specified location\n4.Delete from front\n5.Delete from last\n6.Delete at random location\n7.Display\n8.Exit");
    do
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:insertBegin ();
            break;
            case 2:insertLast ();
            break;
            case 3:insertSpecified ();
            break;
            case 4:deleteBeigin ();
            break;
            case 5:deleteLast ();
            break;
            case 6:deleteSpecified ();
            break;
            case 7:display ();
            break;
            case 8:exit(0);
            break;
            default: printf("\nInvalid input");
        }
    } while (ch != 8);
    
    return 0;
}