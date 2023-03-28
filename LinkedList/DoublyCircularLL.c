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
    struct Node *currNode;
    int new_data;

    //Dynamic allocation of newNode
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    //Overflow condition
    if (newNode == NULL)
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

            printf("\nNode inserted");
        }
        else
        {
            //Pointing currNode at head, to traverse till end of list
            currNode = head;

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
    printf("\nNode Inserted");
}

void deleteBegin()
{
    struct Node *temp;

    //Underflow condition
    if(head == NULL)
    {
        printf("\nUnderflow");
    }

    //If there is only one element
    else if(head->next == head)
    {
        //Empty the head
        head = NULL;

        //Dynamically free the space 
        free(head);

        printf("\nNode deleted");
    }
    else 
    {
        //assigning head value to temp
        temp = head;

        //Iterating till previous element of head, basitcally to last element as it is circular linked list
        while(temp->next != head)
        {
            temp = temp->next;
        }

        //Making next of head as next of temp
        temp->next = head->next;

        //Making next of head's previous as temp
        head->next->prev = temp;

        //Deallocating the head's space
        free(head);

        //next of head will be new head
        head = temp->next;

        printf("\nNode deleted");
    }
}

void deleteLast()
{
    struct Node *temp;

    //Underflow condition
    if(head == NULL)
    {
        printf("\nUnderflow");
    }
    //If there is only one element
    else if(head->next == head)
    {
        temp = temp->next;
    }
    else
    {
        //Assigning head value to temp
        temp = head;

        //Iterating till previous element of head, basitcally to last element as it is circular linked list
        while(temp->next != head)
        {
            temp = temp->next;
        }

        //pointing next of temp's previous to head
        temp->prev->next = head;

        //Making previous of temp as previous of head
        head->prev = temp->prev;

        //Dynamically deallocating space
        free(temp);
        printf("\nNode deleted");
    }
}

void display()
{
    struct Node *temp;

    //Assigning addressof head to temp
    temp = head;

    //If list is empty
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        //Iterate till last element
        while(temp->next != head)
        {
            printf("\n%d", temp->data);
            temp = temp->next;
        }
        printf("\n%d", temp->data);
    }
}


int main()
{
    int ch;
    printf("\n1.Insert from front\n2.Insert from end\n3.Delete from front\n4.Delete from end\n5.Display\n6.Exit");
    while(ch != 6)
    {
        printf("\n\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertBegin();
            break;
            case 2:insertLast();
            break;
            case 3:deleteBegin();
            break;
            case 4:deleteLast();
            break;
            case 5: display();
            break;
            case 6: exit(0);
            break;
            default: printf("\nInvalid input");
        }
    }
    return 0;
}