#include <string.h>
#include <limits.h> // Correct header for C programs

char* minWindow(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    
    if (s_len == 0 || t_len == 0 || s_len < t_len) {
        return "";
    }

    int t_count[128] = {0};
    int window_count[128] = {0};

    for (int i = 0; i < t_len; i++) {
        t_count[(unsigned char)t[i]]++;
    }

    int required = 0;
    for (int i = 0; i < 128; i++) {
        if (t_count[i] > 0) {
            required++;
        }
    }

    int left = 0, right = 0;
    int formed = 0; 
    
    int min_len = INT_MAX;
    int start_idx = 0;

    while (right < s_len) {
        char c = s[right];
        window_count[(unsigned char)c]++;

        if (t_count[(unsigned char)c] > 0 && window_count[(unsigned char)c] == t_count[(unsigned char)c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = s[left];

            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start_idx = left;
            }

            window_count[(unsigned char)c]--;
            if (t_count[(unsigned char)c] > 0 && window_count[(unsigned char)c] < t_count[(unsigned char)c]) {
                formed--;
            }
            left++;
        }
        right++;
    }

    if (min_len == INT_MAX) {
        return "";
    }

    s[start_idx + min_len] = '\0';
    return &s[start_idx];
}
