# include<stdio.h>
# include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
int main()
{
	struct node*head =NULL,*newnode=NULL;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\n enter node data:");
	scanf("%d",&newnode->data);
	newnode->link = NULL;
	head = newnode;
	printf("\n  new node=%d",newnode->data);
	return 0;
	}
