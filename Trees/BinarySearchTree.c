#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *left, *right;
};

//Creating a node
struct Node *createNode(int new_data)
{
    //Dynamically assigning space for newNode
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //Assigning newNode new_node
    newNode->data = new_data;

    //Keeping left and right node as null
    newNode->left = newNode->right =NULL;

    return newNode;
}

//Insert a node
struct Node *insert(struct Node *node, int data)
{
    //Return createNode if the tree is empty
    if(node == NULL)
    {
        return createNode(data);
    }
    //Traverse to appropriate place and insert the node
    if(data < node->data)
    {
        node->left = insert(node->left, data);
    }
    else 
    {
        node->right = insert(node->right,data);
    }
    return node;
}

//Find inorder successor
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;

    //Find the leftmosr leaf
    while(current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

//Deleting a node
struct Node *deleteNode(struct Node *root, int key)
{
    //return if the tree is empty
    if(root == NULL) return root;

    //Find the node to be deleted
    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        //If the node is with one child or no child
        if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        //If the node has two children
        struct Node *temp = minValueNode(root->right);

        //Place the inorder successor in position of the node to be deleted
        root->data = temp->data;

        //Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

//Inorder traversal
void inorder(struct Node *root)
{
    if(root != NULL)
    {
        //Traversal left
        inorder(root->left);

        //Traverse root
        printf("%d ->", root->data);

        //Traverse right
        inorder(root->right);
    }
}

struct Node *search(struct Node *root, int key)
{
    if(root == NULL || root->data == key)
    {
        return root;
    }
    else if(key > root->data)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}

int main()
{
    struct Node *root = NULL;
    
    // root = insert(root, 8);
    // root = insert(root, 3);
    // root = insert(root, 1);
    // root = insert(root, 6);
    // root = insert(root, 7);
    // root = insert(root, 10);
    // root = insert(root, 14);
    // root = insert(root, 4);

    // printf("\nInorder traversal: ");
    // inorder(root);

    // printf("\nAfter deleting: ");
    // root = deleteNode(root, 10);

    // printf("\nInorder traversal: ");
    // inorder(root);

    int ch ,data;
    printf("\n1.Insert\n2.Delete\n3.Print Inorder\n4.Exit");
    while(1)
    {
        printf("\n\nEnter the choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: printf("\nEnter the data: ");
            scanf("%d",&data);
            root = insert(root,data);
            break;

            case 2:printf("\nEnter data to be deleted: ");
            scanf("%d",&data);
            root = deleteNode(root,data);
            break;

            case 3: inorder(root);
            break;

            case 4: exit(0);
            break;

            default:printf("\nInvalid input");
        }
    }
    return 0;
}