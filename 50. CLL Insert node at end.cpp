// Circular Lined List Insert node at end
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
void ins_end()
{
	struct cirnode *enode = NULL;
	enode = (struct cirnode * )malloc(sizeof(struct cirnode));
	printf("\nEnter the New last node data : ");
	scanf("%d",&enode->data);
	enode->next = NULL;
	if(head == NULL)
	{
		head = tail = enode;
        tail->next = head;
	}
	else
	{
		tail->next = enode;
		tail = enode;
		tail->next = head;
	}
	printf("After inserting at the end : \n");
	display();
	if (tail != NULL && tail->next != NULL) 
	{
		printf("Verification (Tail points to): %d\n", tail->next->data);
	}
}
int main()
{
	cir_create();
	display();
	ins_end();
	return 0;
}
