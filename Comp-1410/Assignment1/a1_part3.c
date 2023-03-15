/* ===========================================================================
COMP-1410 Assignment 1 - Part 3
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// collatz(n) returns the number of steps it takes to reach 1 by
//   by repeatedly applying the Collatz mapping on n; prints each
//   number in the sequence starting at n
// requires: 1 <= n
int collatz(int n);

int main(void) {
    int start = 1;
    int n = 0;
    while (start == 1) {
        printf("Please enter a number: \n");
        if (scanf("%d", &n)) {
            if (n >= 1) {
               printf("It took %d steps to reach the number 1.\n", collatz(n));
               start = 0;
            }
            else {
                printf("Error: Invalid Number.\n");
            }
        }
        else {
           start = 0;
        }
    }

    puts("The following numbers being printed out are from the collatz assertions:");
    // First collatz assertion:
    assert(collatz(1) == 0);
    puts("");
    // Second collatz assertion:
    assert(collatz(65) == 27);
    puts("");
    // Third collatz assertion:
    assert(collatz(100) == 25);
    puts("");
    // Fourth collatz assertion:
    assert(collatz(7) == 16);
    puts("");
}

int collatz(int n) {
    int count;
    if (n == 1) {
        printf("%d\n", n);
        return count;
    }
    else if (n % 2 != 0) {
        printf("%d -> ", n);
        return count = collatz(3 * n + 1) + 1;
    }
    else {
        printf("%d -> ", n);
        return count = collatz(n / 2) + 1;
    }
}