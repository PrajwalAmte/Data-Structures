#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

//Inorder traversal
void inorder(struct Node* root)
{
    if(root == NULL) return;

    //Traversal left
    inorder(root->left);

    //Traverse root
    printf("%d  ", root->data);

    //Traverse right
    inorder(root->right);
}

//Preorder traversal
void preorder(struct Node* root)
{
    if(root == NULL) return;

    //Traverse root
    printf("%d  ", root->data);

    //Traverse left
    preorder(root->left);

    //Traverse right
    preorder(root->right);
}

//postorder traversal
void postorder(struct Node* root)
{
    if(root == NULL) return;

    //Traverse left
    postorder(root->left);

    //Traverse right
    postorder(root->right);

    //Traverse root
    printf("%d  ", root->data);
}

//creating a node
struct Node* create(int value)
{
    //Dynamic allocation of space for newNode
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    //Assigning newNode its value
    newNode->data = value;

    //Assigning right and left of node as null
    newNode->left = NULL;

    newNode->right = NULL;

    return newNode;
}

//Insert on left of the node
struct Node* insertLeft(struct Node* root, int value)
{
    root->left = create(value);
    return root->left;
}

//Insert on right of the node
struct Node* insertRight(struct Node* root, int value)
{
    root->right = create(value);
    return root->right;
} 


int main()
{
    struct Node *root = create(1);
    insertLeft(root, 12);
    insertRight(root, 9);

    insertLeft(root->left, 5);
    insertRight(root->left, 6);

    printf("Inorder traversal \n");
    inorder(root);

    printf("\nPreorder traversal \n");
    preorder(root);

    printf("\nPostorder traversal \n");
    postorder(root);

    return 0;
}