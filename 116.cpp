#include<stdio.h>
#include<string.h>
union Employee
{
	char ename[];
	int eid;
	float esal;
};
int main()
{
	union Employee e;
	e.eid=667;
	e.esal=500.001;
	strcpy(e.ename,"Siddu");
	printf("\nSize of e is %d",sizeof(e));
	printf("\nEmployee ID : %d",e.eid);
	printf("\nEmployee Name = %s",e.ename);
	printf("\nEmployee Salary = %f",e.esal);
	return 0;
}
