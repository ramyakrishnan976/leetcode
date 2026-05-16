class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0;
        
        for (char c : columnTitle) {
            // Shift existing digits left by base 26 and add current character value
            result = result * 26 + (c - 'A' + 1);
        }
        
        return result;
    }
};
