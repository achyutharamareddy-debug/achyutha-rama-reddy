#include<stdio.h>
#define MAX 5

int queue[MAX];
int rear = -1;
int front = -1;

void enqueue()
{
    int a;

    if((rear + 1) % MAX == front)
    {
        printf("\nQueue Overflow");
    }
    else
    {
        printf("\nEnter element: ");
        scanf("%d", &a);

        if(front == -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = a;
    }
}

void dequeue()
{
    if(front == -1)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        printf("\nDeleted element: %d", queue[front]);

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;   // ? FIXED
        }
    }
}

void peek()
{
    if(front == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nFront element is: %d", queue[front]);
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements are: ");

        i = front;
        while(i!=rear)
        {
            printf("%d ", queue[i]);

            if(i == rear)
                break;

            i = (i + 1) % MAX;   
        }
        printf("\n %d",queue[i]);
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
        }
    }
}
