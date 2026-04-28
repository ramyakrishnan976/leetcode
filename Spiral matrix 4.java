/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        // Initialize matrix with -1
        int[][] res = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = -1;
            }
        }

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        ListNode curr = head;

        while (curr != null) {
            // 1. Right: move across the top boundary
            for (int j = left; j <= right && curr != null; j++) {
                res[top][j] = curr.val;
                curr = curr.next;
            }
            top++;

            // 2. Down: move down the right boundary
            for (int i = top; i <= bottom && curr != null; i++) {
                res[i][right] = curr.val;
                curr = curr.next;
            }
            right--;

            // 3. Left: move across the bottom boundary
            for (int j = right; j >= left && curr != null; j--) {
                res[bottom][j] = curr.val;
                curr = curr.next;
            }
            bottom--;

            // 4. Up: move up the left boundary
            for (int i = bottom; i >= top && curr != null; i--) {
                res[i][left] = curr.val;
                curr = curr.next;
            }
            left++;
        }

        return res;
    }
}
