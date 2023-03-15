/*
Title: Guessing Game
Programmer: Edward Nafornita
Date: November 8th, 2021
*/

//Defining necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Main function declaration
int main(void) {
    
    //srand setup
    time_t t; //time variable definition
    srand((unsigned) time(&t)); //resetting time variable

    //defining necessary variables
    int lives = 10;
    int guess = 0;
    int play = 1;
    int goal = rand() % 50 + 1; //creates a random number
    
    //being game
    while(play == 1) {
        //making sure lives aren't zero, or the guess isn't the goal.
        if (lives != 0 && guess != goal) {
            printf("Enter your guess (between 1 and 50):");
            scanf("%d", &guess);

            //checking the boundaries of the guess
            if (guess > goal) {
                printf("Too high...\n"); //guessing too high
                lives = lives - 1;
            }
            else if (guess < goal) {
                printf("Too low...\n"); //guessing too low
                lives = lives - 1;
            }
            //correct guess
            else {
                printf("Correct, the number was %d.", goal);
                play = 0;
            }
        }
        //if the lives are zero or the guess equals the goal proceed to this else
        else {
            printf("Sorry, the correct number was %d.", goal);
            play = 0;
        }
    }
}