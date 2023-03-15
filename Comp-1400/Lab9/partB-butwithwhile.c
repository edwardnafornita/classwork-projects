#include <stdio.h>

long int factorial(int x);

int main(void) {
    int x;
    puts("Please enter a positive value: ");
    scanf("%d", &x);

    while (x < 0) {
        puts("Please enter a positive value: ");
        scanf("%d", &x);
    }

    printf("The factorial of the number is %ld\n", factorial(x));
}

long int factorial(int x) {
    long int fact = x;
    int i = 1;
    while (i < x) {
        fact = fact * (x-i);
        i++;
    }

    return fact;
}
