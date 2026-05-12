#include<stdio.h>
#define MAX 5
int queue[MAX], rear = -1,front = -1;
void enqueue()
{
	int a;
	if(rear == MAX-1)
	{
		printf("\nQueue is Overflow.");
	}
	else
	{
		printf("\nEnter the Element : ");
		scanf("%d",&a);
		if(rear == -1 && front == -1)
		{
			rear = front = 0;
			queue[rear] = a;
		}
		else
		{
			rear++;
			queue[rear] = a;
		}
	}
}
void dequeue()
{
	int temp;
	if(front == -1)
	{
		printf("\nQueue is Underflow.");
	}
	else if(rear == front)
	{
		temp = queue[front];
		printf("\nThe deleted element is : %d",temp);
		rear = front = -1;
	}
	else
	{
		temp = queue[front];
		printf("\nThe deleted element is : %d",temp);
		front++;
	}
}
void peek()
{
	if(front == -1)
	{
		printf("\nQueue is Underflow.");
	}
	else
	{
		printf("\nThe front element is : %d",queue[front]);
	}
}
void display()
{
	int i;
	printf("\n");
	if(front == -1)
	{
		printf("\nQueue is Underflow.");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("\t%d",queue[i]);
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
