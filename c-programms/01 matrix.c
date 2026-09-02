import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        
        int[][] dist = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        
        // Initialize the distance matrix and queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    queue.offer(new int[]{i, j}); // Multi-source: Add all 0s to the queue
                } else {
                    dist[i][j] = Integer.MAX_VALUE; // Mark unvisited cells with infinity
                }
            }
        }
        
        // Direction vectors for traveling up, down, left, and right
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Process BFS layer-by-layer
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int currRow = curr[0];
            int currCol = curr[1];
            
            for (int[] dir : directions) {
                int nr = currRow + dir[0];
                int nc = currCol + dir[1];
                
                // Boundary check and condition to see if we found a shorter path
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (dist[nr][nc] > dist[currRow][currCol] + 1) {
                        dist[nr][nc] = dist[currRow][currCol] + 1;
                        queue.offer(new int[]{nr, nc}); // Enqueue cell for further expansion
                    }
                }
            }
        }
        
        return dist;
    }
}
