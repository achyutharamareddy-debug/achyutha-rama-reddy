//Stack Using Linked List's
#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *head = NULL, *temp = NULL, *top = NULL;
void push()
{
	struct stack *newnode = NULL;
	newnode = (struct stack *)malloc(sizeof(struct stack));
	printf("\nEnter the data : ");
	scanf("%d",&newnode->data);
	newnode->next = top;
	top = newnode;
}
void pop()
{
	if(top==NULL)
	{
		printf("\nUnder flow");
	}
	else
	{
		temp=top;
		top = top->next;
		printf("\nThe popped element : %d",temp->data);
		free(temp);
	}
}
void peek()
{
	if(top==NULL)
	{
		printf("\nThe satck is empty....");
	}
	else
	{
		printf("\nThe top most element is : %d",top->data);
	}
}
void display()
{
	if(top==NULL)
	{
		printf("\nThe satck is empty....");
	}
	else
	{
		temp = top;
		while(temp!=NULL)
		{
			printf("\n\t%d",temp->data);
			temp = temp->next;
		}
	}
}
int main()
{
	int choice,ch=1;
	while(ch)
	{
		printf("\n1. Push\n2. Pop\n3. Peek\n4. Display");
		printf("\nEnter your Choice : ");
		scanf("%d",&choice);
	switch(choice)
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
		default:
			printf("\nInvalid Option ");
	}
	printf("\nDo you want another option [yes:1 || no:0] : ");
	scanf("%d",&ch);
	}
}
