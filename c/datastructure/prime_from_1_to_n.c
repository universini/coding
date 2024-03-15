#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print prime numbers up to n
void printPrimes(int n) {
    // Create a boolean array "prime[0..n]" and initialize all entries as true.
    // A value in prime[i] will be false if i is not a prime, else true.
    bool prime[n+1];
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }

    // Sieve of Eratosthenes algorithm to find prime numbers
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or equal to p^2
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers
    printf("Prime numbers between 1 and %d are:\n", n);
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("There are no prime numbers less than 2\n");
    } else {
        printPrimes(n);
    }

    return 0;
}
