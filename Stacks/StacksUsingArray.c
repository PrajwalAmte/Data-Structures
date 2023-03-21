#include<stdio.h>
#include<stdlib.h>
int stack[100], top =-1, n;

void push()
{
    int val;
    //Overflow condition
    if(top == n)
    {
        printf("\nOverflow");
    }
    else
    {
        printf("\nEnter the value: ");
        scanf("%d",&val);
        top = top+1;
        stack[top] = val;
        printf("\nPushed %d",stack[top]);
    }
}

void pop()
{
    //Underflow condition
    if (top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nPopped %d",stack[top]);
        top = top - 1;
    }
}

void display()
{
    int i;
    for(i = top; i >= 0; i--)
    {
        printf("\n%d", stack[i]);
    }
    if(top == -1)
    {
        printf("\nStack is empty");
    }
}

int main()
{
    int ch;
    printf("\nEnter the number of elements in: ");
    scanf("%d",&n);
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