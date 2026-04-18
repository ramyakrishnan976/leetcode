#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculate(char* s) {
    int n = strlen(s);
    int stack[n]; // Stack to store results and signs before parentheses
    int top = -1;
    
    int result = 0;
    int number = 0;
    int sign = 1; // 1 for '+', -1 for '-'

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        } else if (c == '(') {
            // Push current result and sign to stack
            stack[++top] = result;
            stack[++top] = sign;
            // Reset for expression inside parentheses
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * number;
            number = 0;
            // Multiply by the sign before '('
            result *= stack[top--];
            // Add the result before '('
            result += stack[top--];
        }
    }
    
    return result + (sign * number);
}
