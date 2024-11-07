#include <stdio.h>
#include <string.h>
#define MAX 20

int top = -1;
char stack[MAX];

// Function to pop from the stack
char pop() {
    char a = stack[top];
    top--;
    return a;
}

// Function to push onto the stack
void push(char item) {
    top++;
    stack[top] = item;
}

// Function to return the precedence of an operator
int prcd(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
        case '$':
            return 6;
        case '(':
        case ')':
        case '#':
            return 1;
        default:
            return -1;
    }
}

// Function to check if the character is an operator
int isoperator(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '$':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

// Function to convert infix expression to postfix
void convertip(char infix[], char postfix[]) {
    int i, symbol, j = 0;
    stack[++top] = '#';  // Push the sentinel '#' onto the stack

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        // If symbol is not an operator, add it directly to the postfix expression
        if (isoperator(symbol) == 0) {
            postfix[j] = symbol;
            j++;
        } else {
            if (symbol == '(') {
                push(symbol);  // Push '(' onto the stack
            } else if (symbol == ')') {
                while (stack[top] != '(') {
                    postfix[j] = pop();
                    j++;
                }
                pop();  // Pop out '('
            } else {
                // If operator precedence is lower or equal to top of stack
                while (prcd(symbol) <= prcd(stack[top])) {
                    postfix[j] = pop();
                    j++;
                }
                push(symbol);  // Push the current operator onto the stack
            }
        }
    }

    // Pop all the remaining operators in the stack
    while (stack[top] != '#') {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[20], postfix[20];

    printf("Enter the valid infix string: ");
    fgets(infix, sizeof(infix), stdin);  // Use fgets for safer input
    infix[strcspn(infix, "\n")] = '\0';  // Remove trailing newline from fgets

    convertip(infix, postfix);

    printf("The corresponding postfix string is: ");
    puts(postfix);

    return 0;
}
