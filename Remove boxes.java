class Solution {
    public int removeBoxes(int[] boxes) {
        int n = boxes.length;
        // dp[i][j][k] stores results for subarray boxes[i...j] with k matching elements preceding boxes[i]
        int[][][] memo = new int[n][n][n];
        return calculatePoints(boxes, 0, n - 1, 0, memo);
    }

    private int calculatePoints(int[] boxes, int i, int j, int k, int[][][] memo) {
        // Base case: empty subarray
        if (i > j) {
            return 0;
        }

        // Return cached result if already computed
        if (memo[i][j][k] != 0) {
            return memo[i][j][k];
        }

        // Optimization: Collapse identical consecutive elements to reduce recursion depth
        int startI = i;
        int startK = k;
        while (i + 1 <= j && boxes[i + 1] == boxes[i]) {
            i++;
            k++;
        }

        // Strategy 1: Eliminate the current box(es) immediately along with the k preceding matching boxes
        int maxPoints = (k + 1) * (k + 1) + calculatePoints(boxes, i + 1, j, 0, memo);

        // Strategy 2: Keep the current block and find another matching box down the line (at index m)
        // to merge with them after destroying the intermediate elements boxes[i+1 ... m-1]
        for (int m = i + 1; m <= j; m++) {
            if (boxes[m] == boxes[i]) {
                int intermediatePoints = calculatePoints(boxes, i + 1, m - 1, 0, memo);
                int mergedPoints = calculatePoints(boxes, m, j, k + 1, memo);
                maxPoints = Math.max(maxPoints, intermediatePoints + mergedPoints);
            }
        }

        // Store result in the original state before optimization
        return memo[startI][j][startK] = maxPoints;
    }
}
