import java.util.*;

public class WordLadder {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Set<String> set = new HashSet<>(wordList);
        if (!set.contains(endWord)) return 0;

        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        int level = 1;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String currentWord = queue.poll();
                char[] wordChars = currentWord.toCharArray();

                for (int j = 0; j < wordChars.length; j++) {
                    char originalChar = wordChars[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (wordChars[j] == c) continue;
                        wordChars[j] = c;
                        String newWord = String.valueOf(wordChars);

                        if (newWord.equals(endWord)) return level + 1;
                        if (set.contains(newWord)) {
                            queue.add(newWord);
                            set.remove(newWord); // Mark as visited
                        }
                    }
                    wordChars[j] = originalChar;
                }
            }
            level++;
        }
        return 0;
    }
}
