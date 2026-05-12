//Traffic Lights
#include<stdio.h>
enum traffic{green=1,red,orange};
int main()
{
	enum traffic t;
	printf("\n Enter accordingly [green=1/red=2/orange=3] : ");
	scanf("%d",&t);
	switch(t)
	{
		case green:
			printf("\n....You May GO....");   
			break;
		case red:
			printf("\n....Please stop....");
			break;
		case orange:
			printf("\n....Wait....");
			break;
	}
}
