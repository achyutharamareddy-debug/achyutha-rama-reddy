/*Bit field
	--> Bit field is used to specify the number of bits allocated to the structured member,
	--> It is mainly ised to save memory,
	--> Bit fields are only alloowed in structures inly,
	--> Bitfield doesn't support for arrays and pointers,
	--> Each bitfield member must be in INTEGER format and it doesn't support float and double,
	Syntax:
		struct structure_name
		{
		datatype member_name : number_of_bits;
		};
	--> Number of bits defines, how many bits the member should occupy.
*/
#include<stdio.h>
struct demo
{
	unsigned int a:2;
	unsigned int b:3;
};
int main()
{
	struct demo v;
	v.a=3;
	v.b=7;
	printf("\n a= %d \n b= %d",v.a,v.b);
}
