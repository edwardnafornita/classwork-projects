/* ===========================================================================
COMP-1410 Lab 1
Programmer: Edward Nafornita
Date: 2022-01-26
=========================================================================== */

#include <stdio.h>
#include <assert.h>

// digit_sum_iterative(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10^9
// note: implemented using iteration and not recursion
int digit_sum_iterative(int n);

// digit_sum_recursive(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10^9
// note: implemented using recursion and not iteration
int digit_sum_recursive(int n);

int main(void) {
  assert(digit_sum_iterative(1234) == 10);
  assert(digit_sum_recursive(1234) == 10);

  assert(digit_sum_iterative(999999999) == 81);
  assert(digit_sum_recursive(999999999) == 81);

  assert(digit_sum_iterative(0) == 0);
  assert(digit_sum_recursive(0) == 0);

  printf("All tests passed successfully.\n");
}

int digit_sum_iterative(int n) {
  int sum = 0;

  while (n != 0) {
    sum = sum + (n % 10);
    n = n / 10;
  }
  
  return sum;
}

int digit_sum_recursive(int n) {
  int sum = 0;

  if (n == 0) {
    return 0;
  }

  return sum = digit_sum_recursive(n/10) + n%10;

}