class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            // Shift to 0-indexed system
            columnNumber--; 
            
            // Get the remainder for the current character
            int remainder = columnNumber % 26;
            result += (remainder + 'A');
            
            // Move to the next higher digit position
            columnNumber /= 26;
        }
        
        // Reverse because characters were added from right to left
        reverse(result.begin(), result.end());
        return result;
    }
};
