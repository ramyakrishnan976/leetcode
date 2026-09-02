#include <stdio.h>
#include <string.h>

int checkRecord(int n) {
    long long MOD = 1000000007;

    // dp[A][L] represents the number of valid sequences where:
    // A = number of 'A's seen so far (0 or 1)
    // L = number of consecutive 'L's ending at the current day (0, 1, or 2)
    long long dp[2][3] = {0};

    // Base case: Day 0 (empty string) has 1 valid arrangement
    dp[0][0] = 1;

    for (int day = 1; day <= n; day++) {
        long long next_dp[2][3] = {0};

        // 1. If we append 'P' (Present)
        // This resets consecutive lates (L) to 0 for both total absence counts.
        next_dp[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;
        next_dp[1][0] = (dp[1][0] + dp[1][1] + dp[1][2]) % MOD;

        // 2. If we append 'A' (Absent)
        // This increases total absence count by 1 and resets consecutive lates (L) to 0.
        // We can only transition from states that had 0 absences previously.
        next_dp[1][0] = (next_dp[1][0] + dp[0][0] + dp[0][1] + dp[0][2]) % MOD;

        // 3. If we append 'L' (Late)
        // This increments the consecutive lates count.
        next_dp[0][1] = dp[0][0];
        next_dp[0][2] = dp[0][1];
        next_dp[1][1] = dp[1][0];
        next_dp[1][2] = dp[1][1];

        // Move the next day's calculations to our current tracker
        memcpy(dp, next_dp, sizeof(dp));
    }

    // Sum up all valid combination states at day N
    long long total = 0;
    for (int a = 0; a < 2; a++) {
        for (int l = 0; l < 3; l++) {
            total = (total + dp[a][l]) % MOD;
        }
    }

    return (int)total;
}
