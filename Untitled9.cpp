#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;
    int a;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("\nEnter element: ");
    scanf("%d", &a);

    newnode->data = a;

    if(front == NULL)
    {
        front = rear = newnode;
        rear->next = front;  
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;  
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("\nQueue Underflow");
    }
    else
    {
        temp = front;
        printf("\nDeleted element: %d", front->data);

        if(front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }

        free(temp);
    }
}

void peek()
{
    if(front == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nFront element is: %d", front->data);
    }
}

void display()
{
    struct node *temp;

    if(front == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements are: ");

        temp = front;

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != front);
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
