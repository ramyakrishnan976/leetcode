#include <stdio.h>
#include <stdbool.h>

bool checkValidString(char* s) {
    int cmin = 0; // Minimum possible open '(' brackets remaining
    int cmax = 0; // Maximum possible open '(' brackets remaining

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            cmin++;
            cmax++;
        } else if (s[i] == ')') {
            cmin--;
            cmax--;
        } else if (s[i] == '*') {
            cmin--; // If '*' acts as ')'
            cmax++; // If '*' acts as '('
        }

        // If maximum possible open brackets drops below 0, there are too many ')'
        if (cmax < 0) {
            return false;
        }

        // Minimum open brackets cannot be negative
        if (cmin < 0) {
            cmin = 0;
        }
    }

    // The string is valid if we can successfully balance all brackets (minimum open is 0)
    return cmin == 0;
}
