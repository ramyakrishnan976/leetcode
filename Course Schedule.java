import java.util.*;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 1. Initialize the adjacency list and the in-degree array
        List<List<Integer>> adj = new ArrayList<>();
        int[] inDegree = new int[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        
        // 2. Build the dependency graph
        for (int[] pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adj.get(prereq).add(course); // prereq -> course
            inDegree[course]++;          // course depends on prereq
        }
        
        // 3. Add all courses with 0 in-degree (no prerequisites) to the queue
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }
        
        // 4. Process nodes in the queue
        int count = 0; // Tracks the number of courses we can successfully take
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            count++;
            
            // Reduce the in-degree of all neighbor courses depending on 'curr'
            for (int nextCourse : adj.get(curr)) {
                inDegree[nextCourse]--;
                // If all prerequisites for nextCourse are cleared, add it to queue
                if (inDegree[nextCourse] == 0) {
                    queue.offer(nextCourse);
                }
            }
        }
        
        // 5. If we were able to take all courses, no cycle exists
        return count == numCourses;
    }
}
