#include <stdio.h>
#include <stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=0,*tail=0;
void create(){
	int n,i;
	printf("enter no.of nodes: ");
	scanf("%d",&n);
	struct node *newnode;
	for(i=0;i<n;i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter data at node %d: ",i+1);
		scanf("%d",&newnode->data);
		newnode->prev=0;
		newnode->next=0;
		if (head==NULL){
			head=newnode;
			tail=newnode;
		}
		else {
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
	}
}
void display(){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d <-> ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
/*void del_pos()
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
		struct node *temp = head;
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
*/
int main(){
	create();
	display();
	
	//insert at first
	struct node *enode=NULL;
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter the the inserting data at first: ");
	scanf("%d",&enode->data);
	enode->prev=0;
	enode->next=head;
	head->prev=enode;
	head=enode;
	display();
	
	//insert at end
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter the the inserting data at end: ");
	scanf("%d",&enode->data);
	enode->prev=tail;
	tail->next=enode;
	tail=enode;
	display();
	
	// insert at position
	int pos;
	struct node *temp=head;
	printf("\nenter the position: ");
	scanf("%d",&pos);
	enode=(struct node *)malloc(sizeof(struct node));
	printf("enter the inserting data at position %d: ",pos);
	scanf("%d",&enode->data);
	for (int i=1;i<pos-1;i++){
		temp=temp->next;
	}
	if (pos==1){
	    enode->prev=0;
	    enode->next=head;
	    head->prev=enode;
	    head=enode;
	    
	}
	else 
	{
	    enode->next=temp->next;
	    temp->next=enode;
	    enode->prev=temp;
	    enode->next->prev=enode;
	display();
	}
	
	
	// deleting the first element
	
	head=head->next;
	free(head->prev);
	head->prev=NULL;
	printf("\nafter delecting the first element: ");
	display();
	
	//delecting the last element
	tail=tail->prev;
	free(tail->next);
	tail->next=NULL;
	printf("\nafter delecting the last elenent: ");
	display();
	
	//delecting the element at given position
	//del_pos();
	
	//reversing the 
	struct node *currentnode=0,*nextnode;
	currentnode=head;
	while(currentnode!=NULL){
		nextnode=currentnode->next;
		currentnode->next=currentnode->prev;
		currentnode->prev= nextnode;
		currentnode=nextnode;
	}
	currentnode=head;
	head=tail;
	tail=currentnode;
	display();
	
	return 0;
}
