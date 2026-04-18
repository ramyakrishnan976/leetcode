#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* simplifyPath(char* path) {
    int n = strlen(path);
    char **stack = (char**)malloc(n * sizeof(char*));
    int top = 0;

    // Use strtok to split the string by '/'
    char *token = strtok(path, "/");
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (top > 0) top--; // Go up one level
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            stack[top++] = token; // Valid directory name
        }
        token = strtok(NULL, "/");
    }

    // If stack is empty, we are at root
    if (top == 0) return "/";

    // Build the result string
    char *result = (char*)malloc(n + 1);
    result[0] = '\0';
    for (int i = 0; i < top; i++) {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    free(stack);
    return result;
}
