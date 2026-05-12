//shoping mall, floor, according to gender
#include<stdio.h>
enum floor{female=1,male,kids};
int main()
{
	enum floor gen;
	printf("Enter accordingly [female=1/male=2/kids=3] : ");
	scanf("%d",&gen);
	switch(gen)
	{
		case female :
			printf("\n....Go to FIRST floor....");
			break;
		case male :
			printf("\n....Go to SECOND floor....");
			break;
		case kids :
			printf("\n....Go to THIRD floor....");
			break;
		default:
			printf("\n....Enter a valid choice....");
	}
	return 0;
}
