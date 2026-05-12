/*Command Line Arguments 
		these arguments are passsed from commandline are called command line arguments, 
		these arguments are handled by main function,
		to support these arguments you need to change the structure of main function.
		i.e., int main(int argc, char *argv[])
		-->  "argc" counts the number of arguments given/entered by the user 
		-->  The first argument is always the name of the program
		-->  "argv" contains the total number of arguments*/
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	if(argc!=5)
	{
		printf("\n usage %s : <name> <marks1> <marks2> <marks3> ",argv[0]);
		return 1;
	}
	char *name= argv[1];
	int m1= atoi(argv[2]);
	int m2= atoi(argv[3]);
	int m3= atoi(argv[4]);
	int total = m1+m2+m3;
	printf("\n Name of the program :%s",argv[0]);
	printf("\n Student name : %s",name);
	printf("\n %d %d %d ",m1,m2,m3);
	printf("\n Total = %d",total);
	return 0;
}
