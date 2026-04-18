#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int n = strlen(s);
    int countStack[100];
    char* stringStack[100];
    int top = -1;

    char* currStr = (char*)calloc(100001, sizeof(char));
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            // Build the number k (can be multiple digits)
            k = k * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            // Push current state to stacks
            countStack[++top] = k;
            stringStack[top] = currStr;
            
            // Start fresh for inner string
            currStr = (char*)calloc(100001, sizeof(char));
            k = 0;
        } else if (s[i] == ']') {
            char* prevStr = stringStack[top];
            int repeatTimes = countStack[top--];
            
            char* expanded = (char*)calloc(100001, sizeof(char));
            strcpy(expanded, prevStr);
            
            // Append current string k times to the previous string
            for (int j = 0; j < repeatTimes; j++) {
                strcat(expanded, currStr);
            }
            
            free(currStr);
            free(prevStr);
            currStr = expanded;
        } else {
            // Append character to current string
            int len = strlen(currStr);
            currStr[len] = s[i];
            currStr[len + 1] = '\0';
        }
    }
    return currStr;
}
