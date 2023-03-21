#include <stdio.h>
#include <stdlib.h>

//Representing a node of binary tree
struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int findHeight(struct Node *temp)
{
    //check whether tree is empty
    if(root == NULL)
    {
        printf("\nTree is empty");
        return 0;
    }
    else
    {
        int leftHeight = 0, rightHeight = 0;

        //Calculating the height of left subtree
        if(temp->left != NULL)
        {
            leftHeight = findHeight(temp->left);
        }

        //Calculating the height of right subtree
        if(temp->right != NULL)
        {
            rightHeight = findHeight(temp->right);
        }

        //Compare height of left subtree and right subtree and store maximum of two in variable max
        int max = (leftHeight > rightHeight)?leftHeight:rightHeight;

        //Calculating the total height of tree by adding height of tree
        return(max+1);
    } 
}

int main()
{
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->right->left = createNode(5);
    root->right->right = createNode(6);
    root->right->right->right = createNode(7);
    root->right->right->right->right = createNode(8);

    printf("\nMaximum height of given binary tree: %d", findHeight(root));

    return 0;
}