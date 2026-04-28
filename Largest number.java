import java.util.*;

class Solution {
    public String largestNumber(int[] nums) {
        // 1. Convert integers to strings
        String[] strs = new String[nums.length];
        for (int i = 0; i < nums.length; i++) {
            strs[i] = String.valueOf(nums[i]);
        }

        // 2. Custom sort: compare (b + a) to (a + b)
        Arrays.sort(strs, (a, b) -> (b + a).compareTo(a + b));

        // 3. Handle edge case: if the largest number is "0"
        if (strs[0].equals("0")) return "0";

        // 4. Build the final result
        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s);
        }

        return sb.toString();
    }
}
