/* ===========================================================================
COMP-1410 Assignment 1 - Part 1
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// choose(n,m) returns how many ways there are to choose m items from
//   a set of n items
// requires: 0 <= m, 0 <= n
int choose(int n, int m);

int main(void) {
    // n choose m function asserts
    assert(choose(4, 2) == 6); 
    assert(choose(7, 2) == 21); 
    assert(choose(4, 10) == 0); 
    assert(choose(0, 0) == 1); 
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