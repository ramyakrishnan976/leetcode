#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* breakPalindrome(char* palindrome) {
    int len = strlen(palindrome);
    
    // Step 1: If length is 1, it's impossible to make it non-palindromic
    if (len <= 1) {
        return "";
    }
    
    // Step 2: Scan the first half of the string
    for (int i = 0; i < len / 2; i++) {
        // Change the first non-'a' character to 'a'
        if (palindrome[i] != 'a') {
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    
    // Step 3: If we reach here, the string is entirely made of 'a's (except possibly the middle element)
    // Change the last character to 'b'
    palindrome[len - 1] = 'b';
    
    return palindrome;
}
