# include<stdio.h>
typedef struct student  //starting
{                            
	int roll;
	float marks;
} stu;                  // entire datatype
int main()
{
	stu a1,a2;
	a1.roll=10;
	a1.marks=90.26;
	a2.roll=11;
	a2.marks=98.6;
	printf("\n %d %f %d %f ",a1.roll,a1.marks,a2.roll,a2.marks);
	return 0;
}
 
