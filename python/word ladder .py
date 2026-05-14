from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        word_set = set(wordList)
        
        # Step 1: Target validation
        if endWord not in word_set:
            return 0
            
        # Step 2: Queue stores pairs of (current_word, current_step_count)
        queue = deque([(beginWord, 1)])
        word_len = len(beginWord)
        
        # Step 3: Layer-by-layer traversal
        while queue:
            current_word, steps = queue.popleft()
            
            # Step 4: Mutate every character position
            for i in range(word_len):
                original_char = current_word[i]
                
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == original_char:
                        continue
                        
                    # Form the neighbor variant
                    next_word = current_word[:i] + c + current_word[i+1:]
                    
                    # Step 5: Check matching targets and dictionary presence
                    if next_word == endWord:
                        return steps + 1
                        
                    if next_word in word_set:
                        queue.append((next_word, steps + 1))
                        word_set.remove(next_word) # Visited checkpoint
                        
        return 0
