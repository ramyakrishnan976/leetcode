/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];

    const backtrack = (currentStr, openCount, closeCount) => {
        // Base case: If the string length is 2*n, we've found a valid combination
        if (currentStr.length === n * 2) {
            result.push(currentStr);
            return;
        }

        // Add an opening parenthesis if we haven't reached the limit 'n'
        if (openCount < n) {
            backtrack(currentStr + "(", openCount + 1, closeCount);
        }

        // Add a closing parenthesis if it won't exceed the number of open ones
        if (closeCount < openCount) {
            backtrack(currentStr + ")", openCount, closeCount + 1);
        }
    };

    backtrack("", 0, 0);
    return result;
};
