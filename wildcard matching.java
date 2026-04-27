class Solution {
    public boolean isMatch(String s, String p) {
        int sIdx = 0, pIdx = 0, lastWildcardIdx = -1, sNextIdx = -1;
        int sLen = s.length(), pLen = p.length();

        while (sIdx < sLen) {
            // Case 1: Characters match or pattern has '?'
            if (pIdx < pLen && (p.charAt(pIdx) == '?' || p.charAt(pIdx) == s.charAt(sIdx))) {
                sIdx++;
                pIdx++;
            } 
            // Case 2: Pattern has '*'
            else if (pIdx < pLen && p.charAt(pIdx) == '*') {
                lastWildcardIdx = pIdx;
                sNextIdx = sIdx;
                pIdx++; // Try matching empty sequence first
            } 
            // Case 3: No match, but we saw a '*' earlier (Backtrack)
            else if (lastWildcardIdx != -1) {
                pIdx = lastWildcardIdx + 1;
                sNextIdx++;
                sIdx = sNextIdx;
            } 
            // Case 4: No match and no '*' to backtrack to
            else {
                return false;
            }
        }

        // Check for remaining '*' in pattern
        while (pIdx < pLen && p.charAt(pIdx) == '*') {
            pIdx++;
        }

        return pIdx == pLen;
    }
}
