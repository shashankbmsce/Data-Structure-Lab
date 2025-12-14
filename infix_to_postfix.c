#include <stdio.h>
#include <ctype.h>

char stack[50];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int priority(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main() {
    char infix[50], postfix[50];
    int i = 0, j = 0;
    char ch;

    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {

        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();
        }
        else {
            while (top != -1 && priority(stack[top]) >= priority(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("%s", postfix);

    return 0;
}

