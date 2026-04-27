import java.util.*;

class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        
        // Step 1: Combine projects
        int[][] projects = new int[n][2];
        for (int i = 0; i < n; i++) {
            projects[i][0] = capital[i];
            projects[i][1] = profits[i];
        }
        
        // Step 2: Sort by capital
        Arrays.sort(projects, (a, b) -> Integer.compare(a[0], b[0]));
        
        // Step 3: Max heap for profits
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        
        int i = 0;
        
        // Step 4: Pick up to k projects
        for (int j = 0; j < k; j++) {
            
            // Add all feasible projects
            while (i < n && projects[i][0] <= w) {
                maxHeap.offer(projects[i][1]);
                i++;
            }
            
            // If no projects available → stop
            if (maxHeap.isEmpty()) break;
            
            // Pick the most profitable
            w += maxHeap.poll();
        }
        
        return w;
    }
}
