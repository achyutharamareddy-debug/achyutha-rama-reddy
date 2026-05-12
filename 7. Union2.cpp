#include<stdio.h>
union student
{
	int roll;
	float marks;
	char grade;
};
int main()
{
	union student s;
	s.roll=149;
	s.grade='A';
	s.marks=98.6;
	printf("\nSize of s is %d",sizeof(s));
	printf("\nStudent Roll No. : %d",s.roll);
	printf("\nStudent marks = %f",s.marks);
	printf("\nStudent grade = %c",s.grade);
	return 0;
}
