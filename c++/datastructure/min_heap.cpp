#include <stdio.h>
#include <stdlib.h>

struct MinHeap {
    int* array;
    int capacity;
    int size;
};

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->array = (int*)malloc(capacity * sizeof(int));
    return minHeap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left] < minHeap->array[smallest])
        smallest = left;

    if (right < minHeap->size && minHeap->array[right] < minHeap->array[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(&minHeap->array[idx], &minHeap->array[smallest]);
        heapify(minHeap, smallest);
    }
}

void insert(struct MinHeap* minHeap, int key) {
    if (minHeap->size == minHeap->capacity) {
        printf("Heap is full. Cannot insert more elements.\n");
        return;
    }

    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->array[i] = key;

    while (i != 0 && minHeap->array[(i - 1) / 2] > minHeap->array[i]) {
        swap(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extractMin(struct MinHeap* minHeap) {
    if (minHeap->size <= 0)
        return -1; // Heap is empty

    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->array[0];
    }

    int root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    heapify(minHeap, 0);

    return root;
}

int main() {
    struct MinHeap* minHeap = createMinHeap(10);

    insert(minHeap, 8);
    insert(minHeap, 5);
    insert(minHeap, 10);
    insert(minHeap, 3);
    insert(minHeap, 2);

    printf("Min Heap: ");
    for (int i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->array[i]);
    }
    printf("\n");

    int min = extractMin(minHeap);
    printf("Extracted Min: %d\n", min);

    printf("Min Heap after extraction: ");
    for (int i = 0; i < minHeap->size; i++) {
        printf("%d ", minHeap->array[i]);
    }
    printf("\n");

    free(minHeap->array);
    free(minHeap);

    return 0;
}
