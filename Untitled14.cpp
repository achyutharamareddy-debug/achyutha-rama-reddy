#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int main() {
    char postfix[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    while (postfix[i] != '\0') {

        // Skip spaces
        if (postfix[i] == ' ' || postfix[i] == '\n') {
            i++;
            continue;
        }

        // If operand (number)
        if (isdigit(postfix[i])) {
            int num = 0;

            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }

            push(num);
        }
        // If operator
        else {
            int op1 = pop();
            int op2 = pop();

            switch (postfix[i]) {
                case '+': push(op2 + op1); break;
                case '-': push(op2 - op1); break;
                case '*': push(op2 * op1); break;

                case '/':
                    if (op1 == 0) {
                        printf("Division by zero error\n");
                        return 1;
                    }
                    push(op2 / op1);
                    break;

                case '^':
                    push((int)pow(op2, op1));
                    break;

                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    return 1;
            }
            i++;
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
