#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestDiverseString(int a, int b, int c) {
    // Maximum possible length of the happy string is a + b + c
    int max_len = a + b + c;
    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    int idx = 0;

    int counts[3] = {a, b, c};
    char chars[3] = {'a', 'b', 'c'};

    while (1) {
        // Step 1: Sort characters based on their remaining counts in descending order
        // A simple bubble pass is perfect since we only have 3 elements
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (counts[j] < counts[j + 1]) {
                    int temp_cnt = counts[j];
                    counts[j] = counts[j + 1];
                    counts[j + 1] = temp_cnt;

                    char temp_ch = chars[j];
                    chars[j] = chars[j + 1];
                    chars[j + 1] = temp_ch;
                }
            }
        }

        // If the largest count is 0, no characters are left to process
        if (counts[0] == 0) {
            break;
        }

        // Step 2: Check if the most frequent character creates a 3-consecutive streak
        if (idx >= 2 && result[idx - 1] == chars[0] && result[idx - 2] == chars[0]) {
            // We cannot use chars[0]. Check if a second choice is available
            if (counts[1] == 0) {
                // No alternative characters are left; we must stop
                break;
            }
            
            // Append the second most frequent character instead
            result[idx++] = chars[1];
            counts[1]--;
        } else {
            // It is safe to use the most frequent character
            result[idx++] = chars[0];
            counts[0]--;
        }
    }

    result[idx] = '\0';
    return result;
}
