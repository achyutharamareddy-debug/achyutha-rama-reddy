// passing adderess of a structure
# include<stdio.h>
struct student
{
	int roll;
	float marks;
};
void display(struct student *s2);
int main()
{
	struct student s1;
	printf("\n enter roll number:");
	scanf("%d",&s1.roll);
	printf("\n enter student marks:");
	scanf("%f",&s1.marks);
	display(&s1);
	return 0;
}
void display(struct student *s2)
{
	printf("\n student roll nr=%d\n student marks=%f",s2->roll,s2->marks);
}

