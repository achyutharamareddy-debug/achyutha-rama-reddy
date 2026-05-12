//Doubly Linked List's
#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	struct dnode *pre;
	int data;
	struct dnode *next;
};
struct dnode *head = NULL, *temp = NULL, *tail = NULL;
void create()
{
	int i,n;
	struct dnode *newnode = NULL;
	printf("\nEnter number of nodes/values : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode = (struct dnode *)malloc(sizeof(struct dnode));
		printf("\nEnter the value in node %d : ",i+1);
		scanf("%d",&newnode->data);
		newnode->pre=NULL;
		newnode->next=NULL;
		if(head==NULL)
		{
			head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->pre=tail;
			tail=newnode;
		}
	}
}
void display()
{
	temp=head;
	printf("\n the data is : \n");
	while(temp!=0)
	{
		printf("\t%d",temp->data);
		temp=temp->next;
	}
}
int main()
{
	create();
	display();
}
