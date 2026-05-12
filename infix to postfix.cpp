#include<stdio.h>
#include<ctype.h>
int precedence(char op)
{
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}
int main()
{
    char infix[50], postfix[50], stack[50];
    int i = 0, j = 0, top = -1;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    while(infix[i] != '\0')
    {
        if(isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '(')
        {
            top++;
            stack[top] = infix[i];
        }
        else if(infix[i] == ')')
        {
            while(stack[top] != '(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top--;
        }
        else
        {
            while(top != -1 &&
                 (precedence(stack[top]) > precedence(infix[i]) ||
                 (precedence(stack[top]) == precedence(infix[i]) && infix[i] != '^')))
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top++;
            stack[top] = infix[i];
        }
        i++;
    }
    while(top != -1)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }
    postfix[j] = '\0';
    printf("Postfix Expression: %s", postfix);
    return 0;
}
