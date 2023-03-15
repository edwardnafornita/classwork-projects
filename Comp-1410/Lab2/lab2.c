/* ===========================================================================
COMP-1410 Lab 2 - Edward Nafornita
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// order(a, b) orders the values pointed to by a and b so that *a <= *b;
//   *diff is set to absolute value of the difference between *a and *b;
//   returns true if the values were switched and false otherwise
// requires: a, b, and diff point to memory that can be modified
// bool order(int *const a, int *const b, int *const diff);
bool order(int *const a, int *const b, int *const diff);

int main(void) {
    // Perform your tests here
    int a, b, diff;
    a = 12, b = 3, diff = 0;
    puts("Case 1 - Before swap:");
    printf("Value of 'a' = %d\nValue of 'b' = %d\nValue of 'diff' = %d\n", a, b, diff);
    puts("");
    puts("After swap:");
    assert(order(&a, &b, &diff) == true);
    printf("Value of 'a' = %d\nValue of 'b' = %d\nValue of 'diff' = %d\n", a, b, diff);
    puts("");
  
    a = 5, b = 10, diff = 0;
    puts("Case 2 - Before swap:");
    printf("Value of 'a' = %d\nValue of 'b' = %d\nValue of 'diff' = %d\n", a, b, diff);
    puts("");
    puts("After swap:");
    assert(order(&a, &b, &diff) == false);
    printf("Value of 'a' = %d\nValue of 'b' = %d\nValue of 'diff' = %d\n", a, b, diff);
    puts("");

    a = 5, b = 5, diff = 0;
    puts("Case 3 - Before swap:");
    printf("Value of 'a' = %d\nValue of 'b' = %d\nValue of 'diff' = %d\n", a, b, diff);
    puts("");
    puts("After swap:");
    assert(order(&a, &b, &diff) == false);
    printf("Value of 'a' = %d\nValue of 'b' = %d\nValue of 'diff' = %d\n", a, b, diff);
    puts("");
    
    printf("All tests passed successfully.\n");
}

bool order(int *const a, int *const b, int *const diff) {
    if (*a < *b) {
        *diff = *b - *a;
        return false;
    }
    else if (*a > *b) {
        *diff = *a - *b;
        int dummy = *a;
        *a = *b;
        *b = dummy;
        return true;
    }
    else {
        *diff = *a - *b;
        return false;
    }
}
