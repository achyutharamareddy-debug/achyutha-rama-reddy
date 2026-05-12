#include<Stdio.h>
typedef struct oddoreven
{
	int n;
}odev;
int main()
{
	odev a;
	
	printf("\nEnter a number : ");
	scanf("%d",&a.n);
	if(a.n%2==0)
	{
		printf("\n%d is even",a.n);
	}
	else
	{
		printf("\n%d is odd",a.n);
	}
}
