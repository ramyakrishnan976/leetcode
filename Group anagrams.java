import java.util.*;

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // Map: Key = Sorted String, Value = List of original anagrams
        Map<String, List<String>> map = new HashMap<>();
        
        for (String s : strs) {
            // Convert string to char array to sort it
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);
            
            // If the key doesn't exist, create a new list
            if (!map.containsKey(sorted)) {
                map.put(sorted, new ArrayList<>());
            }
            
            // Add the original string to the corresponding list
            map.get(sorted).add(s);
        }
        
        // Return all the grouped lists
        return new ArrayList<>(map.values());
    }
}
