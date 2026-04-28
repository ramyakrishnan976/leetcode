import java.util.*;

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int i = 0;
        
        while (i < words.length) {
            int lineLength = words[i].length();
            int last = i + 1;
            
            // Step 1: Determine how many words fit in the current line
            while (last < words.length) {
                if (lineLength + 1 + words[last].length() > maxWidth) break;
                lineLength += 1 + words[last].length();
                last++;
            }
            
            StringBuilder sb = new StringBuilder();
            int diff = last - i - 1; // number of gaps between words
            
            // Step 2: Handle the last line or lines with only one word (Left Justified)
            if (last == words.length || diff == 0) {
                for (int j = i; j < last; j++) {
                    sb.append(words[j]);
                    if (j < last - 1) sb.append(" ");
                }
                while (sb.length() < maxWidth) sb.append(" ");
            } 
            // Step 3: Handle fully justified lines
            else {
                int spaces = (maxWidth - lineLength) / diff;
                int extra = (maxWidth - lineLength) % diff;
                
                for (int j = i; j < last; j++) {
                    sb.append(words[j]);
                    if (j < last - 1) {
                        // Base 1 space + calculated distributed spaces
                        for (int s = 0; s <= (spaces + (j - i < extra ? 1 : 0)); s++) {
                            sb.append(" ");
                        }
                    }
                }
            }
            
            res.add(sb.toString());
            i = last;
        }
        
        return res;
    }
}
