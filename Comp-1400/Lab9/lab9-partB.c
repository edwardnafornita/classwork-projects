/*
Assignment: Comp-1400 Lab 9 Part B
Developer: Edward Nafornita
Date: November 24th 2021
*/

// declaring required libraries
#include <stdio.h>

// declaring the prototype of the factorial function
int factorial(int x);

// declaring the main function
int main(void) {
    // declaring required variables
    int x;
    // receiving an input from the user
    puts("Please enter a positive value: ");
    scanf("%d", &x);

    // checking for validity (must be positive number)
    while (x < 0) {
        puts("Please enter a positive value: ");
        scanf("%d", &x);
    }

    // displaying the result of the factorial function
    printf("The factorial of %d is %d\n", x, factorial(x));

    // displays additional results of the factorial function
    puts("Additionally the factorial of 2, 3, 4, 5, 10, and 15 are:");
    printf("2 factorial = %d\n", factorial(2));
    printf("3 factorial = %d\n", factorial(3));
    printf("4 factorial = %d\n", factorial(4));
    printf("5 factorial = %d\n", factorial(5));
    printf("10 factorial = %d\n", factorial(10));
    printf("15 factorial = %d\n", factorial(15));

    // Answer to the Question:
    // the maximum value of an integer is 2,147,483,647. Although, as noticed, 15 factorial produces an incorrect value. This is due to the limits of a standard integer datatype meaning
    // that the value of 15 factorial must be larger than the limit of the integer datatype, which must be the cause for the production of an incorrect value.
    // Therefore, knowing the bounds of an integer datatype, we can calculate that the largest factorial that can be calculated with this algorithm is 12 factorial.
}

// declaring and computing the factorial of a number inputted, alongside some 
int factorial(int x) {
    int fact = x;
    for (int i = 1; i < x; i++) {
        fact = fact * (x-i);
    }

    return fact;
}
