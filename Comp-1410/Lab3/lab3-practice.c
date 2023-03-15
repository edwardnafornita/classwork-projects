#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

// matrix_equals(n, m, a, b) returns true exactly when the n x m matrices
//   pointed to by a and b are equal
// requires: n >= 1, m >= 1
//           a and b point to the (0, 0) element of an n x m matrix
bool matrix_equals(const int n, const int m, const int *a, const int *b) {
    int *len = (int *)a + (n * m);

    while (a < len) {
        if (*a != *b) {
            return false;
        }
        a++;
        b++;
    }

    return true;
}

// negate_row(n, m, a, r) negates the entries in row r of matrix a
// requires: n >= 1, m >= 1, 0 <= r < n
//           a points to the (0, 0) element of an n x m matrix
void negate_row(const int n, const int m, int *a, const int r) {
    int *value = a + r*m;

    while (value < a + (r+1)*m) {
        *value *= -1;
        value++;
    }
}

// negate_col(n, m, a, c) negates the entries in column c of matrix a
// requires: n >= 1, m >= 1, 0 <= c < m
//           a points to the (0, 0) element of an n x m matrix
void negate_col(const int n, const int m, int *a, const int c) {
    int *value = a + c;

    while (value < a + n*m) {
        *value *= -1;
        value++;
    }
}

// matrix_add(n, m, a, b, c) computes the sum of the matrices a and b;
//   the result is stored in the matrix c
// requires: n >= 1, m >= 1
void matrix_add(const int n, const int m, const int *a, const int *b, int *c) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            *c = *a + *b;
            a++, b++, c++;
        }
    }
}

int main(void) {

    int a1[2][3] = {{1, 5, 7}, {2, 7, 4}};
    int a2[2][3] = {{0, 4, 2}, {1, 2, 1}};
    int a3[2][3] = {{1, 9, 9}, {3, 9, 5}};
    int c1[2][3];

    matrix_add(2, 3, &a1[0][0], &a2[0][0], &c1[0][0]);
    assert(matrix_equals(2, 3, &a3[0][0], &c1[0][0]) == true);

    int b1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int b2[3][3] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int b3[3][3] = {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}};
    int c2[3][3];

    matrix_add(3, 3, &b1[0][0], &b2[0][0], &c2[0][0]);
    assert(matrix_equals(3, 3, &b3[0][0], &c2[0][0]) == true);

    int d1[1][1] = {{1}};
    int d2[1][1] = {{4}};
    int d3[1][1] = {{5}};
    int c3[1][1];

    matrix_add(1, 1, &d1[0][0], &d2[0][0], &c3[0][0]);
    assert(matrix_equals(1, 1, &d3[0][0], &c3[0][0]) == true);
    puts("Assertions Passed!");
}