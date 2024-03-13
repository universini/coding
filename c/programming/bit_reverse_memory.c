#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void reverse_memory_bits(void *memory, size_t size) {
    unsigned char *ptr = (unsigned char *)memory;
    size_t total_bits = size * 8; // Calculate total number of bits
    size_t end = total_bits - 1; // Index of the last bit
    size_t start = 0; // Index of the first bit
    
    while (start < end) {
        // printf("data0: %u data1: %u\n", ptr[start], ptr[end]);
        
        // Extract bit values from the start and end positions
        uint8_t start_bit = (ptr[start / 8] >> (start % 8)) & 1;
        uint8_t end_bit = (ptr[end / 8] >> (end % 8)) & 1;

        // printf("start: %lu end: %lu\n", start/8, end/8);
        // printf("start: %lu end: %lu\n", start%8, end%8);

        // Swap the bits
        if (start_bit != end_bit) {
            ptr[start / 8] ^= (1 << (start % 8));
            ptr[end / 8] ^= (1 << (end % 8));
        }
        
        // Move to the next bit positions
        start++;
        end--;
    }
}

void reverseBits(char* block, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        char byte = block[i];
        char reversedByte = 0;

        for (int j = 0; j < 8; ++j) {
            reversedByte |= ((byte >> j) & 1) << (7 - j);
        }

        block[i] = reversedByte;
    }
}

int main() {
    size_t size = 3; // Example size of memory block in bytes
    unsigned char *memory = (unsigned char *)malloc(size);
    if (memory == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Fill the memory block with example data
    memory[0] = 0x80; // 1000 0000
    memory[1] = 0x00; // 0000 0000
    memory[2] = 0x01;
    // memory[3] = 0x78;

    printf("Original memory content:\n");
    for (size_t i = 0; i < size; i++) {
        printf("0x%X ", memory[i]);
    }
    printf("\n");

    // Reverse the bits of the entire memory block
    reverseBits(memory, size);

    printf("Memory content after bit reversal:\n");
    for (size_t i = 0; i < size; i++) {
        printf("0x%X ", memory[i]);
    }
    printf("\n");

    free(memory);
    return 0;
}
