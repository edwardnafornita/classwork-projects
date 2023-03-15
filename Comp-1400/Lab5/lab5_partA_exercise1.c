#include <stdio.h>

int main(void) {
    int num1=0, num2=0, rem=0;
    puts("Please enter two integer values: ");
    scanf("%d, %d", &num1, &num2);

    rem = num1 % num2;
    printf("The remainder of %d and %d is %d", num1, num2, rem);
}