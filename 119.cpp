#include<stdio.h>
typedef struct num
{
	int a[20];
}numbers;
int main()
{
	numbers a;
	int i=1;
	for(i=1;i<=10;i++)
	{
		a.a[i]=i;
	}
	for(i=1;i<11;i++)
	{
		printf("\n%d",a.a[i]);
	}

}
