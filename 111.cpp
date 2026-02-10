# include<stdio.h>
struct student
{
	int roll;
	float marks;
};
void display(int a, float b);
int main()
{
	struct student s;
	printf("\n enter roll number:");
	scanf("%d",&s.roll);
	printf("\n enter student marks:");
	scanf("%f",&s.marks);
	return 0;
}
void display(int a, float b)
{
	printf("\n student roll number=%d\n student marks=%f",a,b);
}
