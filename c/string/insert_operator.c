#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backtrack(char* digits, int target, int start, int current, char* expression);

void addOperators(char* digits, int target) {
    if (digits == NULL || *digits == '\0') {
        return;
    }

    char* expression = (char*)malloc(strlen(digits) * 2);  // Max length of expression
    expression[0] = digits[0];
    expression[1] = '\0';

    backtrack(digits, target, 1, digits[0] - '0', expression);

    free(expression);
}

void backtrack(char* digits, int target, int start, int current, char* expression) {
    if (digits[start] == '\0') {
        // If we reach the end of the string, check if the current expression equals the target
        if (current == target) {
            printf("%s\n", expression);
        }
        return;
    }

    // Try adding the current digit
    expression[strlen(expression)] = '+';
    expression[strlen(expression)] = digits[start];
    expression[strlen(expression) + 1] = '\0';
    backtrack(digits, target, start + 1, current + (digits[start] - '0'), expression);
    expression[strlen(expression) - 2] = '\0';

    // Try subtracting the current digit
    expression[strlen(expression)] = '-';
    expression[strlen(expression)] = digits[start];
    expression[strlen(expression) + 1] = '\0';
    backtrack(digits, target, start + 1, current - (digits[start] - '0'), expression);
    expression[strlen(expression) - 2] = '\0';
}

int main() {
    char input[] = "123";
    int target = 6;

    printf("Expressions to achieve the target %d are:\n", target);
    addOperators(input, target);

    return 0;
}
