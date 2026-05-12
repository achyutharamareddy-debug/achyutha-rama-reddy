//delete at the end
#include<stdio.h>
#include<stdlib.h>
void display();
struct node
{
	int data;
	struct node *link;
};
struct node *head = NULL, *temp = NULL;
void create()
{
	struct node *newnode=NULL;
	int n,i;
	printf("\nEnter number of Values : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		newnode->link = NULL;
		printf("\nEnter the value %d : ",i+1);
		scanf("%d",&newnode->data);
		if(head==NULL)
		{
			head = newnode;
			temp = newnode;
		}
		else
		{
			temp->link = newnode;
			temp = newnode;
		}
	}
	display();
}
void display()
{
	temp = head;
	while(temp!=0)
	{
		printf("\t%d",temp->data);
		temp = temp->link;
	}
}
void del_last_node()
{
	struct node *prenode=NULL;
//	prenode = (struct node *)malloc(sizeof(struct node));
//	prenode->link = NULL;
//	temp = head;
//	while(temp->link!=0)
//	{
//		prenode=temp;
//		temp = temp->link;
//	}
//	free(temp);
//	prenode->link = NULL;
	temp = head;
	while((temp->link)->link != 0)
	{
		temp = temp->link;
	}
	free(temp->link);
	temp->link = NULL;
}
int main()
{
	create();
	del_last_node();
	printf("\nAfter deleting the last node : \n");
	display();
	return 0;
}
