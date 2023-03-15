#include <stdio.h>

int main(void) {
    char grade, letterGrade;
    int numberGrade=0;

    puts("Please enter the conversion type (N or n for number, C or c for letter: ");
    scanf(" %c", &grade);

    switch(grade) {
        case 'N':
            puts("Please enter the number grade as an integer: ");
            scanf("%d", &numberGrade);
            if (numberGrade >= 0 && numberGrade <= 49) {
                printf("The letter grade of %d is F", numberGrade);
            }
            else if (numberGrade >= 50 && numberGrade <= 59) {
                printf("The letter grade of %d is D", numberGrade);
            }
            else if (numberGrade >= 60 && numberGrade <= 69) {
                printf("The letter grade of %d is C", numberGrade);
            }
            else if (numberGrade >= 70 && numberGrade <= 72) {
                printf("The letter grade of %d is B-", numberGrade);
            }
            else if (numberGrade >= 73 && numberGrade <= 76) {
                printf("The letter grade of %d is B", numberGrade);
            }
            else if (numberGrade >= 77 && numberGrade <= 79) {
                printf("The letter grade of %d is B+", numberGrade);
            }
            else if (numberGrade >= 80 && numberGrade <= 84) {
                printf("The letter grade of %d is A-", numberGrade);
            }
            else if (numberGrade >= 85 && numberGrade <= 89) {
                printf("The letter grade of %d is A", numberGrade);
            }
            else if (numberGrade >= 90 && numberGrade <= 100) {
                printf("The letter grade of %d is A+", numberGrade);
            }
            else {
                printf("Number grade %d is invalid", numberGrade);
            }
            break;
        case 'n':
            puts("Please enter the number grade as an integer: ");
            scanf("%d", &numberGrade);
            if (numberGrade >= 0 && numberGrade <= 49) {
                printf("The letter grade of %d is F", numberGrade);
            }
            else if (numberGrade >= 50 && numberGrade <= 59) {
                printf("The letter grade of %d is D", numberGrade);
            }
            else if (numberGrade >= 60 && numberGrade <= 69) {
                printf("The letter grade of %d is C", numberGrade);
            }
            else if (numberGrade >= 70 && numberGrade <= 72) {
                printf("The letter grade of %d is B-", numberGrade);
            }
            else if (numberGrade >= 73 && numberGrade <= 76) {
                printf("The letter grade of %d is B", numberGrade);
            }
            else if (numberGrade >= 77 && numberGrade <= 79) {
                printf("The letter grade of %d is B+", numberGrade);
            }
            else if (numberGrade >= 80 && numberGrade <= 84) {
                printf("The letter grade of %d is A-", numberGrade);
            }
            else if (numberGrade >= 85 && numberGrade <= 89) {
                printf("The letter grade of %d is A", numberGrade);
            }
            else if (numberGrade >= 90 && numberGrade <= 100) {
                printf("The letter grade of %d is A+", numberGrade);
            }
            else {
                printf("Number grade %d is invalid.", numberGrade);
            }
            break;
        case 'C':
            puts("Please enter the letter grade as a character");
            scanf(" %c", &letterGrade);
            if (letterGrade == 'F' || letterGrade == 'f') {
                printf("The word grade of %c is Failure.", letterGrade);
            }
            else if (letterGrade == 'D' || letterGrade == 'd') {
                printf("The word grade of %c is Pass.", letterGrade);
            }
            else if (letterGrade == 'C' || letterGrade == 'c') {
                printf("The word grade of %c is Fair.", letterGrade);
            }
            else if (letterGrade == 'B' || letterGrade == 'b') {
                printf("The word grade of %c is Good.", letterGrade);
            }
            else if (letterGrade == 'A' || letterGrade == 'a') {
                printf("The word grade of %c is Excellent.", letterGrade);
            }
            else {
                printf("Letter grade %c is invalid.", letterGrade);
            }
            break;
        case 'c':
            puts("Please enter the letter grade as a character");
            scanf(" %c", &letterGrade);
            if (letterGrade == 'F' || letterGrade == 'f') {
                printf("The word grade of %c is Failure.", letterGrade);
            }
            else if (letterGrade == 'D' || letterGrade == 'd') {
                printf("The word grade of %c is Pass.", letterGrade);
            }
            else if (letterGrade == 'C' || letterGrade == 'c') {
                printf("The word grade of %c is Fair.", letterGrade);
            }
            else if (letterGrade == 'B' || letterGrade == 'b') {
                printf("The word grade of %c is Good.", letterGrade);
            }
            else if (letterGrade == 'A' || letterGrade == 'a') {
                printf("The word grade of %c is Excellent.", letterGrade);
            }
            else {
                printf("Letter grade %c is invalid.", letterGrade);
            }
            break;
        default:
            printf("Goodbye!");
    }

}