#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *front = NULL, *rear = NULL, *temp = NULL;
void enqueue()
{
	struct queue *newnode = NULL;
	newnode = (struct queue *)malloc(sizeof(struct queue));
	printf("\nEnter the data of the element : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	if(front == NULL)
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
	if(front==NULL)
	{
		printf("\nUnderflow....");
	}
	else
	{
		temp = front;
		front = front->next;
		printf("\nThe deleted element is : %d",temp->data);
		free(temp);
		if(front==NULL)
		{
			rear = NULL;
		}
	}
}
void peek()
{
	if(front==NULL)
	{
		printf("\nUnderflow...");
	}
	else
	{
		printf("\nThe Front value is : %d",front->data);
		front = front->next;
	}
}
void display()
{
	if(front==NULL)
	{
		printf("\nUnderflow...");
	}
	else
	{
		temp = front;
		while(temp!=NULL)
		{
			printf("\t%d",temp->data);
			temp = temp->next;
		}
	}
}
int main()
{
	int choice, ch=1;
	while(ch)
	{
		printf("\n1. enqueue\n2. dequeue\n3. peek\n4. display");
		printf("\nEnter your choice :");
		scanf("%d",&choice);
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
			default:
				printf("\nInvalid Option.....");
		}
		printf("\nDo you want another option [yes:1||no:0] : ");
		scanf("%d",&ch);
	}
	return 0;
}
