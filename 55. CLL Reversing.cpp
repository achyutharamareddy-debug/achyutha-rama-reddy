//Circular Linked List Reversing
#include<stdio.h>
#include<stdlib.h>
struct cirnode
{
	int data;
	struct cirnode *next;
};
struct cirnode *head = NULL, *temp = NULL, *tail = NULL;
void cir_create()
{
	struct cirnode *newnode = NULL;
	int i,n;
	printf("\nEnter number of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		newnode = (struct cirnode *)malloc(sizeof(struct cirnode));
		printf("\nEnter node %d data : ",i+1);
		scanf("%d",&newnode->data);
		newnode->next = NULL;
		if(head==NULL)
		{
			head = tail = newnode;
			tail->next = head;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
			tail->next = head;
		}
	}
}
void display()
{
	temp = head;
	if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: \n");
    do {
        printf("%d \t", temp->data);
        temp = temp->next;
    } while(temp != head); 
    printf("\n");
}
void reverse()
{
	struct cirnode *prenode = tail, *current = head, *nextnode = 0;
	do
	{
		nextnode = current->next;
		current->next = prenode;
		prenode = current;
		current = nextnode;
	}while(current!=head);
	tail = head;
	head = prenode;
	printf("\nAfter reversing : \n");
	display();
	printf("\n%d",tail->next->data);
}
int main()
{
	cir_create();
	display();
	reverse();
	return 0;
}
