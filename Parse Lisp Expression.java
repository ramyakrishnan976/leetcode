import java.util.*;

class Solution {
    public int evaluate(String expression) {
        // Use a List of Maps to represent scoped symbol tables
        return eval(expression, new ArrayList<>());
    }

    private int eval(String exp, List<Map<String, Integer>> scope) {
        // Base case: If it's an integer (can be negative)
        if (exp.charAt(0) != '(') {
            if (Character.isDigit(exp.charAt(0)) || exp.charAt(0) == '-') {
                return Integer.parseInt(exp);
            }
            // Variable lookup: Search scopes from innermost to outermost
            for (int i = scope.size() - 1; i >= 0; i--) {
                if (scope.get(i).containsKey(exp)) {
                    return scope.get(i).get(exp);
                }
            }
        }

        // Identify the operation type and extract the content within parentheses
        // "(let " is 5 chars, "(add " is 5 chars, "(mult " is 6 chars
        String type = exp.substring(1, exp.indexOf(' '));
        String inner = exp.substring(type.length() + 2, exp.length() - 1);
        List<String> tokens = parse(inner);

        if (type.equals("add")) {
            return eval(tokens.get(0), scope) + eval(tokens.get(1), scope);
        } else if (type.equals("mult")) {
            return eval(tokens.get(0), scope) * eval(tokens.get(1), scope);
        } else { // "let" expression
            // Create a new scope level for this 'let' block
            Map<String, Integer> currentScope = new HashMap<>();
            scope.add(currentScope);
            
            // Pairs of (variable, expression)
            for (int i = 0; i < tokens.size() - 1; i += 2) {
                currentScope.put(tokens.get(i), eval(tokens.get(i + 1), scope));
            }
            
            // The last token is the expression to evaluate using current scope
            int result = eval(tokens.get(tokens.size() - 1), scope);
            
            // Pop the scope level before returning (Backtracking)
            scope.remove(scope.size() - 1);
            return result;
        }
    }

    /**
     * Splits a string into tokens based on spaces, but respects nested parentheses.
     * Prevents empty tokens to avoid StringIndexOutOfBoundsException.
     */
    private List<String> parse(String s) {
        List<String> res = new ArrayList<>();
        int balance = 0;
        StringBuilder sb = new StringBuilder();
        
        for (char c : s.toCharArray()) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            
            if (c == ' ' && balance == 0) {
                if (sb.length() > 0) {
                    res.add(sb.toString());
                    sb.setLength(0);
                }
            } else {
                sb.append(c);
            }
        }
        if (sb.length() > 0) res.add(sb.toString());
        return res;
    }
}
