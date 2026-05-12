//Passint individual data 
#include<stdio.h>
void display (int a, float b);
struct student
{
	int roll;
	float marks;
};
int main()
{
	struct student s;
	printf("Enter Roll No. : ");
	scanf("%d",&s.roll);
	printf("\nEnter Marks : ");
	scanf("%f",&s.marks);
	display(s.roll,s.marks);
	return 0;
}
void display(int a,float b)
{
	printf("\nStudent roll number : %d \nSudent marks : %f",a,b);
}
