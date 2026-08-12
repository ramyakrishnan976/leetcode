#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Trie Node Definition
typedef struct TrieNode {
    struct TrieNode* children[26];
    char* word; // Stores the complete word if this node is the end of a word
} TrieNode;

// Helper to create a new Trie Node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->word = NULL;
    return node;
}

// Insert a word into the Trie
void insertWord(TrieNode* root, char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int idx = word[i] - 'a';
        if (!curr->children[idx]) {
            curr->children[idx] = createNode();
        }
        curr = curr->children[idx];
    }
    curr->word = word; // Store the exact string pointer at the leaf
}

// Backtracking DFS function
void backtrack(char** board, int m, int n, int r, int c, TrieNode* curr, char** res, int* resSize) {
    char ch = board[r][c];
    int idx = ch - 'a';
    
    // If character does not match any prefix path in our Trie
    if (!curr->children[idx]) {
        return;
    }
    
    curr = curr->children[idx];
    
    // If we matched a complete word, add it to our results array
    if (curr->word != NULL) {
        res[(*resSize)++] = curr->word;
        curr->word = NULL; // De-duplicate: Ensure we don't pick up the same word twice
    }
    
    // Mark the current cell as visited using a placeholder symbol
    board[r][c] = '#';
    
    // Direction vectors for 4-way exploration (Up, Down, Left, Right)
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        // Bounds checking and checking for visited cells
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] != '#') {
            backtrack(board, m, n, nr, nc, curr, res, resSize);
        }
    }
    
    // Revert cell back to its original state (Backtrack)
    board[r][c] = ch;
}

// Main execution function required by LeetCode
char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    TrieNode* root = createNode();
    for (int i = 0; i < wordsSize; i++) {
        insertWord(root, words[i]);
    }
    
    int m = boardSize;
    int n = boardColSize[0];
    
    // Allocate space for results (at most wordsSize matches can happen)
    char** res = (char**)malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    
    // Launch DFS from every single cell on the board
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            backtrack(board, m, n, i, j, root, res, returnSize);
        }
    }
    
    return res;
}
