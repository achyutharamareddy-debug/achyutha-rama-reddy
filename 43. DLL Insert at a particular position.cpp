//Insert at a particular position
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
void ins_pos()
{
	int pos,i;
	printf("\nEnter the position at which you want to insert the node : ");
	scanf("%d",&pos);
	struct dnode *posnode=NULL;
	posnode = (struct dnode *)malloc(sizeof(struct dnode));
	posnode->pre = NULL;
	posnode->next = NULL;
	printf("\nEnter the New value to be inserted at the end : ");
	scanf("%d",&posnode->data);
	temp = head;
	for(i=1;i<pos-1;i++)
	{
		temp = temp->next;
	}
	posnode->pre = temp;
	posnode->next = temp->next;
	temp->next = posnode;
	(posnode->next)->pre = posnode;
	display();
}
int main()
{
	create();
	display();
	ins_pos();
	return 0;
}
