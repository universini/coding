#include <limits.h>
#include <stdio.h>

int find_repeat_1(int a[], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        return (a[i]);
      }
    }
  }

  return (-1);
}

int find_repeat_2(int arr[], int size) {
  /*
    It initializes a hash_map array with zeros,
    which can accommodate elements up to a certain
    maximum value (in this example, 100000).
    The hash_map array is used to keep track of
    the count of each element encountered.
  */
  int hash_map[65535] = {0}; // Initialize the hash_map array with 0
  int i;

  for (i = 0; i < size; i++) {
    hash_map[arr[i]]++; // Increment the hash_map of the current element

    // Check if the current element has been repeated
    if (hash_map[arr[i]] > 1) {
      return arr[i]; // Return the first repeating number
    }
  }

  return -1; // If no repeating number is found
}

int main() {
  int arr[] = {2, 5, 6, 2, 8, 1, 9, 10, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("The first repeating number is: %d\n", find_repeat_1(arr, size));

  int repeared_num = find_repeat_2(arr, size);

  if (repeared_num != -1) {
    printf("The first repeating number is: %d\n", repeared_num);
  } else {
    printf("No repeating number found.\n");
  }

  return 0;
}
