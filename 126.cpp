# include<stdio.h>
struct student
{
	int roll;
	float marks;
};
int main()
{
		struct student s;
		struct  student *ptr;
		ptr= &s;
	printf("\n enter roll number");
	scanf("%d",&ptr->roll);
	printf("\n enter student marks");
	scanf("%f",&ptr->marks);
	printf("%d \n %f ",ptr->roll,ptr->marks);
	return 0;
}

