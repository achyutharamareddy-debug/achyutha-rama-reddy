/*
ENUM: 
	--> It is a user defined datatype it is used to define set of named integer constants
	--> Enum is mainly used when the variable have limited set of fixed values
	--> Enum is commonly used to represent days, states, months, directions, options, etc...
	Syntax: 
		enum enum_name
		{
			constant 1,
			constant 2,
			...    ...
			constant n
		};
	Enum variable declaration 
		enum enum_name object1, object2,...;
*/
#include<stdio.h>
enum days{mon,tue,wed,thur,fri,sat,sun};
int main()
{
	enum days d;
	d=mon;
	printf("%d",d);
}
