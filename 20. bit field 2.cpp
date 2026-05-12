#include<stdio.h>
struct demo
{
	unsigned int a:4;
	unsigned int b:4;
};
int main()
{
	struct demo v;
	int temp;
	printf("\n Enter a value : ");
	scanf("%d",&temp);
	v.a = temp;
	printf("\n Enter b value : ");
	scanf("%d",&temp);
	v.b = temp;
	printf("\n a= %d \n b= %d",v.a,v.b);
}
