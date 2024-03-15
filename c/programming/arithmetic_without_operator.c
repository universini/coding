#include <stdio.h>

// Function to perform addition without using + operator
int add(int x, int y) {
    while (y != 0) {
        int carry = x & y;
        x = x ^ y;
        y = carry << 1;
    }
    return x;
}

// Function to perform subtraction without using - operator
int subtract(int x, int y) {
    while (y != 0) {
        int borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

// Function to perform multiplication without using * operator
int multiply(int x, int y) {
    int result = 0;
    while (y != 0) {
        if (y & 1)
            result = add(result, x);
        x <<= 1;
        y >>= 1;
    }
    return result;
}

// Function to perform division without using / operator
int divide(int x, int y) {
    int quotient = 0;
    while (x >= y) {
        x = subtract(x, y);
        quotient = add(quotient, 1);
    }
    return quotient;
}

int main() {
    int a = 15, b = 5;
    
    printf("Addition: %d + %d = %d\n", a, b, add(a, b));
    printf("Subtraction: %d - %d = %d\n", a, b, subtract(a, b));
    printf("Multiplication: %d * %d = %d\n", a, b, multiply(a, b));
    printf("Division: %d / %d = %d\n", a, b, divide(a, b));
    
    return 0;
}
