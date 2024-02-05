#include <stdio.h>

void insertIntoVector(int vector[], int size, int newNumber, int lowerBound, int upperBound) {
    // Find the position to insert the new number
    int i;
    for (i = 0; i < size; i++) {
        if (vector[i] > lowerBound && vector[i] < upperBound) {
            break;
        }
    }

    // Shift elements to make room for the new number
    for (int j = size - 1; j > i; j--) {
        vector[j] = vector[j - 1];
    }

    // Insert the new number at the appropriate position
    vector[i] = newNumber;
}

int main() {
    int myVector[] = {10, 20, 30, 40, 50};
    int size = sizeof(myVector) / sizeof(myVector[0]);

    int newNumber = 25; // The integer you want to insert
    int lowerBound = 20; // Lower bound of the range
    int upperBound = 30; // Upper bound of the range

    // Call the function to insert the number into the vector
    insertIntoVector(myVector, size, newNumber, lowerBound, upperBound);

    // Print the vector after insertion
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", myVector[i]);
    }

    return 0;
}
