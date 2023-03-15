#include <stdio.h>

int questionNum = 18;
int sum(void);

int main(void) {
    int selection=0;
    puts("Please select the program that you want to run:");
    puts("Questions 1 through 18");
    scanf("%d", &selection);
    while (selection < 1 || selection > 18) {
        puts("Please select the program that you want to run:");
    }

    switch (selection) {
        case 1:
            printf("The result is %d", sum());
            break;
        case 2:
            int asciiValue = 0;
            char asciiLetter;
            
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
    }
}

int sum(void) { 
    int n=0, sum=0;
    puts("Please enter an integer number: ");
    scanf("%d", &n);

    for (int i=1; i < n; i++) {
        sum = sum + i;
    }

    return sum;
}