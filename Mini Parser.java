import java.util.*;

class Solution {
    public NestedInteger deserialize(String s) {
        // Handle the case where the input is just a single integer
        if (!s.startsWith("[")) {
            return new NestedInteger(Integer.parseInt(s));
        }

        Stack<NestedInteger> stack = new Stack<>();
        NestedInteger curr = null;
        int l = 0; // Left pointer for substring parsing

        for (int r = 0; r < s.length(); r++) {
            char ch = s.charAt(r);

            if (ch == '[') {
                if (curr != null) {
                    stack.push(curr);
                }
                curr = new NestedInteger();
                l = r + 1;
            } else if (ch == ']' || ch == ',') {
                // If there's a number before this delimiter, add it to current list
                if (r > l) {
                    curr.add(new NestedInteger(Integer.parseInt(s.substring(l, r))));
                }
                l = r + 1;
                
                // If it's a closing bracket and the stack isn't empty, 
                // pop the parent and add the finished current list to it
                if (ch == ']' && !stack.isEmpty()) {
                    NestedInteger parent = stack.pop();
                    parent.add(curr);
                    curr = parent;
                }
            }
        }
        return curr;
    }
}
