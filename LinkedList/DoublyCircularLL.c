#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head;

void insertBegin()
{
    struct Node *currNode;
    int new_data;

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //If there is no space
    if(newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        //If there is no space
        printf("\nEnter the data value: ");
        scanf("%d",&new_data);

        //Assining data to newNode
        newNode->data = new_data;

        //When there are no nodes in list
        if(head == NULL)
        {
            //Making newNode as head
            head = newNode;

            //pointing next and previous of newNode to itself
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            //Making currNode as head to iterate till end
            currNode = head;

            //iterating till end of list
            while(currNode->next != head)
            {
                currNode = currNode->next;
            }

            //Make newNode as next of currNode, which is at end of list
            currNode->next = newNode;

            //currNode will be previous of newNode, as its circular
            newNode->prev = currNode;

            //As its circular,it is inserted previos to head and next to last node
            head->prev = newNode;

            //And head is next to newNode
            newNode->next = head;

            //newNode will be head now
            head = newNode;
        }
        printf("\nNode inserted");
    }
}

void insertLast()
{
    struct Node currNode;
    int new_data;

    //Dynamic allocation of newNode
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //Overflow condition
    if (newNode = NULL)
    {
        printf("\nOverflow");
    }
    else
    {
        //Taking data input
        printf("\nEnter the value of data: ");
        scanf("%d", &new_data);

        //Assigning new_data to newNode
        newNode->data = new_data;

        //if list is empty
        if(head == NULL)
        {
            //Making newNode as head
            head = newNode;

            //As it is circular linkedlist , next of newNode will be head itself
            newNode->next = head;

            //and previous of newNode will also be head itself
            newNode->prev = head;
        }
        else
        {
            //Pointing currNode at head, to traverse till end of list
            currNode = newNode;

            //traverse till end
            while(currNode->next != head)
            {
                currNode = currNode->next;
            }

            //Make newNode as next of currNode, which is at end of list
            currNode->next = newNode;

            //currNode will be previous of newNode, as its last
            newNode->prev = currNode;

            //As its circular,it is inserted previos to head and next to last node
            head->prev = newNode;

            //And head is next to newNode
            newNode->next = head;
        }
    }
}
