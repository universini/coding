#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
    int* array;
    int capacity;
    int size;
};

struct MaxHeap* createMaxHeap(int capacity) {
    struct MaxHeap* maxHeap = (struct MaxHeap*)malloc(sizeof(struct MaxHeap));
    maxHeap->capacity = capacity;
    maxHeap->size = 0;
    maxHeap->array = (int*)malloc(capacity * sizeof(int));
    return maxHeap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MaxHeap* maxHeap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < maxHeap->size && maxHeap->array[left] > maxHeap->array[largest])
        largest = left;

    if (right < maxHeap->size && maxHeap->array[right] > maxHeap->array[largest])
        largest = right;

    if (largest != idx) {
        swap(&maxHeap->array[idx], &maxHeap->array[largest]);
        heapify(maxHeap, largest);
    }
}

void insert(struct MaxHeap* maxHeap, int key) {
    if (maxHeap->size == maxHeap->capacity) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    maxHeap->size++;
    int i = maxHeap->size - 1;
    maxHeap->array[i] = key;

    while (i != 0 && maxHeap->array[(i - 1) / 2] < maxHeap->array[i]) {
        swap(&maxHeap->array[i], &maxHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMax(struct MaxHeap* maxHeap) {
    if (maxHeap->size <= 0)
        return -1; // Heap is empty

    if (maxHeap->size == 1) {
        maxHeap->size--;
        return maxHeap->array[0];
    }

    int root = maxHeap->array[0];
    maxHeap->array[0] = maxHeap->array[maxHeap->size - 1];
    maxHeap->size--;
    heapify(maxHeap, 0);

    return root;
}

int main() {
    struct MaxHeap* maxHeap = createMaxHeap(10);

    insert(maxHeap, 8);
    insert(maxHeap, 5);
    insert(maxHeap, 10);
    insert(maxHeap, 3);
    insert(maxHeap, 2);

    printf("Max Heap: ");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->array[i]);
    }
    printf("\n");

    int max = extractMax(maxHeap);
    printf("Extracted Max: %d\n", max);

    printf("Max Heap after extraction: ");
    for (int i = 0; i < maxHeap->size; i++) {
        printf("%d ", maxHeap->array[i]);
    }
    printf("\n");

    free(maxHeap->array);
    free(maxHeap);

    return 0;
}
