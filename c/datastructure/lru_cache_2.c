#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
};

// Structure for the LRU cache
struct LRUCache {
    int capacity;
    int size;
    struct Node* head;
    struct Node* tail;
    struct Node** cacheMap;
};

// Function to create a new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the LRU cache
struct LRUCache* createLRUCache(int capacity) {
    struct LRUCache* cache = (struct LRUCache*)malloc(sizeof(struct LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    cache->cacheMap = (struct Node**)malloc(sizeof(struct Node*) * capacity);

    // Initialize cache map with NULL
    for (int i = 0; i < capacity; i++)
        cache->cacheMap[i] = NULL;

    return cache;
}

// Function to delete a node from the cache
void deleteNode(struct LRUCache* cache, struct Node* node) {
    if (node->prev != NULL)
        node->prev->next = node->next;
    else
        cache->head = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;
    else
        cache->tail = node->prev;

    free(node);
    cache->size--;
}

// Function to move a node to the front of the cache
void moveToFront(struct LRUCache* cache, struct Node* node) {
    if (cache->head == node)
        return;

    if (node->prev != NULL)
        node->prev->next = node->next;

    if (node->next != NULL)
        node->next->prev = node->prev;

    if (cache->tail == node)
        cache->tail = node->prev;

    node->next = cache->head;
    node->prev = NULL;

    if (cache->head != NULL)
        cache->head->prev = node;

    cache->head = node;

    if (cache->tail == NULL)
        cache->tail = cache->head;
}

// Function to get value corresponding to a key from the cache
int get(struct LRUCache* cache, int key) {
    int index = key % cache->capacity;
    struct Node* node = cache->cacheMap[index];

    while (node != NULL) {
        if (node->key == key) {
            moveToFront(cache, node);
            return node->value;
        }
        node = node->next;
    }
    return -1;
}

// Function to put key-value pair into the cache
void put(struct LRUCache* cache, int key, int value) {
    int index = key % cache->capacity;
    struct Node* node = cache->cacheMap[index];

    while (node != NULL) {
        if (node->key == key) {
            node->value = value;
            moveToFront(cache, node);
            return;
        }
        node = node->next;
    }

    struct Node* newNode = createNode(key, value);
    newNode->next = cache->head;
    if (cache->head != NULL)
        cache->head->prev = newNode;
    cache->head = newNode;

    if (cache->tail == NULL)
        cache->tail = cache->head;

    cache->cacheMap[index] = newNode;

    if (cache->size == cache->capacity) {
        deleteNode(cache, cache->tail);
        cache->cacheMap[index] = newNode;
    } else {
        cache->size++;
    }
}

// Function to print the cache contents
void printCache(struct LRUCache* cache) {
    struct Node* temp = cache->head;
    while (temp != NULL) {
        printf("(%d, %d) ", temp->key, temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct LRUCache* cache = createLRUCache(3);
    put(cache, 1, 1);
    put(cache, 2, 2);
    put(cache, 3, 3);
    printCache(cache); // Output: (3, 3) (2, 2) (1, 1)

    get(cache, 2); // Output: 2
    printCache(cache); // Output: (2, 2) (3, 3) (1, 1)

    put(cache, 4, 4);
    printCache(cache); // Output: (4, 4) (2, 2) (3, 3)

    get(cache, 1); // Output: -1 (key not found)
    printCache(cache); // Output: (4, 4) (2, 2) (3, 3)

    return 0;
}
