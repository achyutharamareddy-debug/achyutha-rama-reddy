/*
TYPEDEF : 
	---> typedef is a keyword which is used to create new names for the existing datatypes,
	---> typedef improves the code readability by allowing programmer to give meaningful names for the dataa types
	---> typedef allows the programmer to rename user defined datatypes such as structures, unions, and enum 
	---> typedef doesn't create new datatype it only provides alternative name for the existing datatype
	---> Syntax : 
			typedef existing_datatype new_name;
*/
#include<stdio.h>
int main()
{
	typedef int integer;
	integer a=10;
	int b=20;
	printf("a = %d; b = %d",a,b);
}
