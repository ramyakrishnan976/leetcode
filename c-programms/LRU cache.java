#include <stdlib.h>

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node *head, *tail;
    Node **hash; // Array-based hash map for keys up to 10000
} LRUCache;

// Helper to create a new node
Node* createNode(int k, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = k; node->value = v;
    node->prev = node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = 0;
    obj->hash = (Node**)calloc(10001, sizeof(Node*));
    obj->head = createNode(0, 0); // Dummy Head
    obj->tail = createNode(0, 0); // Dummy Tail
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    return obj;
}

void detach(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void attachToHead(LRUCache* obj, Node* node) {
    node->next = obj->head->next;
    node->next->prev = node;
    obj->head->next = node;
    node->prev = obj->head;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (obj->hash[key] == NULL) return -1;
    Node* node = obj->hash[key];
    detach(node);
    attachToHead(obj, node);
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if (obj->hash[key] != NULL) {
        Node* node = obj->hash[key];
        node->value = value;
        detach(node);
        attachToHead(obj, node);
    } else {
        if (obj->size == obj->capacity) {
            Node* lru = obj->tail->prev;
            obj->hash[lru->key] = NULL;
            detach(lru);
            free(lru);
            obj->size--;
        }
        Node* newNode = createNode(key, value);
        obj->hash[key] = newNode;
        attachToHead(obj, newNode);
        obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(obj->hash);
    free(obj);
}
