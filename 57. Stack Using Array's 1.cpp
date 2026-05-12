//Stack using array's
#include<stdio.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push()
{
	int a;
	if(top==MAX-1)
	{
		printf("\nOverflow");
	}
	else
	{
		printf("\nEnter the element : ");
		scanf("%d",&a);
		top++;
		stack[top]=a;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		int temp;
		temp = stack[top];
		printf("\nThe popped element is : %d",top);
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		printf("\nUnderflow");
	}
	else
	{
		printf("\nThe top most element is : %d",stack[top]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("\nOverflow");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
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
