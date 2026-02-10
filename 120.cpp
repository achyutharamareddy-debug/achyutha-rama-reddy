#include<stdio.h>
typedef struct num
{
	int a;
}numbers;
int main()
{
	numbers a1;
	printf("enter value:");
	scanf("%d",&a1.a);
	if(a1.a%2 ==0)
	{
		printf("\n %d is even",a1.a);
	}
    else
    {
    	printf("\n %d is not even",a1.a);
	}
}
