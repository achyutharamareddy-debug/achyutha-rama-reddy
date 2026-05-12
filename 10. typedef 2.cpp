/*
typedef syntax for structure
		
			typedef struct structure_name
			{
			datatype element1;
				datatype element2;
				...			...
				...			...
				datatype element n;			
			}new_name;
*/
#include<stdio.h>
typedef struct student
{
	int roll;
	float marks;
}stu;
int main()
{
	stu a1,a2;
	a1.roll=10;
	a1.marks=90.26;
	a2.roll=11;
	a2.marks=85.25;
	printf("\n%d\n%f\n%d\n%f",a1.roll,a1.marks,a2.roll,a2.marks);
	return 0;
}
