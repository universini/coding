#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Function to initialize a stack
void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push a node onto the stack
void push(struct Stack* stack, struct Node* node) {
    node->next = stack->top;
    stack->top = node;
}

// Function to pop a node from the stack
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }

    struct Node* popped = stack->top;
    stack->top = stack->top->next;
    return popped;
}

// Function to reverse the linked list using a stack
struct Node* reverseLinkedList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct Stack stack;
    initializeStack(&stack);

    struct Node* current = head;

    // Step 1: Traverse the original linked list and push nodes onto the stack
    while (current != NULL) {
        push(&stack, current);
        current = current->next;
    }

    // Step 2: Pop elements from the stack and update next pointers
    struct Node* newHead = pop(&stack);
    current = newHead;

    while (!isEmpty(&stack)) {
        struct Node* node = pop(&stack);
        current->next = node;
        current = node;
    }

    // Step 3: Update the next pointer of the last node
    current->next = NULL;

    return newHead;
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to free the memory allocated for the linked list
void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// Example usage
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original linked list:\n");
    printLinkedList(head);

    // Reversing the linked list using a stack
    struct Node* newHead = reverseLinkedList(head);

    printf("Reversed linked list:\n");
    printLinkedList(newHead);

    // Freeing the allocated memory
    freeLinkedList(newHead);

    return 0;
}
