#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValid(char* code) {
    int n = strlen(code);
    char stack[500][10]; // Stack to store TAG_NAMEs
    int top = -1;

    for (int i = 0; i < n; ) {
        // Rule 1: Everything must be wrapped in a root tag
        if (i > 0 && top == -1) return false;

        if (strncmp(code + i, "<![CDATA[", 9) == 0) {
            // Rule 7 & 8: Handle CDATA
            if (top == -1) return false; // CDATA must be inside a tag
            i += 9;
            char* endCdata = strstr(code + i, "]]>");
            if (!endCdata) return false;
            i = (endCdata - code) + 3;
        } else if (strncmp(code + i, "</", 2) == 0) {
            // Rule 2: End Tag
            i += 2;
            char* closeBracket = strchr(code + i, '>');
            if (!closeBracket) return false;
            
            int len = closeBracket - (code + i);
            if (len < 1 || len > 9 || top == -1) return false;
            
            char tagName[10];
            strncpy(tagName, code + i, len);
            tagName[len] = '\0';
            
            // Check if matches the start tag at the top of stack
            if (strcmp(stack[top--], tagName) != 0) return false;
            i = (closeBracket - code) + 1;
        } else if (code[i] == '<') {
            // Rule 2 & 3: Start Tag
            i++;
            char* closeBracket = strchr(code + i, '>');
            if (!closeBracket) return false;
            
            int len = closeBracket - (code + i);
            if (len < 1 || len > 9) return false;
            
            char tagName[10];
            for (int j = 0; j < len; j++) {
                if (!isupper(code[i + j])) return false;
                tagName[j] = code[i + j];
            }
            tagName[len] = '\0';
            
            strcpy(stack[++top], tagName);
            i = (closeBracket - code) + 1;
        } else {
            // Regular text
            if (top == -1) return false;
            i++;
        }
    }
    return top == -1; // Stack must be empty if all tags are closed
}
