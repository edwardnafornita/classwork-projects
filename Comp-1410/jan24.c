/**
 * @file jan24.c
 * @author Edward
 * @brief - Lesson 1 - Recursion in C Programming
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <assert.h>

// sum(n) returns the sum of the integers 0,1,...,n
// requires: n >= 0
int sum(int n) {
    if (n == 0) { //base case
        return 0;
    }
    else if (n > 0) { //recursive case
        return sum(n - 1) + n;
    }
    return 0;
}

// fib(n) return the nth Fibonacci number
// require: n >= 0
int fib(int n) {
    if (n == 0) { //base case 1
        return 0;
    }
    else if (n == 1) { //base case 2
        return 1;
    }
    else { //recursive case
        return fib(n - 1) + fib(n - 2);
    }
}

int main(void) {
    // Tests for the function that you're going to write
    assert(sum(0) == 0);
    assert(sum(1) == 1);
    assert(sum(4) == 10);

    assert(fib(0) == 0);
    fib(40);

    printf("All tests completed successfully!\n");
    return 0;
}