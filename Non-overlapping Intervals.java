import java.util.Arrays;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // Sort intervals by end time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        
        int count = 0;  // number of non-overlapping intervals
        int prevEnd = Integer.MIN_VALUE;
        
        for (int[] interval : intervals) {
            if (interval[0] >= prevEnd) {
                count++;
                prevEnd = interval[1];
            }
        }
        
        // Total - kept = removed
        return intervals.length - count;
    }
}
