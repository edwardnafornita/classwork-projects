/*
Comp-1400 Lab 8 - Part B
Developer: Edward Nafornita (ID: 110076381)
Date: Wednesday November 17th, 2021
*/

// initialise required libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declaring main function
int main(void) {

    // setting time function to allow for numerical randomness
    time_t t;
    srand((unsigned int)time(&t));

    // declaring required variables
    int list[30];
    int num=0;
    int count=0;

    // loop that generates 30 random numbers between 0 and 20
    for (int i = 0; i < 30; i++) {
        int x = rand() % 21;
        list[i] = x;
    }

    // receive input from user to calculate for the frequency of a number in that particular array
    puts("Please enter the number, between 0 to 20, that you want to calculate for the frequency:");
    scanf("%d", &num);
    // check for inputted number being in the range of 0 to 20
    while (num < 0 || num > 20) {
        puts("Please enter the number, between 0 to 20, that you want to calculate for the frequency:");
        scanf("%d", &num);
        
    }

    // counting how many times that number appears in the array
    for (int i = 0; i < 30; i++) {
        if (list[i] == num) {
            count++;
        }
    }

    // final statement displaying the array, the value the user inputted, and the frequency of that number.
    printf("The value %d appears %d times in the following list:\n", num, count);
    for (int i = 0; i < 30; i++) {
        printf("%d ", list[i]);
    }
}