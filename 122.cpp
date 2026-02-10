#include<stdio.h>
enum signal {red=1,yellow,green};
int main()
{
	int s;
	printf("\n enter choice:");
	scanf("%d",&s);
	switch(s)
	{
		case red:
			printf("\n STOP");
			break;
		case yellow :
		    printf("\n ready to go");
		    break;
		case green:
			printf("\n go");
			break ;
			default:
			printf("\n ERROR");
	}
	return 0;
	 }     
              

           
