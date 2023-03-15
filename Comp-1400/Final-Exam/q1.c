#include <stdio.h>

int main(void) {
    int n=0, sum=0, numOfFactors=0;
    float avg=0.0;

    puts("Please enter an integer number: ");
    scanf("%d", &n);

    if (n <= 1) {
        puts("No input less than or equal to 1, goodbye!");
    }
    else {
        for (int i = 1; i < n; i++) {
            if ((n%i) == 0) {
                printf("%d ", i);
                numOfFactors++;
                sum = sum + i;
            }
        }

        avg = (float)sum / (float)numOfFactors;

        printf("\nThe average of the factors is %.2f\n", avg);
    }
}