#include <iostream>
#include <numeric>
using namespace std;

// Top-down recursive function to count all paths from the cell (m,n)
// to the last cell (N-1,M-1) in a given M x N rectangular grid
int countPaths(int m, int n) {
  // there is only one way to reach the last cell
  // when we're at the last row or the last column
  if (m == M - 1 || n == N - 1) return 1;

  return countPaths(m + 1, n)     // move down
         + countPaths(m, n + 1);  // move right
}

int main(void) {
  int k = countPaths(0, 0);
  printf("Total number of paths are: %d", k);

  return 0;
}
== == == == =
                // Convert lowercase alphabet to uppercase
    for (char ch = 'a'; ch <= 'z'; ch++) cout
    << char(ch ^ ' ');  // prints ABCDEFGHIJKLMNOPQRSTUVWXYZ

// Convert uppercase alphabet to lowercase
for (char ch = 'A'; ch <= 'Z'; ch++)
  cout << char(ch ^ ' ');  // prints abcdefghijklmnopqrstuvwxyz
== == == == = int findMissingElement(int A[], int n) {
  int XOR = 0;

  // take xor of all array elements
  for (int i = 0; i < n; i++) XOR ^= A[i];

  // take xor of numbers from 1 to n+1
  for (int i = 1; i <= n + 1; i++) XOR ^= i;

  // same elements will cancel out each other as a ^ a = 0
  // Also 0 ^ 0 = 0 and a ^ 0 = a

  // xor will contain the missing number
  return XOR;
}
== == == == =
                // Find missing number in a limited range array [1..n+1]
    int findMissingElement(int A[], int n) {
  // calculate sum of all elements of the array A
  int sum = accumulate(A, A + n, 0);

  // expected sum - actual sum
  // return (n + 1) + n * (n + 1)/2 - sum;
  return ((n + 1) * (n + 2)) / 2 - sum;
}
== == == ==
    =
// macro that defines integer size
#define SIZE_INT sizeof(int) * 8

        // Function to perform left circular shift or right circular shift
    // on integer n by k positions based on flag leftShift
    int circularShift(unsigned n, int k, bool leftShift) {
  // left shift by k
  if (leftShift) return (n << k) | (n >> (SIZE_INT - k));

  // right shift by k
  return (n >> k) | (n << (SIZE_INT - k));
}
== == == == = inline int swapAdjacentBits(int n) {
  return (((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1));
}
== == == == =
                // compute power of two less than or equal to n
    unsigned previousPowerOf2(unsigned n) {
  // do till only one bit is left
  while (n & n - 1) n = n & n - 1;  // unset rightmost bit

  // n is now a power of two (less than or equal to n)
  return n;
}
== == == == =
                // Find number of bits needed to be flipped to convert x to y
    int findBits(int x, int y) {
  // take XOR of x and y and store in n
  int n = x ^ y;

  // Using Brian Kernighan's algorithm to count set bits

  // count stores the total bits set in n
  int count = 0;

  for (; n; count++) n = n & (n - 1);  // clear the least significant bit set

  return count;
}
== == == == =
                // return true if binary representation of n is a palindrome
    bool isPalindrome(unsigned n) {
  // rev stores reverse of binary representation of n
  unsigned rev = 0;

  // do till all bits of n are processed
  unsigned k = n;
  while (k) {
    // add rightmost bit to rev
    rev = (rev << 1) | (k & 1);
    k = k >> 1;  // drop last bit
  }

  // return true if reverse(n) is same as n
  return n == rev;
}
== == == == =
                // perform bubble sort on arr[]
    void bubbleSort(int arr[], int n) {
  // (n - 1) pass
  for (int k = 0; k < n - 1; k++) {
    // last k items are already sorted, so inner loop can
    // avoid looking at the last k items
    for (int i = 0; i < n - 1 - k; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(arr, i, i + 1);
      }
    }

    // the algorithm can be stopped if the inner loop didn’t do any swap
  }
}
== == == == =
