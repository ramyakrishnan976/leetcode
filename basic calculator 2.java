import java.util.*;

class Solution {
    public int calculate(String s) {
        if (s == null || s.isEmpty()) return 0;
        
        Stack<Integer> stack = new Stack<>();
        int currentNumber = 0;
        char operation = '+'; // Tracks the operation before the current number
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char curr = s.charAt(i);

            if (Character.isDigit(curr)) {
                currentNumber = (currentNumber * 10) + (curr - '0');
            }

            // Process if it's an operator or the last character in the string
            if (!Character.isDigit(curr) && curr != ' ' || i == n - 1) {
                if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '*') {
                    stack.push(stack.pop() * currentNumber);
                } else if (operation == '/') {
                    stack.push(stack.pop() / currentNumber);
                }
                operation = curr;
                currentNumber = 0;
            }
        }

        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }
}
