#include <stdio.h>

// Function to move all zeros to the end of the array
void moveZerosToEnd(int arr[], int size) {
    int nonZeroIndex = 0;

    // Traverse the array
    for (int i = 0; i < size; i++) {
        // If the current element is non-zero
        if (arr[i] != 0) {
            // Swap the non-zero element with the first zero encountered
            int temp = arr[i];
            arr[i] = arr[nonZeroIndex];
            arr[nonZeroIndex] = temp;

            // Move the nonZeroIndex to the next position
            nonZeroIndex++;
        }
    }
}

// Function which pushes all zeros to end of an array. 
void pushZerosToEnd(int arr[], int n) 
{ 
    int count = {0};  // Count of non-zero elements 
  
    // Traverse the array. If element encountered is non- 
    // zero, then replace the element at index 'count'  
    // with this element 
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            arr[count++] = arr[i]; // here count is  
                                   // incremented 
  
    // Now all non-zero elements have been shifted to  
    // front and  'count' is set as index of first 0.  
    // Make all elements 0 from count to end. 
    while (count < n) 
        arr[count++] = 0; 
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {1, 0, 2, 0, 3, 0, 4, 5, 0, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, size);

    // Move zeros to the end
    pushZerosToEnd(arr, size);

    printf("Array after moving zeros to the end: ");
    printArray(arr, size);

    return 0;
}
