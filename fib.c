#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
long fib_recursive(int n);
long fib_iterative(int n);


// Function definitions

long fib_recursive(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long fib_iterative(int n) {
    int num1 = 0, num2 = 1, next;
    if (n == 0) return num1;
    if (n == 1) return num2;

    for (int i = 2; i <= n; i++) {
        next = num1 + num2;
        num1 = num2;
        num2 = next;
    }
    return num2;
}

int main(int argc, char *argv[]) {
    
    
    if (argc != 4) {
        printf("Usage: %s <integer> <r/i/c> <filename>\n", argv[0]);
        return 1;
    }

    // Read file
    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        printf("Could not open file '%s'\n", argv[3]);
        return 1;
    }

    int file_number;
    fscanf(file, "%d", &file_number);  // Read the integer from the file
    fclose(file);  // Close the file

    // Get input number from command-line argument
    int input_number = atoi(argv[1]);

    // Calculate N as the sum of input number and file number
    int N = input_number + file_number - 1;

    int fib;

    // Determine which Fibonacci function to use based on the second argument
    if (strcmp(argv[2], "r") == 0) {
        fib = fib_recursive(N);
    } else if (strcmp(argv[2], "i") == 0) {
        fib = fib_iterative(N);
    } else if (strcmp(argv[2], "c") == 0) {
        fib = fib_cache(N);
    } else {
        printf("Second argument must be 'r', 'i', or 'c'\n");
        return 1;
    }

    // Print Fibonacci result without extra newlines or spaces
    printf("%d", fib);

    return 0;
}
