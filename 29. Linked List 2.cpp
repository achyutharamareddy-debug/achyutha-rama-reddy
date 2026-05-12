//Linked List 2
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}; 
int main()
{
	struct node *head = NULL, *newnode = NULL, *newnode2 = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode2 = (struct node *)malloc(sizeof(struct node));
	newnode->link=NULL;
	newnode2->link=NULL;
	head = newnode;
	newnode->link = newnode2;
	printf("Enter node 1 data : ");
	scanf("%d",&newnode->data);
	printf("\nEnter node 2 data : ");
	scanf("%d",&newnode2->data);
	printf("\nNode1 data is : %d",head->data);
	printf("\nNode2 data is : %d",(newnode->link)->data);
	return 0;
}
