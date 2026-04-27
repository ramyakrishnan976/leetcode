class Solution {
    public int findMinMoves(int[] machines) {
        int total = 0;
        for (int m : machines) total += m;
        
        int n = machines.length;
        
        
        if (total % n != 0) return -1;
        
        int avg = total / n;
        int maxMoves = 0;
        int runningSum = 0;
        
        for (int m : machines) {
            int diff = m - avg;
            runningSum += diff;
            
            maxMoves = Math.max(maxMoves, Math.max(Math.abs(runningSum), diff));
        }
        
        return maxMoves;
    }
}
