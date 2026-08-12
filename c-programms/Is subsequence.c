#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int i = 0; // Pointer for s
    int j = 0; // Pointer for t
    
    // Scan both strings until one reaches its null terminator
    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++; // Move to the next character we need to match in s
        }
        j++; // Always move forward in t
    }
    
    // If we matched every character in s, i will point to the null terminator
    return s[i] == '\0';
}
