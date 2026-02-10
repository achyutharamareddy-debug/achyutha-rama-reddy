# include<stdio.h>
struct student
{
	int roll;
	float marks;
};
int main()
{
	struct student s1,s2;
	s1.roll =101;
	s1.marks=98.6;
	s2=s1;
	printf("\n student roll number=%d\n student marks=%f",s2.roll,s2.marks);
	return 0;
}
