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
void del_fst_node()
{
	temp = head;
	head = head->link;
	free(temp);
}
void del_pos()
{
	int pos,i;
	struct node *prenode=NULL;
	prenode = (struct node *)malloc(sizeof(struct node));
	prenode->link = NULL;
	printf("\nEnter the Position of value that you want to delete : ");
	scanf("%d",&pos);
	temp=head;
	if(head==NULL)
	{
		printf("\nThe LIST is empty...");
	}
	else if(pos==1)
	{
		del_fst_node();
	}
	else
	{
		
		for(i=1;i<pos-1;i++)
		{
			temp = temp->link;
		}
		prenode = temp->link;
		temp->link=prenode->link;
		prenode->link=NULL;
		free(prenode);
		display();
	}
}
int main()
{
	create();
	del_pos();
	return 0;
}
