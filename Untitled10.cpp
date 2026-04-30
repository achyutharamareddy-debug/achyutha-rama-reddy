#include <stdio.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; 

int main() {
    char infix[50], stack[50], postfix[50];
    int i = 0, j = 0, top = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') {
        
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } 
    
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } 
        
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--; 
        } 
        
        else {
            
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }

    
    while (top != -1) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
