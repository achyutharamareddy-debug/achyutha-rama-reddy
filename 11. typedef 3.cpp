#include<stdio.h>
typedef struct num
{
	int a;
}numbers;
int main()
{
	numbers a;
	int i=1;
/*	for(i=1;i<=10;i++)
	{
		a.a[i]=i;
	}
	for(i=1;i<11;i++)
	{
		printf("\n%d",a.a[i]);
	}
	*/
	while(i<11)
	{
		a.a=i;
		printf("\n%d",a.a);
		i++;
	}
}
