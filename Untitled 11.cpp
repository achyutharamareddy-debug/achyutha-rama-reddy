#include <stdio.h>
#include <ctype.h>
#include <string.h>


int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}


void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

int main() {
    char infix[50], stack[50], result[50];
    int i = 0, j = 0, top = -1;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }


    i = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) {
            result[j++] = infix[i];
        } 
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } 
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }
            top--; 
        } 
        else {
            
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) > precedence(infix[i])) {
                result[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }

    while (top != -1) {
        result[j++] = stack[top--];
    }
    result[j] = '\0';

    reverse(result);

    printf("Prefix expression: %s\n", result);

    return 0;
}
