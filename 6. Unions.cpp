/*UNIONS : 
	---> Union is a user defined data type, it contains different type of data members,
		these data members are identifes or refered with union key word
	---> It is similar to structures but the only difference is that,
		the size of the union is equal to the maximum/highest/largest size of its data member,
	---> In union all the data members shares the common memory.
	---> These Union's are reffered with "union" keyword.
	---> Here we use the keyword called "union" to dealare the variables
	---> syntax
			union unionname
			{
				datatype element1;
				datatype element2;
				...			...
				...			...
				datatype element n;			
			};
			int main()
			{
				union unionname obj1,obj2,obj3,....;     
			}
	---> We usually don't use the "union" because we will loss the data
	---> Variable initialization
			variablename.datamember = value;
	---> Accessing isalso same as the variable declaration/initialization
*/
#include<stdio.h>
union student
{
	int roll;
	float marks;
};
int main()
{
	union student s;
	s.roll=149;
	s.marks=98.6;
	printf("\nSize of s is %d",sizeof(s));
	printf("\nStudent Roll No. : %d",s.roll);
	printf("\nStudent marks = %f",s.marks);
	return 0;
}
