import java.util.*;

class Solution {
    class Pair implements Comparable<Pair> {
        long sum;
        int leftIdx;
        public Pair(long sum, int leftIdx) {
            this.sum = sum;
            this.leftIdx = leftIdx;
        }
        @Override
        public int compareTo(Pair other) {
            if (this.sum != other.sum) return Long.compare(this.sum, other.sum);
            return Integer.compare(this.leftIdx, other.leftIdx);
        }
    }

    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        if (isNonDecreasing(nums)) return 0;

        long[] arr = new long[n];
        for (int i = 0; i < n; i++) arr[i] = nums[i];

        int[] prev = new int[n];
        int[] next = new int[n];
        PriorityQueue<Pair> pq = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            prev[i] = i - 1;
            next[i] = i + 1;
            if (i < n - 1) pq.add(new Pair(arr[i] + arr[i+1], i));
        }
        next[n-1] = -1;

        int ops = 0;
        boolean[] removed = new boolean[n];

        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            int i = p.leftIdx;
            int j = next[i];

            // Validate the pair is still valid
            if (removed[i] || j == -1 || removed[j] || (arr[i] + arr[j] != p.sum)) continue;

            // Perform merge
            arr[i] += arr[j];
            removed[j] = true;
            ops++;

            // Update neighbors
            next[i] = next[j];
            if (next[j] != -1) prev[next[j]] = i;

            // Check if condition is met
            if (checkNonDecreasing(arr, removed, next)) return ops;

            // Add newly adjacent pairs to heap
            if (prev[i] != -1) pq.add(new Pair(arr[prev[i]] + arr[i], prev[i]));
            if (next[i] != -1) pq.add(new Pair(arr[i] + arr[next[i]], i));
        }

        return ops;
    }

    private boolean isNonDecreasing(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i+1]) return false;
        }
        return true;
    }

    private boolean checkNonDecreasing(long[] arr, boolean[] removed, int[] next) {
        int curr = 0;
        while (curr < arr.length && removed[curr]) curr++;
        if (curr >= arr.length) return true;
        
        int forward = next[curr];
        while (forward != -1) {
            if (arr[curr] > arr[forward]) return false;
            curr = forward;
            forward = next[curr];
        }
        return true;
    }
}
