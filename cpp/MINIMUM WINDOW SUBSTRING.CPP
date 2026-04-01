#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        // Frequency maps using arrays for performance (ASCII 128)
        std::vector<int> target(128, 0);
        for (char c : t) target[c]++;

        std::vector<int> window(128, 0);
        int left = 0, right = 0;
        int required = 0; // Number of unique chars in t met in current window
        for (int count : target) if (count > 0) required++;
        
        int formed = 0; // Unique chars in current window that meet target count
        int minLen = INT_MAX, startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            window[c]++;
            
            // If frequency of current char matches target frequency
            if (target[c] > 0 && window[c] == target[c]) {
                formed++;
            }

            // Try to shrink the window
            while (left <= right && formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                
                // If removing this char makes the window invalid
                if (target[leftChar] > 0 && window[leftChar] < target[leftChar]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
