#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* removeDuplicateLetters(char* s) {
    int len = strlen(s);
    int last_occurrence[26] = {0};
    bool visited[26] = {false};
    
    // 1. Record the last index of every character
    for (int i = 0; i < len; i++) {
        last_occurrence[s[i] - 'a'] = i;
    }

    char* stack = (char*)malloc(27 * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        int curr = s[i] - 'a';

        // 2. If character is already in our result, skip it
        if (visited[curr]) continue;

        // 3. Monotonic Stack Logic:
        // While stack top is "larger" than current char AND 
        // the top char exists later in the string, remove it.
        while (top >= 0 && stack[top] > s[i] && last_occurrence[stack[top] - 'a'] > i) {
            visited[stack[top--] - 'a'] = false;
        }

        stack[++top] = s[i];
        visited[curr] = true;
    }

    stack[++top] = '\0';
    return stack;
}
