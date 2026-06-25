#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    // Array to store the last seen position of all 128 ASCII characters
    // Initialize all positions to -1
    int last_seen[128];
    for (int i = 0; i < 128; i++) {
        last_seen[i] = -1;
    }
    
    int max_len = 0;
    int left = 0;
    int right = 0;
    
    while (s[right] != '\0') {
        char current_char = s[right];
        
        // If the character was seen inside the current window, shrink the window
        if (last_seen[(unsigned char)current_char] >= left) {
            left = last_seen[(unsigned char)current_char] + 1;
        }
        
        // Record/update the current character's last seen position
        last_seen[(unsigned char)current_char] = right;
        
        // Calculate window size and update max_len
        int current_len = right - left + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
        
        right++;
    }
    
    return max_len;
}
