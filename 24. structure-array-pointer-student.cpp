//structure-array-pointer-student
#include<stdio.h>
typedef struct student 
{
	char name[100];
	int roll;
	float marks;
}stu;
int main()
{
	int n;
	printf("\nEnter Number of students : ");
	scanf("%d",&n);
	stu s[n];
	stu *ptr=s;
	for(int i=0;i<n;i++)
	{
		printf("\nEnter student %d name : ",i+1);
		scanf(" %[^\n]s",ptr[i].name);
		printf("\nEnter student %d roll No. :",i+1);
		scanf("%d",&ptr[i].roll);
		printf("\nEnter student %d marks :",i+1);
		scanf("%f",&ptr[i].marks);
	}
	for(int i=0;i<n;i++)
	{
		printf("\nStudent %d name : %s ",i+1,ptr[i].name);
		printf("\nStudent %d roll No. : %d",i+1,ptr[i].roll);
		printf("\nStudent %d marks : %.2f",i+1,ptr[i].marks);
	}
}
