/* ===========================================================================
COMP-1410 Midterm Review Lab
=========================================================================== */

#include <stdio.h>
#include <assert.h>

// row_sums(n, m, matrix, sums) updates sums to contain the row sums of the
//   given n by m matrix
// requires: 1 <= n <= 10, 1 <= m <= 10
//           sums points to an array of length at least n
void row_sums(int n, int m, int matrix[][3], int * sums);

int main(void) {
    // Perform your tests here
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sums[3] = {0,0,0};

    row_sums(3, 3, matrix, &sums[0]);
    assert(sums[0] == 6);
    assert(sums[1] == 15);
    assert(sums[2] == 24);
    printf("All tests passed successfully.\n");

}

void row_sums(int n, int m, int matrix[][3], int * sums){
    for(int j = 0; j<n; j++){
        for(int i = 0; i<m; i++){
            *(sums + j) += matrix[j][i];
        }
        printf("%d \n", sums[j]);
    }
}