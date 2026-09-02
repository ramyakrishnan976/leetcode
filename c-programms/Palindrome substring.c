#include <stdio.h>
#include <string.h>

// Helper function to expand outward from a given center
int expandAroundCenter(char* s, int len, int left, int right) {
    int count = 0;
    
    // Expand outward while characters match and pointers remain inside bounds
    while (left >= 0 && right < len && s[left] == s[right]) {
        count++;
        left--;
        right++;
    }
    
    return count;
}

int countSubstrings(char* s) {
    if (s == NULL) return 0;
    
    int len = strlen(s);
    int totalPalindromes = 0;
    
    for (int i = 0; i < len; i++) {
        // Case 1: Odd-length palindromes (centered directly at index i)
        totalPalindromes += expandAroundCenter(s, len, i, i);
        
        // Case 2: Even-length palindromes (centered between index i and i+1)
        totalPalindromes += expandAroundCenter(s, len, i, i + 1);
    }
    
    return totalPalindromes;
}
