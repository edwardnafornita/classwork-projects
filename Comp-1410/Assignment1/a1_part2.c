/* ===========================================================================
COMP-1410 Assignment 1 - Part 2
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// num_divisors_up_to_k(n,k) returns the number of positive divisors
//   of n that are less than or equal to k
// requires: 1 <= k <= n
int num_divisors_up_to_k(int n, int k);

// is_prime(n) returns true if n is a prime number and false otherwise
// requires: 1 <= n
bool is_prime(int n);

int main(void) {
    // num_divisors_up_to_k and is_prime asserts
    assert(num_divisors_up_to_k(9, 3) == 2);
    assert(is_prime(5) == true);
    
    assert(num_divisors_up_to_k(21, 7) == 3);
    assert(is_prime(11) == true);

    assert(num_divisors_up_to_k(4, 4) == 3);
    assert(is_prime(4) == false);

    assert(num_divisors_up_to_k(50, 25) == 5);
    assert(is_prime(50) == false);
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