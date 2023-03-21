#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head;

//Insering node at beginning (Time complexity = O(1))
void insertStart ()
{
    int new_data;

    printf("\nEnter the node to be inserted: ");
    scanf("%d", &new_data);

    //Dynamically allocate node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    //Put in data
    newNode->data = new_data;

    //Make next of new node as head
    newNode->next = head;

    // Move the head to point to the new node
    head = newNode;

    printf("\nNode inserted"); 
}


//Inserting node after given node (Time Complexity = O(1))
void insertAfter ()
{
    int new_data, loc, i;
    struct Node *prev_node = head;

    //Dynamically allocate new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    //Check if the given Previous node is NULL
    if (newNode == NULL)
    {
        printf("\nOverflow");
    }
    else
    {
    printf("\nEnter the node to be inserted: ");
    scanf("%d", &new_data);

    //Put in the data
    newNode->data = new_data;

    printf("\nEnter the location of previous node: ");
    scanf("%d", &loc);

    for (i = 0; i < loc - 1; i++)
    {
        prev_node = prev_node->next;

        if (prev_node == NULL)
        {
            printf("\nCant insert");
            return;
        }
    }
    
    //make next of new node as next of prev_node
    newNode->next = prev_node->next;

    // Move the next of prev_node as new_node
    prev_node->next = newNode;

    printf("\nNode inserted");

    }
}


//Insertig node at end
void insertEnd ()
{
    int new_data;

    printf("\nEnter the node to be inserted: ");
    scanf("%d", &new_data);

    //Dynamically allocate node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = head;
    
    //Put in the data
    newNode->data = new_data;

    //This new node is going to be the last node, so make next of it as NULL
    newNode->next = NULL;

    //If the linked list is empty, then make the new node as head
    if (head == NULL) 
    {
        head = newNode;
        return;
    }

    //else traverse till last node
    while (last->next != NULL)
    {
        last = last->next;
    }

    //Change the next of last node
    last->next = newNode;
    printf("\nNode inserted");
    return;
    
}

//Deleting node from beginning
void deleteFirst ()
{
    struct Node *node;

    //if list is empty
    if(head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        node = head;

        //changing postion of head to next node
        head = node->next;

        //Dynamically freeing up the node
        free(node);

        printf("\nNode deleted");

    }
}

//deleting node from end
void deleteEnd()
{
    struct Node *node, *temp;

    //if list is empty
    if(head == NULL)
    {
        printf("\nList is empty");
    }

    //if there is only one node
    else if (head ->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted");
    }

    //if there are more than one node
    else
    {
        //node be positioned at head of list
        node = head;

        //Iterating to last node
        while (node->next != NULL)
        {
            temp = node;
            node = node->next;
        }

        temp->next = NULL;

        free(node);

        printf("\nNode deleted");
    }
}

//Delete first occurrance of key in linked list 
void deleteNode ()
{
    int key;
    printf("\nEnter the key to be deleted: ");
    scanf("%d", &key);
    //store head node
    struct Node* temp = head, *prev;

    //If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        head = temp->next;   //chaned head
        printf("\nNode Deleted.");
        free(temp);           //free old head
        return;
    }

    //search for the key to be deleted, keep track of the 
    //previos node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    //If key was not present in linked list
    if (temp == NULL) 
    {
        printf("\nKey not present");
        return;
    }    

    //unlike the node from linked list
    prev->next = temp->next;

    printf("\nNode Deleted.");
    free(temp);   //free memory
}


void display()
{
    struct Node *curr;
    curr = head;

    if(curr == NULL)
    {
        printf("\nNothing to print");
    }

    else
    {
    printf("\nLinked List: ");
    //as linked list will end when Node is NULL
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    }
}


int main()
{
    int ch;
    printf("\n1.Insert node from start.\n2.Insert node at end.\n3.Insert after given node\n4.Delete from beginning\n5.Delete from end\n6.Delete given node.\n7.Display\n8.Exit");
    do{
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: insertStart();
            break;
            case 2: insertEnd();
            break;
            case 3: insertAfter();
            break;
            case 4: deleteFirst();
            break;
            case 5: deleteEnd();
            break;
            case 6: deleteNode();
            break;
            case 7: display();
            break;
            case 8: exit(0);
            break;
            default:printf("\nInvalid input");
        }
    } while (ch != 8);

    return 0;
}