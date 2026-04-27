import java.util.*;

class Solution {
    public String countOfAtoms(String formula) {
        int n = formula.length();
        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new TreeMap<>()); // Use TreeMap to keep keys sorted automatically
        
        int i = 0;
        while (i < n) {
            char c = formula.charAt(i);
            
            if (c == '(') {
                stack.push(new TreeMap<>());
                i++;
            } else if (c == ')') {
                Map<String, Integer> top = stack.pop();
                i++;
                // Read the multiplier after ')'
                int start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) i++;
                int multiplier = (start == i) ? 1 : Integer.parseInt(formula.substring(start, i));
                
                // Multiply and merge into the parent map
                Map<String, Integer> parent = stack.peek();
                for (String atom : top.keySet()) {
                    parent.put(atom, parent.getOrDefault(atom, 0) + top.get(atom) * multiplier);
                }
            } else {
                // Read Atom Name (Uppercase + Lowercase)
                int start = i++;
                while (i < n && Character.isLowerCase(formula.charAt(i))) i++;
                String atom = formula.substring(start, i);
                
                // Read Atom Count
                start = i;
                while (i < n && Character.isDigit(formula.charAt(i))) i++;
                int count = (start == i) ? 1 : Integer.parseInt(formula.substring(start, i));
                
                stack.peek().put(atom, stack.peek().getOrDefault(atom, 0) + count);
            }
        }
        
        // Build final string from the last remaining map
        StringBuilder sb = new StringBuilder();
        Map<String, Integer> finalMap = stack.pop();
        for (String atom : finalMap.keySet()) {
            sb.append(atom);
            int count = finalMap.get(atom);
            if (count > 1) sb.append(count);
        }
        return sb.toString();
    }
}
