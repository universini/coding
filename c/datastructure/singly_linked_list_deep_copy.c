#include <stdio.h>
#include <stdlib.h>

// Definition for a linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* random;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}

// Function to deep copy a linked list with random pointers
struct Node* deepCopy(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    // Create a mapping between original nodes and their corresponding new nodes
    struct Node* original = head;
    struct Node* copy = NULL;
    struct Node* copiedHead = NULL;
    struct Node* copiedTail = NULL;
    while (original != NULL) {
        copy = createNode(original->data);
        if (copiedHead == NULL) {
            copiedHead = copy;
        } else {
            copiedTail->next = copy;
        }
        copiedTail = copy;
        original = original->next;
    }

    // Update random pointers in the copied list based on the mapping
    original = head;
    copy = copiedHead;
    while (original != NULL) {
        if (original->random != NULL) {
            // Find the corresponding node in the copied list
            struct Node* temp = head;
            struct Node* copiedRandom = copiedHead;
            while (temp != original->random) {
                temp = temp->next;
                copiedRandom = copiedRandom->next;
            }
            copy->random = copiedRandom;
        }
        original = original->next;
        copy = copy->next;
    }

    return copiedHead;
}

// Function to print the linked list with random pointers
void printList(struct Node* head) {
    while (head != NULL) {
        printf("Node: %d, Random: %d\n", head->data, (head->random != NULL) ? head->random->data : -1);
        head = head->next;
    }
}

int main() {
    // Create the original linked list with random pointers
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Set random pointers
    head->random = head->next->next; // Random pointer of node 1 points to node 3
    head->next->random = head->next->next->next->next; // Random pointer of node 2 points to node 5
    head->next->next->random = head; // Random pointer of node 3 points to node 1
    head->next->next->next->random = head->next; // Random pointer of node 4 points to node 2
    head->next->next->next->next->random = NULL; // Random pointer of node 5 points to NULL

    // Print original list with random pointers
    printf("Original list with random pointers:\n");
    printList(head);

    // Deep copy the linked list
    struct Node* copiedHead = deepCopy(head);

    // Print copied list with random pointers
    printf("\nCopied list with random pointers:\n");
    printList(copiedHead);

    // Free memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    while (copiedHead != NULL) {
        temp = copiedHead;
        copiedHead = copiedHead->next;
        free(temp);
    }

    return 0;
}
