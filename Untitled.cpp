#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;


void enqueue()
{
    struct queue *newnode;
    int X;

    newnode = (struct queue*)malloc(sizeof(struct queue));

    if(newnode == NULL)
    {
        printf("\nOVER FLOW");
        
    }

    printf("\nEnter element: ");
    scanf("%d", &X);

    newnode->data = X;
    newnode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}


void dequeue()
{
    struct queue *temp;

    if(front == NULL)
    {
        printf("\n Underflow");
    }
    else
    {
        temp = front;
        printf("\nDeleted element: %d", front->data);

        front = front->next;

        if(front == NULL) 
        {
            rear = NULL;
        }

        free(temp);
    }
}
void peek()
{
    if(front == NULL)
    {
        printf("\nis empty");
    }
    else
    {
        printf("\nFront element is: %d", front->data);
    }
}


void display()
{
    struct queue *temp;

    if(front == NULL)
    {
        printf("\n is empty");
    }
    else
    {
        temp = front;
        printf("\nQueue elements are: ");

        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
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
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}
