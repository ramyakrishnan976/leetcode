#include <stdio.h>
#include <string.h>

// Helper function to expand around a center and return the length
int expandAroundCenter(char* s, int left, int right) {
    while (left >= 0 && s[right] != '\0' && s[left] == s[right]) {
        left--;
        right++;
    }
    // Length of the palindrome is (right - 1) - (left + 1) + 1
    return right - left - 1;
}

char* longestPalindrome(char* s) {
    if (s == NULL || strlen(s) < 1) return "";
    
    int start = 0;
    int max_len = 0;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        // Case 1: Odd length palindrome (center is s[i])
        int len1 = expandAroundCenter(s, i, i);
        
        // Case 2: Even length palindrome (center is between s[i] and s[i+1])
        int len2 = expandAroundCenter(s, i, i + 1);
        
        // Find the maximum of both expansions
        int current_max = (len1 > len2) ? len1 : len2;
        
        // Update global longest palindrome indices
        if (current_max > max_len) {
            max_len = current_max;
            // Calculate start index based on center 'i' and length
            start = i - (current_max - 1) / 2;
        }
    }
    
    // Terminate the string at the end of the longest palindrome
    // Note: If you cannot modify the input string, you would allocate dynamic memory here.
    s[start + max_len] = '\0';
    return &s[start];
}
