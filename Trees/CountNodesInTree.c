#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *createNode(int key)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int count = 0;

int countNodes(struct Node *root)
{
    if(root != NULL)
    {
        countNodes(root->left);
        count++;
        countNodes(root->right);
    }
    return count;
}

int main()
{
    struct Node *newNode = createNode(25);
    newNode->left = createNode(27);
    newNode->right = createNode(19);
    newNode->left->left = createNode(17);
    newNode->left->right = createNode(91);
    newNode->right->left = createNode(13);
    newNode->right->right = createNode(55);

    printf("\nNumber of nodes in tree = %d", countNodes(newNode));
}