//COMPLETE DOUBLY LINKED LIST OPERATIONS PROGRAM
# include<stdio.h>
# include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=0,*temp=0,*tail=0;
void create()
{
    struct node *newnode=0;
    int i,n;
    printf("\nenter n size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	newnode=(struct node *)malloc(sizeof(struct node));
    	printf("\nenter node %d data: ",i+1);
    	scanf("%d",&newnode->data);
    	newnode->prev=NULL;
    	newnode->next=NULL;
    	if(head==NULL)
    	{
    		head=tail=newnode;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
		}
	}
}
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("  %d",temp->data);
        temp=temp->next;
    }
}
void insert_front()
{
	struct node *enode=0;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data for newely created node: ");
    scanf("%d",&enode->data);
    enode->prev=NULL;
    enode->next=NULL;
    head->prev=enode;
    enode->next=head;
    head=enode;
    printf("\nAFTER INSERTING NODE AT FRONT: ");
    display();
}
void insert_end()
{
	struct node *enode=NULL;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter data for newely created node: ");
    scanf("%d",&enode->data);
    enode->next=0;
    enode->prev=0;
    tail->next=enode;
    enode->prev=tail;
    tail=enode;
    printf("\nAFTER INSERTING NODE AT END POSITION: ");
    display();
}
void insert_pos()
{
	struct node *enode=NULL;
	int pos,i;
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newely creates node data: ");
	scanf("%d",&enode->data);
	enode->prev=0;enode->next=0;
	printf("\nenter position: ");
	scanf("%d",&pos);
	if(pos==1)
	{
		enode->next=head;
		head->prev=enode;
		head=enode;
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		enode->next=temp->next;
		enode->prev=temp;
		temp->next=enode;
		enode->next->prev=enode;
	}
	printf("\nAFTER INSERTING A NODE AT POSITION: ");
	display();
}
void delete_front()
{
	if(head==NULL)
	{
		printf("\nLIST IS empty");
	}
	else
	{
	head=head->next;
	free(head->prev);
	head->prev=NULL;
	}
	printf("\n AFTER DELETING, THE LIST IS: ");
	display();
}
void delete_end()
{
	if(head==NULL)
	{
		printf("\nLIST IS empty");
	}
	else if(head->next==NULL)
	{
		free(head);
		head=tail=NULL;
	}
	else
	{
		tail=tail->prev;
		free(tail->next);
		tail->next=0;
	}
	printf("\nAFTER DELETING");
	display();
}
void delete_pos()
{
	int i,pos;
	printf("\nenter position: ");
	scanf("%d",&pos);
	if(head==0)
	{
		printf("\nLIST ID EMPTY");
	}
	else if(pos==1)
	{
		head=head->next;
		free(head->prev);
		head->prev=NULL;
	}
	else
	{
		temp=head;
		for(i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
	printf("\nAFTER DELETING");
	display();
}
void counting()
{
	
	int count=0;
	temp=head;
	while(temp!=0)
	{
		count++;
		temp=temp->next;
	}
	printf("\nNODES COUNT IS: %d",count);

}
void reverse()
{
	struct node *currentnode=0, *nextnode=0;
	currentnode=head;
	while(currentnode!=NULL)
	{
		nextnode=currentnode->next;
		currentnode->next=currentnode->prev;
		currentnode->prev=nextnode;
		currentnode=nextnode;
	}
	currentnode=head;
	head=tail;
	tail=currentnode;
	printf("\nAFTER REVERSING ");
	display();
}
int main()
{
    create();
	printf("\nBEFORE OPERATING ANY OPERATION:");
	display();
    int choice,ch;
	printf("\n1. INSERTING NODE AT FRONT");
	printf("\n2. INSERTING NODE AT END");
	printf("\n3. INSERTING NODE AT PARTICULAR POSITION");
	printf("\n4. DELETING NODE AT FRONT");
	printf("\n5. DELETING NODE AT END");
	printf("\n6. DELETING NODE AT PARTICULAR POSITION");
	printf("\n7. COUNTING");
	printf("\n8. REVERSING THE LIST");
	while(ch)
	{
	printf("\nenter your choice: ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			insert_front();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			insert_pos();
			break;
		case 4:
			delete_front();
			break;
		case 5:
			delete_end();
			break;
		case 6:
			delete_pos();
			break;
		case 7:
			counting();
			break;	
		case 8:
			reverse();
			break;
		default:
			printf("\nINVALID OPTION");
	}
	printf("\nDO YOU WANT ANOTHER OPTION (YES:1||NO:0): ");
	scanf("%d",&ch);
}
    return 0;
}
