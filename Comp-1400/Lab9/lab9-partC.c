/*
Assignment: Comp-1400 Lab 9 Part B
Developer: Edward Nafornita
Date: November 24th 2021
*/

// declaring necessary libraries
#include <stdio.h>
#include <math.h>
// function prototype for the binary calculator
long long int numberToBinary(int x);

// declaring the main function
int main(void) {
    int x;
    // receives input from the user
    puts("Please enter a positive number to convert into binary:");
    scanf("%d", &x);

    // checks for validity
    while (x < 0) {
        puts("Please enter a positive number to convert into binary:");
        scanf("%d", &x);
    }

    // displays the result of the binary calculator
    printf("The number, %d, in binary is %lld\n", x, numberToBinary(x));

    // displays more results of the binary calculator, but these are constant values given in the question
    puts("");
    puts("Additionally:");
    printf("Binary of 1 is %lld\n", numberToBinary(1));
    printf("Binary of 2 is %lld\n", numberToBinary(2));
    printf("Binary of 10 is %lld\n", numberToBinary(10));
    printf("Binary of 1001 is %lld\n", numberToBinary(1001));
    printf("Binary of 90250 is %lld\n", numberToBinary(90250));

}

// declaring the binary calculator function
long long int numberToBinary(int x) {
    // declaring necessary variables for the function
    long long int numToBinary=0;
    int y;

    // checking how many power increments can fit inside the given number
    for (int i = 0; pow(2, i) <= x; i++) {
        y = i;
    }
    // computing the binary calculation
    for (y; y >= 0; y--) {
        if ((x - pow(2, y)) >= 0) {
            numToBinary = numToBinary * 10 + 1;
            x = x - pow(2, y);
        }
        else {
            numToBinary = numToBinary * 10;
        }
    }

    return numToBinary;

}