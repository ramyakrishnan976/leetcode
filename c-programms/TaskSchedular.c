#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int leastInterval(char* tasks, int tasksSize, int n) {
    // Array to store frequencies of each uppercase task letter (A-Z)
    int frequencies[26] = {0};
    
    // Count frequencies of each task
    for (int i = 0; i < tasksSize; i++) {
        frequencies[tasks[i] - 'A']++;
    }
    
    // Find the maximum frequency
    int max_freq = 0;
    for (int i = 0; i < 26; i++) {
        if (frequencies[i] > max_freq) {
            max_freq = frequencies[i];
        }
    }
    
    // Find how many tasks share this maximum frequency
    int max_freq_count = 0;
    for (int i = 0; i < 26; i++) {
        if (frequencies[i] == max_freq) {
            max_freq_count++;
        }
    }
    
    // Calculate intervals needed based on the most frequent task framework
    int total_chunks = max_freq - 1;
    int chunk_length = n + 1;
    int minimum_intervals = (total_chunks * chunk_length) + max_freq_count;
    
    // Return the larger value between the calculated minimum and the actual tasks size
    return MAX(tasksSize, minimum_intervals);
}
