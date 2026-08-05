import java.util.*;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // 1. Initialize the adjacency list and the in-degree array
        List<List<Integer>> adj = new ArrayList<>();
        int[] inDegree = new int[numCourses];
        
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        
        // 2. Build the dependency graph (prereq -> course)
        for (int[] pair : prerequisites) {
            int course = pair[0];
            int prereq = pair[1];
            adj.get(prereq).add(course);
            inDegree[course]++;
        }
        
        // 3. Add all courses with 0 in-degree (no prerequisites) to the queue
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }
        
        // 4. Process nodes and record the order
        int[] order = new int[numCourses];
        int index = 0; // Tracks position in the order array
        
        while (!queue.isEmpty()) {
            int curr = queue.poll();
            order[index++] = curr; // Append the processed course to our schedule
            
            // Reduce the in-degree of all dependent neighbor courses
            for (int nextCourse : adj.get(curr)) {
                inDegree[nextCourse]--;
                // If all prerequisites are cleared, add it to the queue
                if (inDegree[nextCourse] == 0) {
                    queue.offer(nextCourse);
                }
            }
        }
        
        // 5. If index matches numCourses, we successfully scheduled everything
        // Otherwise, a cycle exists, making it impossible to finish all courses
        return (index == numCourses) ? order : new int[0];
    }
}
