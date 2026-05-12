//Circular Linked List Insetr at Position
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
void ins_pos()
{
	int pos,i;
	struct cirnode *pnode = NULL;
	pnode = (struct cirnode *)malloc(sizeof(struct cirnode));
	printf("\nEnter the position of the new node : ");
	scanf("%d",&pos);
	pnode = (struct cirnode *)malloc(sizeof(struct cirnode));
    printf("Enter data: ");
    scanf("%d", &pnode->data);

    if (pos == 1) {
        pnode->next = head;
        head = pnode;
        tail->next = head;
    } else
	{
        for (i = 1; i < pos - 1; i++) 
		{
            temp = temp->next;
        }
        pnode->next = temp->next;
        temp->next = pnode;
        if (temp == tail) 
		{
            tail = pnode;
        }
    }
    printf("\nAfter inserting at %d position : \n",pos);
    display();
}
int main()
{
	cir_create();
	display();
	ins_pos();
	return 0;
}
