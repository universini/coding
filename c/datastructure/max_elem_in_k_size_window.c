#include <stdio.h>
#include <stdlib.h>

// Structure for a deque node
struct DequeNode {
    int data;
    struct DequeNode* next;
    struct DequeNode* prev;
};

// Structure for a deque
struct Deque {
    struct DequeNode* front;
    struct DequeNode* rear;
};

// Function to create a new node
struct DequeNode* createNode(int data) {
    struct DequeNode* newNode = (struct DequeNode*)malloc(sizeof(struct DequeNode));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to create an empty deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    deque->front = deque->rear = NULL;
    return deque;
}

// Function to insert a node at the front of the deque
void insertFront(struct Deque* deque, int data) {
    struct DequeNode* newNode = createNode(data);

    if (deque->front == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// Function to insert a node at the rear of the deque
void insertRear(struct Deque* deque, int data) {
    struct DequeNode* newNode = createNode(data);

    if (deque->rear == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// Function to remove a node from the front of the deque
void removeFront(struct Deque* deque) {
    if (deque->front == NULL) {
        return;
    }

    struct DequeNode* temp = deque->front;
    deque->front = deque->front->next;

    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }

    free(temp);
}

// Function to get the front element of the deque
int getFront(struct Deque* deque) {
    return (deque->front != NULL) ? deque->front->data : -1;
}

// Function to get the rear element of the deque
int getRear(struct Deque* deque) {
    return (deque->rear != NULL) ? deque->rear->data : -1;
}

// Function to find the maximum element in a window of size k in an array
void maxInWindow(const int* arr, int n, int k) {
    struct Deque* deque = createDeque();

    // Process the first window separately
    for (int i = 0; i < k; ++i) {
        // Remove elements smaller than the current element from the back
        while (deque->rear != NULL && arr[i] >= arr[getRear(deque)]) {
            removeFront(deque);
        }
        insertRear(deque, i);
    }

    // Process the remaining windows
    for (int i = k; i < n; ++i) {
        // The front of the deque contains the maximum element in the current window
        printf("%d ", arr[getFront(deque)]);

        // Remove elements outside the current window
        while (deque->front != NULL && getFront(deque) <= i - k) {
            removeFront(deque);
        }

        // Remove elements smaller than the current element from the back
        while (deque->rear != NULL && arr[i] >= arr[getRear(deque)]) {
            removeFront(deque);
        }

        // Add the current index to the deque
        insertRear(deque, i);
    }

    // Print the maximum element of the last window
    printf("%d\n", arr[getFront(deque)]);

    // Free the allocated memory
    free(deque);
}

int main() {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    printf("Maximum elements in each window of size %d are: ", k);
    maxInWindow(arr, n, k);

    return 0;
}
