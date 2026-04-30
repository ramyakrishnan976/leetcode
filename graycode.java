import java.util.*;

class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<>();
        // Base case: 0-bit gray code is just 0
        result.add(0);

        for (int i = 0; i < n; i++) {
            int size = result.size();
            int addValue = 1 << i; // This is 2^i
            
            // Iterate backwards through the current list to create the mirror
            for (int j = size - 1; j >= 0; j--) {
                result.add(result.get(j) + addValue);
            }
        }
        
        return result;
    }
}
