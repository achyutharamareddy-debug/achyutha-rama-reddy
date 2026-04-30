#include <stdio.h>
#include <ctype.h>
#include <math.h> 

int stack[100];
int top = -1;

int main() 
{
    char postfix[50];
    int i = 0;

    printf("\n Enter postfix expression: "); 
    fgets(postfix, sizeof(postfix), stdin);

    while (postfix[i] != '\0') 
    {
        if (postfix[i] == ' ' || postfix[i] == '\n') 
        {
            i++;
            continue;
        }

        if (isdigit(postfix[i])) 
        {
            int num = 0;
            while (isdigit(postfix[i])) 
            {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            top++;
            stack[top] = num;
            continue;
        } 
        else 
        {
            int op1, op2;
            
        
            op1 = stack[top];
            top--;
            
            
            op2 = stack[top];
            top--;

            switch (postfix[i]) 
            {
                case '+':
                    top++;
                    stack[top] = op2 + op1;
                    break;
                case '-':
                    top++;
                    stack[top] = op2 - op1;
                    break;
                case '*':
                    top++;
                    stack[top] = op2 * op1;
                    break;
                case '/':
                    top++;
                    stack[top] = op2 / op1;
                    break;
                case '^':
                    top++;
                    
                    stack[top] = (int)pow(op2, op1);
                    break;
            }
            i++; 
        }
    }

    printf("\n Result: %d\n", stack[top]);
    return 0;
}
