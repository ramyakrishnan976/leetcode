#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1e9

// Global/Helper state tracker for memoization
int* memo;

int dfs(int mask, char* target, int targetLen, int stickerCounts[][26], int numStickers) {
    // Return cached value if this exact subset layout has already been evaluated
    if (memo[mask] != -1) {
        return memo[mask];
    }

    // Find the first unfilled character index in target
    int firstUnassignedIdx = -1;
    for (int i = 0; i < targetLen; i++) {
        if (!(mask & (1 << i))) {
            firstUnassignedIdx = i;
            break;
        }
    }

    // Base case: All characters are filled successfully
    if (firstUnassignedIdx == -1) {
        return 0;
    }

    char targetChar = target[firstUnassignedIdx];
    int minStickers = INF;

    // Try applying every sticker that can help fill this specific anchor character
    for (int i = 0; i < numStickers; i++) {
        // Optimization: Skip stickers that do not contain our target missing anchor character
        if (stickerCounts[i][targetChar - 'a'] == 0) {
            continue;
        }

        // Create a local tracking copy of the sticker frequencies to consume
        int remainingLetters[26];
        memcpy(remainingLetters, stickerCounts[i], 26 * sizeof(int));
        int nextMask = mask;

        // Try to satisfy as many unfilled target characters as possible using this sticker
        for (int j = 0; j < targetLen; j++) {
            if (!(nextMask & (1 << j))) {
                char c = target[j];
                if (remainingLetters[c - 'a'] > 0) {
                    remainingLetters[c - 'a']--;
                    nextMask |= (1 << j); // Mark this character position as completed
                }
            }
        }

        // Recurse into the subproblem with the newly updated bitmask layout
        int residualCost = dfs(nextMask, target, targetLen, stickerCounts, numStickers);
        if (residualCost != INF) {
            if (1 + residualCost < minStickers) {
                minStickers = 1 + residualCost;
            }
        }
    }

    return memo[mask] = minStickers;
}

int minStickers(char** stickers, int stickersSize, char* target) {
    int targetLen = strlen(target);
    int numStates = 1 << targetLen;

    // Precompute character frequencies for each sticker
    int (*stickerCounts)[26] = malloc(stickersSize * sizeof(*stickerCounts));
    for (int i = 0; i < stickersSize; i++) {
        memset(stickerCounts[i], 0, 26 * sizeof(int));
        for (int j = 0; stickers[i][j] != '\0'; j++) {
            stickerCounts[i][stickers[i][j] - 'a']++;
        }
    }

    // Allocate memory for the memo table dynamically and initialize with -1
    memo = (int*)malloc(numStates * sizeof(int));
    memset(memo, -1, numStates * sizeof(int));

    int result = dfs(0, target, targetLen, stickerCounts, stickersSize);

    // Free all dynamically allocated memories to completely eliminate leaks
    free(memo);
    free(stickerCounts);

    return result >= INF ? -1 : result;
}
