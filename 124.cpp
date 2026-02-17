#include<stdio.h>
struct time{
	unsigned int h:24;
	unsigned int m:60;
	unsigned int s:60;
}; int main() { struct time v;
	int h,m,s;
	printf("\nenter h value:");
	scanf("%d",&h);
	printf("\nenter m value:");
	scanf("%d",&m);
	printf("\nenter s value:");
	scanf("%d",&s);
	v.h=h;
	v.m=m;
	v.s=s;
	printf("\n %dhours:%dminutes:%dseconds",v.h,v.m,v.s);
	return 0;
}
