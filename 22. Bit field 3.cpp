#include<stdio.h>
struct time
{
	unsigned int ss:6;
	unsigned int mm:6;
	unsigned int hh:5;
};
int main()
{
	struct time t;
	int temp;
	printf("\n Enter number of hours : ");
	scanf("%d",&temp);
	t.hh = temp;
	printf("\n Enter number of minutes : ");
	scanf("%d",&temp);
	t.mm = temp;
	printf("\n Enter number of seconds : ");
	scanf("%d",&temp);
	t.ss = temp;
	printf("\n Total time is : %dhh:%dmm:%dss",t.hh,t.mm,t.ss);
}
