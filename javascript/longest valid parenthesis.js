/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    let maxLength = 0;
    let stack = [-1]; // Initialize with -1 to handle base case for length calculation

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            // Push the index of the opening parenthesis
            stack.push(i);
        } else {
            // Pop the last opening parenthesis index
            stack.pop();
            
            if (stack.length === 0) {
                // If stack is empty, this ')' is a mismatch; 
                // push its index as the new base/anchor
                stack.push(i);
            } else {
                // Calculate the length: current index minus the last index in stack
                maxLength = Math.max(maxLength, i - stack[stack.length - 1]);
            }
        }
    }

    return maxLength;
};
