#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to try removing 'count' number of digits belonging to a specific remainder group
int removeDigits(int* counts, int remainder_target, int count_to_remove) {
    int removed = 0;
    // We want to remove the smallest digits first to maximize the final number value
    for (int i = remainder_target; i < 10; i += 3) {
        while (counts[i] > 0 && removed < count_to_remove) {
            counts[i]--;
            removed++;
        }
    }
    return removed == count_to_remove;
}

char* largestMultipleOfThree(int* digits, int digitsSize) {
    int counts[10] = {0};
    int sum = 0;

    // Step 1: Count frequency of each digit and calculate total sum
    for (int i = 0; i < digitsSize; i++) {
        counts[digits[i]]++;
        sum += digits[i];
    }

    // Step 2: Adjust counts based on the remainder to make the sum divisible by 3
    int remainder = sum % 3;
    if (remainder == 1) {
        // Try to remove one digit from remainder group 1 (1, 4, 7)
        if (!removeDigits(counts, 1, 1)) {
            // If not possible, remove two digits from remainder group 2 (2, 5, 8)
            removeDigits(counts, 2, 2);
        }
    } else if (remainder == 2) {
        // Try to remove one digit from remainder group 2 (2, 5, 8)
        if (!removeDigits(counts, 2, 1)) {
            // If not possible, remove two digits from remainder group 1 (1, 4, 7)
            removeDigits(counts, 1, 2);
        }
    }

    // Step 3: Build the largest number from the remaining digit counts
    // Dynamically allocate a buffer large enough to hold all digits plus a null terminator
    char* result = (char*)malloc((digitsSize + 1) * sizeof(char));
    int idx = 0;

    for (int i = 9; i >= 0; i--) {
        while (counts[i] > 0) {
            result[idx++] = i + '0';
            counts[i]--;
        }
    }
    result[idx] = '\0';

    // Step 4: Handle special cases (Empty strings or multiple leading zeros)
    if (idx == 0) {
        free(result);
        return "";
    }
    if (result[0] == '0') {
        // If the biggest digit is 0, the whole answer collapses to just "0"
        result[1] = '\0';
    }

    return result;
}
