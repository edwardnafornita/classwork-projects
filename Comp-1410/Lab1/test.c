#include <stdio.h>
#include <assert.h>

int digit_sum_iterative(int n);
int digit_sum_recursive(int n);

int main(void) {
 //   printf("Please enter a number between 0 and 1x10^9: \n");

    assert(digit_sum_iterative(56) == 11);
    assert(digit_sum_recursive(56) == 11);

    printf("All tests passed successfully. \n");
}

int digit_sum_iterative(int n) {
    int workingNum;
    int answer = 0;

    while (n != 0) {
        workingNum = n%10;
        answer = answer + workingNum;
        n = n/10;
    }

//    printf("The digit summation of your number is %d \n", answer);
    return answer;
}

int digit_sum_recursive(int n){
    int workingNum;
    int answer = 0;

    if (n == 0) { //base case
        return 0;
    }
    else { //recursive case
        workingNum = n%10;
        n = n/10;
        answer = digit_sum_recursive(n) + workingNum;
        return answer;
    }
}
