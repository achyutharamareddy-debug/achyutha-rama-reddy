# include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data,top;
	struct stack *next;
};
void push()
{
	struct stack *newnode =0;
	newnode =(struct stack *)malloc(sizeof(struct stack));
	printf("\n enter data:");
	scanf("%d",&newnode->data);
	newnode->next = top;
	top=newnode;
}
void pop()
{
	if(top==0)
	{
		printf("\n is empty");
	}
	else
	{
		temp=top;
		top= top->next;
		printf("\n the poped element is %d",temp->data);
		free(temp);
	}
}
void peek()
{
	if(top==0)
	{
		printf("\n is empty");
	}
	else
	{
		printf("\n top value:",top->data);
	}
}
void display()
{
    if (top == 0)
    {
        printf("\nStack is Empty");
    }
    else
    { temp=top;
     while(temp!=0)
     {
     	printf("\n%d",temp->data);
     	temp=temp->next;
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

