#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    if (top == MAX - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        int a;
        printf("\nEnter element: ");
        scanf("%d", &a);
        top++;
        stack[top] = a;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nPopped element: %d", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nTop element: %d", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\nStack elements:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    int choice,ch=1;

    while (ch)   
    {
        printf("\n\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("\nInvalid option");
                scanf("%d",&ch);
                
        }
    }
    return 0;
}
