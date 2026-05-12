//insert at end
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
void insend()
{
	struct node *enode = NULL;
	enode = (struct node *)malloc(sizeof(struct node));
	enode->link = NULL;
	printf("\nEnter the last node value : ");
	scanf("%d",&enode->data);
	temp = head;
	while(temp->link!=NULL)
	{
		temp = temp->link;
	}
	temp->link=enode;
	printf("\nAfter insertion at the end : \n");
	display();
}
int main()
{
	create();
	insend();
	return 0;
}
