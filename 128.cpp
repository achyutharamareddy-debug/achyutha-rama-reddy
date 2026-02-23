# include<stdio.h>
struct student
{   
	int roll;
	float marks;
};
	int main()
	{
	struct student s[3];
	struct student *ptr;
	int i;
	ptr=s;
	for(i=0;i<3;i++)
	{
		printf("\n enter %d student roll number & marks",i+1);
		scanf("%d %f",&ptr[i].roll,&ptr[i].marks);
	}
	for(i=0;i<3;i++)
	{
		printf("\n student roll=%d\n student marks =%f",ptr[i].roll,ptr[i].marks);
	}
}

