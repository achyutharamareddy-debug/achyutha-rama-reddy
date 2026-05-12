//Linked List 1
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
}; 
int main()
{
	struct node *head = NULL;
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
/*
	or
	struct node *head = NULL, *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
*/
	printf("Enter the new node : ");
	scanf("%d",&newnode->data);
	head = newnode;
	printf("New node data is : %d",newnode->data);
	return 0;
}
