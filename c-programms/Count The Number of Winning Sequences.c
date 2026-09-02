#include <stdio.h>
#include <string.h>

#define MOD 1000000007
#define OFFSET 1000
#define MAX_SCORE 2001

// Helper function to map characters to integers
int getCreatureId(char c) {
    if (c == 'F') return 0;
    if (c == 'W') return 1;
    return 2; // 'E'
}

// Helper function to get Bob's net score for a round
int getRoundScore(int bob, int alice) {
    if (bob == alice) return 0;
    // F (0) beats E (2)
    if (bob == 0 && alice == 2) return 1;
    // W (1) beats F (0)
    if (bob == 1 && alice == 0) return 1;
    // E (2) beats W (1)
    if (bob == 2 && alice == 1) return 1;
    // Otherwise Alice wins
    return -1;
}

int countWinningSequences(char* s) {
    int n = strlen(s);
    
    // dp[last_move][score_diff]
    // 0: 'F', 1: 'W', 2: 'E'
    int dp[3][MAX_SCORE];
    int next_dp[3][MAX_SCORE];
    
    memset(dp, 0, sizeof(dp));
    
    // Base Case: Initialize for the first round (i = 0)
    int alice_first = getCreatureId(s[0]);
    for (int j = 0; j < 3; j++) {
        int score = getRoundScore(j, alice_first);
        dp[j][OFFSET + score] = 1;
    }
    
    // Iterate through rounds 1 to n-1
    for (int i = 1; i < n; i++) {
        int alice_move = getCreatureId(s[i]);
        memset(next_dp, 0, sizeof(next_dp));
        
        for (int last_j = 0; last_j < 3; last_j++) {
            for (int cur_j = 0; cur_j < 3; cur_j++) {
                // Bob cannot choose the same creature in two consecutive rounds
                if (cur_j == last_j) continue;
                
                int score = getRoundScore(cur_j, alice_move);
                
                for (int diff = 0; diff < MAX_SCORE; diff++) {
                    if (dp[last_j][diff] > 0) {
                        int next_diff = diff + score;
                        if (next_diff >= 0 && next_diff < MAX_SCORE) {
                            next_dp[cur_j][next_diff] = (next_dp[cur_j][next_diff] + dp[last_j][diff]) % MOD;
                        }
                    }
                }
            }
        }
        // Roll over the current round states to the next round baseline
        memcpy(dp, next_dp, sizeof(dp));
    }
    
    // Sum up all winning sequences where Bob's net score is strictly greater than 0 (diff > OFFSET)
    long long total_winning_ways = 0;
    for (int j = 0; j < 3; j++) {
        for (int diff = OFFSET + 1; diff < MAX_SCORE; diff++) {
            total_winning_ways = (total_winning_ways + dp[j][diff]) % MOD;
        }
    }
    
    return (int)total_winning_ways;
}
