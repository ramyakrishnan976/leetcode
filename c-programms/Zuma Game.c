#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Helper function to simulate ball explosions automatically
void updateBoard(char* b) {
    int len = strlen(b);
    bool changed = true;
    
    while (changed) {
        changed = false;
        int i = 0;
        while (i < len) {
            int j = i;
            // Find consecutive blocks of the same color
            while (j < len && b[j] == b[i]) {
                j++;
            }
            // If 3 or more consecutive balls match, eliminate them
            if (j - i >= 3) {
                memmove(&b[i], &b[j], len - j + 1);
                len -= (j - i);
                changed = true;
                break;
            }
            i = j;
        }
    }
}

// Core Backtracking DFS
int dfs(char* board, int* hand_count, int total_hand) {
    // Base Case 1: Successfully cleared the entire board
    if (board[0] == '\0') {
        return 0;
    }
    // Base Case 2: Out of balls in hand but board is not clear
    if (total_hand == 0) {
        return 1e9;
    }

    int min_steps = 1e9;
    int len = strlen(board);
    char colors[] = {'R', 'Y', 'B', 'G', 'W'};

    // Try inserting at every possible boundary index
    for (int i = 0; i <= len; i++) {
        for (int c_idx = 0; c_idx < 5; c_idx++) {
            char c = colors[c_idx];
            if (hand_count[(unsigned char)c] == 0) {
                continue;
            }

            // Apply Greedy Pruning Rules to skip unhelpful moves
            bool worth_trying = false;
            if (i > 0 && board[i - 1] == c) {
                worth_trying = true; // Matches the ball to its left
            }
            if (i < len && board[i] == c) {
                worth_trying = true; // Matches the ball to its right
            }
            if (i > 0 && i < len && board[i - 1] == board[i] && board[i - 1] != c) {
                worth_trying = true; // Intentionally splits an identical pair
            }

            if (!worth_trying) {
                continue;
            }

            // Create the new board configuration after insertion
            char next_board[40];
            strncpy(next_board, board, i);
            next_board[i] = c;
            strcpy(next_board + i + 1, board + i);

            // Cascade ball removals
            updateBoard(next_board);

            // Backtrack
            hand_count[(unsigned char)c]--;
            int current_res = dfs(next_board, hand_count, total_hand - 1);
            if (current_res != 1e9 && current_res + 1 < min_steps) {
                min_steps = current_res + 1;
            }
            hand_count[(unsigned char)c]++; // Revert state
        }
    }
    return min_steps;
}

int findMinStep(char* board, char* hand) {
    int hand_count[256] = {0};
    int total_hand = strlen(hand);

    // Populate our hand color frequencies
    for (int i = 0; hand[i] != '\0'; i++) {
        hand_count[(unsigned char)hand[i]]++;
    }

    int result = dfs(board, hand_count, total_hand);
    return (result == 1e9) ? -1 : result;
}
