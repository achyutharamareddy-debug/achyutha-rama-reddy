//No. of students above 50 marks
#include<stdio.h>
typedef struct rollmarks
{
	int roll;
	int marks;
}rm;
int main()
{
	int n,i=0,m=0;
	printf("\n Enterthe Number of students : ");
	scanf("%d",&n);
	rm a[n];
	for(i=1;i<=n;i++)
	{
		printf("\nEnter the student roll no. and marks : ");
		scanf("%d %d",&a[i].marks,&a[i].roll);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i].marks>=50)
		{
			m++;
		}
	}
	printf("\nThe total Number of students having marks greater than or equal to 50 are : %d",m);
}
