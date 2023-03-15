/* ===========================================================================
COMP-1410 Assignment 1
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// choose(n,m) returns how many ways there are to choose m items from
//   a set of n items
// requires: 0 <= m, 0 <= n
int choose(int n, int m);

// num_divisors_up_to_k(n,k) returns the number of positive divisors
//   of n that are less than or equal to k
// requires: 1 <= k <= n
int num_divisors_up_to_k(int n, int k);

// is_prime(n) returns true if n is a prime number and false otherwise
// requires: 1 <= n
bool is_prime(int n);

// collatz(n) returns the number of steps it takes to reach 1 by
//   by repeatedly applying the Collatz mapping on n; prints each
//   number in the sequence starting at n
// requires: 1 <= n
int collatz(int n);

int main(void) {
    // n choose m function asserts
    assert(choose(4, 2) == 6); 
    assert(choose(7, 2) == 21); 
    assert(choose(4, 10) == 0); 
    assert(choose(0, 0) == 1); 

    // num_divisors_up_to_k and is_prime asserts
    assert(num_divisors_up_to_k(9, 3) == 2);
    assert(is_prime(5) == true);
    
    assert(num_divisors_up_to_k(21, 7) == 3);
    assert(is_prime(11) == true);

    assert(num_divisors_up_to_k(4, 4) == 3);
    assert(is_prime(4) == false);

    assert(num_divisors_up_to_k(50, 25) == 5);
    assert(is_prime(50) == false);

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

int choose(int n, int m) {
    if (m == 0 || m == n) {
        return 1;
    }
    else if (m > n) {
        return 0;
    }
    else {
        return choose(n - 1, m) + choose(n - 1, m - 1);
    }
}

int num_divisors_up_to_k(int n, int k) {
    if (k < 1) {
        return 0;
    }
    else if (n % k == 0) {
        return num_divisors_up_to_k(n, --k) + 1;
    }
    else {
        return num_divisors_up_to_k(n, --k);
    }
}

bool is_prime(int n) {
    if (num_divisors_up_to_k(n, n) == 2) {
        return true;
    }
    else {
        return false;
    }
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