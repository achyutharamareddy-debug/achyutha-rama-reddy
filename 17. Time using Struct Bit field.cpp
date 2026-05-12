// Online C compiler to run C program online
#include<stdio.h>
struct time
{
	unsigned int hrs : 5;
	unsigned int min : 6;
	unsigned int sec : 6;
};
int main()
{
	struct time t;
	printf("\nEnter Number of hours : ");
	scanf("%d",t.hrs);
	printf("\nEnter Number of Minutes : ");
	scanf("%d",t.min);
	printf("\nEnter Number of seconds : ");
	scanf("%d",t.sec);
	printf("\nThe total time is : %dhh:%dmm:%dss",t.hrs,t.min,t.sec);
	return 0;
	
	
	
	
	
	
	
	
	
	
}
