//complete single linked list operations
# include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=0,*temp=0;
void create()
{
    struct node *newnode=0;
    int i,n;
    printf("\nenter n size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nenter node %d data: ",i+1);
    scanf("%d",&newnode->data);
    newnode->link=0;
    if(head==0)
    {
        temp=head=newnode;
    }
    else
    {
        temp->link=newnode;
        temp=newnode;
    }
    }
}
void display()
{
    temp=head;
    while(temp!=0)
    {
        printf("  %d",temp->data);
        temp=temp->link;
    }
}
void count()
{
	int count=0;
	temp=head;
	while(temp!=0)
	{
		count++;
		temp=temp->link;
	}
	printf("\nNODES COUNT IS: %d",count);
}
void insertfront()
{
	struct node *newnode2=0;
	newnode2 =(struct node*)malloc(sizeof(struct node));
	printf("\nenter newly created node data: ");
	scanf("%d",&newnode2->data);
	newnode2->link = head;
	head=newnode2;
	printf("\nAFTER INSERTING NODE AT FRONT: ");
	display();
}
void insertend()
{
	struct node *newnode2=0;
	newnode2=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newnode data: ");
	scanf("%d",&newnode2->data);
	temp=head;
	while(temp->link!=0)
	{
		temp=temp->link;
	}
	temp->link=newnode2;
	newnode2->link=NULL;
	printf("\nAFTER INSERTING NODE AT END: ");
	display();
}
void insertpos()
{
	struct node *enode=0;
	int i,pos;
	printf("\nenter position: ");
	scanf("%d",&pos);
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newly created node data: ");
	scanf("%d",&enode->data);
	enode->link=NULL;
	if(pos==1)
	{
		enode->link=head;
		head=enode;	
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}
		enode->link=temp->link;
		temp->link=enode;
	}
	printf("\nAFTER INSERTING THE NODE AT PARTICUAR POSITION: ");
	display();
}
void deletefront()
{
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else
	{
		temp=head;
		head=temp->link;
		free(temp);
	}
	printf("\nAFTER DELETING THE FIRST NODE: ");
	display();
}
void deleteend()
{
	struct node *prevnode=0;
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else if(head->link==0)
	{
		free(head);
		head=0;
	}
	else
	{
		temp=head;
		while(temp->link!=0)
		{
			prevnode=temp;
			temp=temp->link;
		}
		free(temp);
		prevnode->link=NULL;
	}
	printf("\nAFTER DELETING THE LAST NODE: ");
	display();
}
void deletepos()
{
	struct node *prevnode=0;
	int pos,i;
	printf("\nenter position: ");
	scanf("%d",&pos);
	if(head==NULL)
	{
		printf("\nLIST IS EMPTY");
	}
	else if(pos==1)
	{
		temp=head;
		head=temp->link;
		free(temp);
	}
	else
	{
		temp=head;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}
		prevnode=temp->link;
		temp->link=prevnode->link;
		free(prevnode);
	}
	printf("\nAFTER DELETING THE NODE AT PARTICULAR POSITION");
	display();
}
void reverse()
{
	struct node *prevnode=0, *currentnode=head, *nextnode=head;
	while(nextnode!=NULL)
	{
		nextnode=nextnode->link;
		currentnode->link=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	head=prevnode;
	printf("\nAFTER REVERSING THE LIST: ");
	display();
}
int main()
{
	create();
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
			insertfront();
			break;
		case 2:
			insertend();
			break;
		case 3:
			insertpos();
			break;
		case 4:
			deletefront();
			break;
		case 5:
			deleteend();
			break;
		case 6:
			deletepos();
			break;
		case 7:
			count();
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
