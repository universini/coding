#include <stdlib.h>
#include <stdio.h>

#define ALIGN 64

void *aligned_malloc(int size) {
  void *mem = malloc(size + ALIGN + sizeof(void *));
  void **ptr = (void **)((long)(mem + ALIGN + sizeof(void *)) & ~(ALIGN - 1));
  ptr[-1] = mem;
  return ptr;
}

void aligned_free(void *ptr) { free(((void **)ptr)[-1]); }

int main(void) {
  int *p;

  p = aligned_malloc(0);

  printf("size: %lu content: %d\n", sizeof(p), *p);

  aligned_free(p);

  return (0);
}