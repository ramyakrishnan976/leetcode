class Solution {
    public int buttonWithLongestTime(int[][] events) {
        // Initial button and time
        int resIndex = events[0][0];
        int maxTime = events[0][1];

        for (int i = 1; i < events.length; i++) {
            int currentIndex = events[i][0];
            int duration = events[i][1] - events[i - 1][1];

            // Update if duration is longer
            if (duration > maxTime) {
                maxTime = duration;
                resIndex = currentIndex;
            } 
            // If duration is tied, choose the smaller index
            else if (duration == maxTime) {
                if (currentIndex < resIndex) {
                    resIndex = currentIndex;
                }
            }
        }

        return resIndex;
    }
}
