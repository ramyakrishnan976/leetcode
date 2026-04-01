#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int sIdx = 0, pIdx = 0;
        int lastStarIdx = -1, sMatchIdx = 0;
        int n = s.length(), m = p.length();

        while (sIdx < n) {
            // 1. Characters match or pattern has '?'
            if (pIdx < m && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // 2. Pattern has '*'
            else if (pIdx < m && p[pIdx] == '*') {
                lastStarIdx = pIdx;   // Record star position
                sMatchIdx = sIdx;     // Record string position to 'greedy' match
                pIdx++;               // Try matching '*' with empty sequence first
            }
            // 3. Mismatch, but we saw a '*' earlier
            else if (lastStarIdx != -1) {
                pIdx = lastStarIdx + 1; // Reset pattern to just after the '*'
                sMatchIdx++;            // '*' now matches one more character in s
                sIdx = sMatchIdx;       // Start string pointer from new match point
            }
            // 4. Mismatch and no '*' to bail us out
            else {
                return false;
            }
        }

        // Check if remaining characters in pattern are all '*'
        while (pIdx < m && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == m;
    }
};
