# include<stdio.h>
# include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=0, *temp=0, *tail=0;
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
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
            tail->next=head;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
            tail->next=head;
        }
    }
}
void display()
{
    temp=head;
    do
    {
        printf("  %d",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
void insert_front()
{
	struct node *enode=0;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter newely created node data: ");
    scanf("%d",&enode->data);
    enode->next=0;
    enode->next=head;
    head=enode;
    tail->next=head;
    display();
    printf("\n%d",tail->next->data);
}
void insert_end()
{
	struct node *enode=NULL;
    enode=(struct node *)malloc(sizeof(struct node));
    printf("\nenter newely created node data: ");
    scanf("%d",&enode->data);
    enode->next=NULL;
    if(head==NULL)
    {
        head=tail=enode;
        tail->next=head;
    }
    else
    {
        tail->next=enode;
        tail=enode;
        tail->next=head;
    }
    display();
    printf("\n%d",tail->next->data);
}
void insert_pos()
{
	int i,pos;
	printf("\nenter position: ");
	scanf("%d",&pos);
	struct node *enode=0;
	enode=(struct node *)malloc(sizeof(struct node));
	printf("\nenter newely created data: ");
	scanf("%d",&enode->data);
	enode->next=0;
	if(head==0)
	{
		head=tail=enode;
		tail->next=head;
	}
	else if(pos==1)
	{
		enode->next=head;
		head=enode;
		tail->next=head;
	}
	else
	{
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	enode->next=temp->next;
	temp->next=enode;
	}
	display();
	printf("\n%d",tail->next->data);
}
void delete_front()
{
	struct node *temp;
    if(head == 0)
    {
        printf("List is empty\n");
        return;
    }
    if(head == tail)
    {
        free(head);
        head = tail = 0;
    }
    else
    {
        temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
    printf("\nAFTER DELETING: ");
    display();
	printf("\n%d",tail->next->data);
}
void delete_end()
{
	if(head == 0)
    {
        printf("List is empty\n");
        return;
    }
    if(head == tail)
    {
        free(head);
        head = tail = 0;
    }
    else
    {
        temp = head;
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;  
        free(tail);
        tail = temp;
    }
	printf("\nAFTER DELETING: ");
	display();
	printf("\n%d",tail->next->data);
}
void delete_pos()
{
	int i, pos;
    struct node *delnode=NULL;
    printf("\nenter position: ");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
    }
    else if(pos==1)
    {
        if(head==tail)
        {
            free(head);
            head=tail=NULL;
        }
        else
        {
            temp=head;
            head=head->next;
            free(temp);
            tail->next=head;
        }
    }
    else
    {
        temp=head;
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        delnode=temp->next;
        if(temp->next==tail)
        {
            temp->next=head;
            free(tail);
            tail=temp;
        }
        else
        {
            temp->next=delnode->next;
            free(delnode);
        }
    }
    printf("\nAFTER DELETING NODE AT PARTICULAR POSITION: ");
    display();
    printf("\n%d",tail->next->data);
}
void reverse()
{
	struct node *prevnode=tail, *currentnode=head, *nextnode=NULL;
    if(head==NULL)
    {
        printf("\nLIST IS EMPTY");
    }
    else if(head==tail)
    {
        printf("\n ONLY ONE NODE IS THERE IN THE LIST SO, NO NEED TO PERFORM THE REVERSE");
    }
    else
    {
        do
        {
            nextnode=currentnode->next;
            currentnode->next=prevnode;
            prevnode=currentnode;
            currentnode=nextnode;
        }while(currentnode!=head);
        tail=head;
    head=prevnode;
    }
    
    printf("\nAFTER REVERSING");
    display();
    printf("\n%d",tail->next->data);
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
	printf("\n7. REVERSING THE LIST");
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
