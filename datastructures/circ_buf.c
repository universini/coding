#include <stdio.h>
#include <memory.h>

struct queue {
  unsigned int tail;      // current tail
  unsigned int head;      // current head
  unsigned int size;      // current number of items
  unsigned int capacity;  // Capacity of queue
  int* data;              // Pointer to array of data
};

typedef struct queue queue_t;

queue_t* create_queue(unsigned int _capacity) {
  queue_t* myQueue = (queue_t*)malloc(sizeof(queue_t));

  if (myQueue == NULL) {
    return NULL;
  } else {
    myQueue->tail = -1;
    myQueue->head = 0;
    myQueue->size = 0;
    myQueue->capacity = _capacity;
    myQueue->data = (int*)malloc(_capacity * sizeof(int));

    return myQueue;
  }
}

int queue_empty(queue_t* q) {
  if (q == NULL) {
    return -1;
  } else if (q->size == 0) {
    return 1;
  } else {
    return 0;
  }
}

int queue_full(queue_t* q) {
  if (q == NULL) {
    return -1;
  } else if (q->size == q->capacity) {
    return 1;
  } else {
    return 0;
  }
}

int queue_enqueue(queue_t* q, int item) {
  if (q == NULL) {
    return -1;
  } else if (queue_full(q) == 1) {
    return 0;
  } else {
    q->tail = (q->tail + 1) % q->capacity;
    q->data[q->tail] = item;
    q->size++;
    return 1;
  }
}

int queue_dequeue(queue_t* q) {
  if (q == NULL) {
    return -1;

  } else if (queue_empty(q) == 1) {
    return 0;
  } else {
    int item = q->data[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;

    return item;
  }
}

unsigned int queue_size(queue_t* q) {
  if (q == NULL) {
    return -1;
  } else {
    return q->size;
  }
}

void free_queue(queue_t* q) {
  free(q->data);
  free(q);
}
