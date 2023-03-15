/*
Comp-1400 Lab 8 - Part A
Developer: Edward Nafornita (ID: 110076381)
Date: Wednesday November 17th, 2021
*/

// including required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declaring main function
int main(void) {
    // declaring the time and clock functions
    time_t start_t;
    clock_t start, end;
    srand((unsigned int)time(&start_t)); // reseting the random number generator

    // declaring required variables
    int array_size=0, index_swap;

    // initialising clock
    start = clock();

    // receiving size of the array and setting it to the array variable
    puts("Please enter a positive integer number for the size of the array:");
    scanf("%d", &array_size);
    int array[array_size];

    // fills the list with random values from 0 to 500.
    printf("The random number generator of %d elements generated these values:\n", array_size);
    for (int i = 0; i < array_size; i++) {
        int num = rand() % 501;
        array[i] = num;
        printf("%d ", array[i]);
    }
 
    puts(""); // brings cursor to new line for aesthetic purposes

    // sorts the entire list from least to greatest value
    for (int i = 0; i < array_size; i++) {
        for (int j = 0; j < (array_size - 1); j++) {
            if (array[j] > array[j+1]) {
                index_swap = array[j];
                array[j] = array[j+1];
                array[j+1] = index_swap;
            }
            index_swap = 0;
        }
    }

    // displays the sorted list of numbers
    printf("The sorted list of numbers is:\n");
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }

    puts(""); // new line for aesthetic purposes

    end = clock(); // ends the clock
    double timeElapsed = (double)(end - start)/CLOCKS_PER_SEC;  // calculates the time elapsed
    printf("The number of seconds elapsed was %.3f seconds.\n", timeElapsed); //displays the time elapsed
}