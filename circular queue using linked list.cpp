# include<stdio.h>
# include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *front=0, *rear=0, *temp=0;
void enqueue()
{
	struct queue *newnode=0;
	newnode=(struct queue *)malloc(sizeof(struct queue));
	printf("\nenter element: ");
	scanf("%d",&newnode->data);
	newnode->next=0;
	if(front==0)
	{
		front=rear=newnode;
		rear->next=front;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=front;
	}
}
void dequeue()
{
	if(front==0)
	{
		printf("\nunderflow");
	}
	else if(rear==front)
	{
		printf("\nthe dequeued element: %d",front->data);
		free(front);
		front=rear=0;
	}
	else
	{
		temp=front;
		printf("\nthe dequeued element: %d",front->data);
		front=front->next;
		rear->next=front;
		free(temp);
	}
}
void peek()
{
	if(front==0)
	{
		printf("\nunderflow");
	}
	else
	{
		printf("\nthe front element: %d",front->data);
	}
}
void display()
{
	if(front==0)
	{
		printf("\nunderflow");
	}
	else
	{
		temp=front;
		do
		{
			printf("\n%d",temp->data);
			temp=temp->next;
		}while(temp!=front);
	}
}
int main()
{
	int choice, ch=1;
	while(ch)
	{
		printf("\n1.enqueue()\n2.dequeue()\n3.peek()\n4.display()");
		printf("\nenter your choice: ");
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
							printf("\ninvalid option");
		}
		printf("\ndo you want another option");
		scanf("%d",&ch);
	}
	return 0;
}
