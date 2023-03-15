/* ===========================================================================

COMP-1410 Midterm Review Lab

=========================================================================== */



#include <stdio.h>

#include <assert.h>



// count_ones(n) returns the number of 1s in the decimal representation of n

// requires: 0 <= n < 10^9

int count_ones(int n) {

   if(n == 1) {

       return 1;

   }

   if(n < 10) {

       return 0;

   }

   if(n % 10 == 1) {

       return 1 + count_ones(n / 10);

   }

   return count_ones(n / 10);

}



// count_ones_up_to_n(n) returns how many 1s are in the decimal representation

//  of the integers between 1 and n

// requires: 0 <= n < 10^5

/*Example:

n = 11

0 1 2 3 .. 9 10 11 -> 4

2 1 0 .. 0 1 0 = 4*/ 

int count_ones_up_to_n(int n) {

   if(n == 0) {

       return 0;

   }

   return count_ones(n) + count_ones_up_to_n(n - 1);

}



// row_sums(n, m, matrix, sums) updates sums to contain the row sums of the

//  given n by m matrix

// requires: 1 <= n <= 10, 1 <= m <= 10

//          sums points to an array of length at least n

//Input size: n x m

//Output size: 1 x n

void row_sums(int n, int m, int matrix [][10], int * sums) {

   for(int i = 0; i < n; i++) {

       sums[i] = 0;

       for(int j = 0; j < m; j++) {

           sums[i] += matrix[i][j];

       }

   }

}



int main(void) {

   // Perform your tests here

   assert(2 == count_ones(3115));

   assert(0 == count_ones(999999999));

   assert(9 == count_ones(111111111));



   assert(4 == count_ones_up_to_n(11));

   assert(6 == count_ones_up_to_n(13));



   int matrix[][10] = {{1,2,3},{4,5,6},{7,8,9}};

   int sums[10];

   int n = 3;

   int m = 3;

   for(int i = 0; i < 3; i++) {

       printf("%d ", sums[i]);

   }

   printf("\n");

   row_sums(n, m, matrix, sums);

   for(int i = 0; i < 3; i++) {

       printf("%d ", sums[i]);

   }

   assert(6 == sums[0]);

   assert(15 == sums[1]);

   assert(24 == sums[2]);

   printf("\nAll tests passed successfully.\n");

}