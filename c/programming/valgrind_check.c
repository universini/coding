#include <stdlib.h>

int main() {
    // Allocate memory without freeing it
    int *ptr = malloc(10 * sizeof(int));

    // Access memory beyond allocated size
    ptr[10] = 5;
    // free(ptr);
    // Return without freeing allocated memory
    return 0;
}
