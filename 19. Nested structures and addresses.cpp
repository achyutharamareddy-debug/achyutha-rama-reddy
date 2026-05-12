//Nested structures and addresses
#include<stdio.h>
struct student 
{
	int roll;
	float marks;
};
int main()
{
	struct student s;
	struct student *ptr;
	ptr = &s;
	int n,i=0;
	printf("\nEnter the Number of students : ");
	scanf("%d",&n);
	printf("\nEnter the roll No. : ");
	scanf("%d",&ptr->roll);
	printf("\nEnter student marks : ");
	scanf("%f",&ptr->marks);
	printf("\n%d \n%f",ptr->roll,ptr->marks);
	return 0;
}
