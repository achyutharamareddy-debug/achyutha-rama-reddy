// Infix to Prefix 
#include<stdio.h>
#include<ctype.h>
#include<string.h>
int precedence(char op)
{
	if(op == '^')
	{
		return 3;
	}
	if(op == '*'|| op == '/')
	{
		return 2;
	}
	if(op == '+'|| op == '-')
	{
		return 1;
	}
	return 0;
}

//void reverse(char arr[])
//{
//    int start=0,n,temp;
//    n = strlen(arr);
//    int end = n-1;
//
//    while (start < end)
//	{
//        temp = arr[start];
//        arr[start] = arr[end];
//        arr[end] = temp;
//        start++;
//        end--;
//    }
//}
int main()
{
	char infix[50],stack[50],postfix[50];
	int i=0,j=0,top=-1;
	printf("\nEnter the Infix Expression :\t ");
	scanf("%s",infix);
	strrev(infix);
	while(infix[i]!='\0')
	{
		if(isalnum(infix[i]))
		{
			postfix[j] = infix[i];
			j++;
		}
		else if(infix[i]==')')
		{
			top++;
			stack[top] = infix[i];
		}
		else if(infix[i]=='(')
		{
			while(stack[top]!=')')
			{
				postfix[j] = stack[top];
				top--;
				j++;
			}
			top--;
		}
		else
		{
			while(top != -1 && ( precedence(stack[top]) > precedence(infix[i]) || precedence(stack[top]) == precedence(infix[i]) ) && infix[i] == '^')
			{
				postfix[j] = stack[top];
				top--;
				j++;
			}
			top++;
			stack[top] = infix[i];
		}
		i++;
	}
	while(top != -1)
	{
		postfix[j] = stack[top];
		top--;
		j++;
	}
	strrev(postfix);
	postfix[j] = '\0';
	printf("\nThe postfix Expression is : \t %s",postfix);
	return 0;
}
