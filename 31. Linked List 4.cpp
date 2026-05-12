#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
int main()
{
	struct node *head = NULL, *newnode = NULL, *temp = NULL;
	int i,n;
	printf("Enter Number of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\nEnter node %d data : ",i+1);
		scanf("%d",&newnode->data);
		newnode->link=NULL;
		if(head==NULL)
		{
			head = newnode;
			temp = newnode;
		}
		else
		{
			temp->link=newnode;
			temp = newnode;
		}
	}
	printf("\nThe given nodes are : \n");
	temp = head;
	while(temp!=NULL)
	{
		printf("\t%d",temp->data);
		temp = temp->link;
	}
	return 0;
}
