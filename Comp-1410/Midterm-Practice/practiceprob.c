/* ===========================================================================
COMP-1410 Midterm Review Lab
=========================================================================== */

#include <stdio.h>
#include <assert.h>

// count_ones(n) returns the number of 1s in the decimal representation of n
// requires: 0 <= n < 10^9
int count_ones(int n) {
    int count = 0;
    int last_num = n % 10;
    if (n == 0) {
        return 0;
    }
    else if (last_num == 1) {
        return count = count_ones(n / 10) + 1;
    }
    else {
        return count = count_ones(n / 10);
    }
}

// count_ones_up_to_n(n) returns how many 1s are in the decimal representation
//   of the integers between 1 and n
// requires: 0 <= n < 10^5
int count_ones_up_to_n(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return count_ones(n) + count_ones_up_to_n(n - 1);
    }
}

// row_sums(n, m, matrix, sums) updates sums to contain the row sums of the
//   given n by m matrix
// requires: 1 <= n <= 10, 1 <= m <= 10
//           sums points to an array of length at least n
void row_sums(int n, int m, int matrix[][10], int *sums) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sums[i] += matrix[i][j];
        }
        printf("%d ", sums[i]);
    }
    puts("");
}

int main(void) {
    // Perform your tests here
    assert(count_ones(1231) == 2);
    assert(count_ones(0) == 0);
    assert(count_ones(111111111) == 9);

    assert(count_ones_up_to_n(30) == 13);
    assert(count_ones_up_to_n(10) == 2);
    assert(count_ones_up_to_n(10) == 2);

    int a[2][10] = {{1, 2, 3}, {4, 5, 6}};
    int sums1[2] = {0, 0};
    int sums_result1[2] = {6, 15};
    row_sums(2, 3, a, &sums1[0]);
    assert(sums1[0] == sums_result1[0]);
    assert(sums1[1] == sums_result1[1]);
    printf("All tests passed successfully.\n");
}