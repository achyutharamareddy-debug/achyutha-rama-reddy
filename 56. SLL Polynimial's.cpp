// Single Linked List's Polynimial's
#include<stdio.h>
#include<stdlib.h>
void display();
struct polynomial
{
	int coeff;
	int degree;
	struct polynomial *link;
};
struct polynomial *head = NULL, *temp = NULL;
int d;
void createpoly()
{
	struct polynomial *newcoeff = NULL;
	int i=0;
	printf("\nEnter the degree of the polynomial : ");
	scanf("%d",&d);
	temp=head;
	for(i=d;i>=0;i--)
	{
		newcoeff = (struct polynomial *)malloc(sizeof(struct polynomial));
		newcoeff->link = NULL;
		printf("\nEnter the coefficient of degree '%d' : ",i);
		scanf("%d",&newcoeff->coeff);
		newcoeff->degree = i;
		if(head==NULL)
		{
			head = temp = newcoeff;
		}
		else
		{
			temp->link = newcoeff;
			temp = newcoeff;
		}
	}
}
void displaypoly()
{
	temp = head;
	int i=0;
	printf("\n The POLYNOMIAL Equation is : \n\n\t");
	for(i=d;i>=0;i--)
	{
		if(i==d)
		{
			printf(" (%d)x^%d + ",temp->coeff,temp->degree);
			temp = temp->link;
		}
		else if(i==0)
		{
			printf(" (%d)x^%d",temp->coeff,temp->degree);
			temp = temp->link;
		}
		else
		{
			printf(" (%d)x^%d + ",temp->coeff,temp->degree);
			temp = temp->link;
		}
	}
}
int main()
{
	createpoly();
	displaypoly();
	return 0;
}
