//Delete at a particular position
#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	struct dnode *pre;
	int data;
	struct dnode *next;
};
struct dnode *head = NULL, *temp = NULL, *tail = NULL;
int n;
void create()
{
	int i;
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
void del_pos()
{
	int pos,i;
	printf("\nEnter a position to delete the node/value : ");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("\nList is EMPTY...");
	}
	else if(head->next==NULL)
	{
		free(head);
		head = tail = NULL;
	}
	else if(pos==1)
	{
		temp = head;
		head = (head->next);
	//	head->pre = NULL;
	//	free(temp);
		free(head->pre);
		head->pre = NULL;
		printf("\nAfter deleting the first node : ");
		display();
	}
	else if(pos==n)
	{
		tail = tail->pre;
		free(tail->next);
		tail->next = NULL;
	//	temp = tail;
	//	tail = tail->pre;
	//	tail->next = NULL;
	//	free(temp);
		printf("\nAfter deleting the last node : ");
		display();
	}
	else
	{
		temp = head;
//		for(i=1;i<pos-1;i++)
//		{
//			temp = temp->next;
//		}
//		temp->next = ((temp->next)->next);
//		free(((temp->next)->pre));
//		((temp->next)->pre) = temp;
		for(i=1;i<pos;i++)
		{
			temp = temp->next;
		}
		(temp->pre)->next = temp->next;
		(temp->next)->pre = temp->pre;
		free(temp);
		printf("\nAfter deleting the node at %d position : ",pos);
		display();
	}
}
int main()
{
	create();
	display();
	del_pos();
	return 0;
}
