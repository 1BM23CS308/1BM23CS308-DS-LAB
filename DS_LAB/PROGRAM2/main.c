#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char x) {
    if (x == '^') {
        return 3;
    } else if (x == '*' || x == '/') {
        return 2;
    } else if (x == '+' || x == '-') {
        return 1;
    } else {
        return 0;
    }
}

int isOperand(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return 1;
    }
    return 0;
}

void infixToPostfix(char* exp) {
    char postfix[MAX];
    int i, j = 0;

    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isOperand(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}
