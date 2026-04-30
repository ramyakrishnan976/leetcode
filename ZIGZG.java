class Solution {
    public String convert(String s, int numRows) {
        // Base case: If only 1 row or string is shorter than rows, no change needed
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a list of StringBuilders, one for each row
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }

        int currentRow = 0;
        boolean goingDown = false;

        // Iterate through the string
        for (char c : s.toCharArray()) {
            rows[currentRow].append(c);
            
            // Reverse direction when we hit the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            
            // Move up or down
            currentRow += goingDown ? 1 : -1;
        }

        // Combine all rows into a single StringBuilder
        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }
}
