import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        
        for (char c : s.toCharArray()) {
            // If it's an opening bracket, push it
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } 
            // If it's a closing bracket
            else {
                // Stack can't be empty if we have a closing bracket
                if (stack.isEmpty()) return false;
                
                char top = stack.pop();
                // Check if the popped opening bracket matches the current closing one
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
            }
        }
        
        // If the stack is empty, all brackets were matched correctly
        return stack.isEmpty();
    }
}
