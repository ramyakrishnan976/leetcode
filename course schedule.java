import java.util.*;

class Solution {
    public int scheduleCourse(int[][] courses) {
        // Step 1: sort by deadline
        Arrays.sort(courses, (a, b) -> Integer.compare(a[1], b[1]));
        
        // Max heap (store durations)
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        int totalTime = 0;
        
        for (int[] course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            
            totalTime += duration;
            maxHeap.offer(duration);
            
            // If exceeded deadline → remove longest course
            if (totalTime > lastDay) {
                totalTime -= maxHeap.poll();
            }
        }
        
        return maxHeap.size();
    }
}
