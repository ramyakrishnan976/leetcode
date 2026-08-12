#include <stdlib.h>
#include <string.h>

// Definition for a Node given by the platform environment
/*
struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};
*/

// Hash map/Array to keep track of visited/cloned nodes. 
// Constraints state Node.val is between 1 and 100.
struct Node* visited[101];

struct Node* cloneHelper(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }

    // If the node is already cloned, return the cloned instance
    if (visited[node->val] != NULL) {
        return visited[node->val];
    }

    // Instantiate a new node clone
    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));
    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    
    // Allocate memory for the neighbor pointer array
    if (clone->numNeighbors > 0) {
        clone->neighbors = (struct Node**)malloc(clone->numNeighbors * sizeof(struct Node*));
    } else {
        clone->neighbors = NULL;
    }

    // Map the original node val to its clone immediately to handle cycles
    visited[node->val] = clone;

    // Recursively clone all neighbors
    for (int i = 0; i < node->numNeighbors; i++) {
        clone->neighbors[i] = cloneHelper(node->neighbors[i]);
    }

    return clone;
}

struct Node* cloneGraph(struct Node* node) {
    // Reset global tracking array for each independent test run
    memset(visited, 0, sizeof(visited));
    return cloneHelper(node);
}
