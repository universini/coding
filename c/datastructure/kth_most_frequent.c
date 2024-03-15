#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for elements in min heap
typedef struct {
    int element;
    int frequency;
} HeapNode;

// Define structure for min heap
typedef struct {
    HeapNode* array;
    int capacity;
    int size;
} MinHeap;

// Function to initialize a new min heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    return minHeap;
}

// Function to swap two heap nodes
void swapHeapNodes(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain min heap property
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left].frequency < minHeap->array[smallest].frequency) {
        smallest = left;
    }

    if (right < minHeap->size && minHeap->array[right].frequency < minHeap->array[smallest].frequency) {
        smallest = right;
    }

    if (smallest != idx) {
        swapHeapNodes(&minHeap->array[idx], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Function to build min heap
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        minHeapify(minHeap, i);
    }
}

// Function to insert a new element into min heap
void insertMinHeap(MinHeap* minHeap, int element, int frequency) {
    if (minHeap->size == minHeap->capacity) {
        if (frequency > minHeap->array[0].frequency) {
            minHeap->array[0].element = element;
            minHeap->array[0].frequency = frequency;
            minHeapify(minHeap, 0);
        }
        return;
    }
    minHeap->array[minHeap->size].element = element;
    minHeap->array[minHeap->size].frequency = frequency;
    minHeap->size++;
    buildMinHeap(minHeap);
}

// Function to find the k most frequent elements in the array
void kMostFrequent(int arr[], int n, int k) {
    // Create a hash map to store frequency of elements
    int maxElement = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    int* freqMap = (int*)calloc(maxElement + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    // Create a min heap
    MinHeap* minHeap = createMinHeap(k);

    // Insert elements with highest frequency into min heap
    for (int i = 0; i <= maxElement; i++) {
        if (freqMap[i] > 0) {
            insertMinHeap(minHeap, i, freqMap[i]);
        }
    }

    // Print the k most frequent elements
    printf("%d most frequent elements: ", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", minHeap->array[i].element);
    }
    printf("\n");

    // Free memory
    free(freqMap);
    free(minHeap->array);
    free(minHeap);
}

int main() {
    int arr[] = {1, 1, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    kMostFrequent(arr, n, k);

    return 0;
}
