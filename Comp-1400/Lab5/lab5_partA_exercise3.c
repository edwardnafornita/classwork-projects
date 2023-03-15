#include <stdio.h>

int main(void) {
    int y1=0;
    puts("Please enter the year you want to check to see if it is a leap year.");
    scanf("%d",&y1);

    if (y1%4 == 0) {
        if (y1%100 != 0) {
            printf("The year %d is a leap year.\n",y1);
        }
        else {
            if (y1%400 == 0) {
                printf("The year %d is a leap year.\n",y1);
            }
            else {
                printf("The year %d is not a leap year.\n",y1);
            }
        }
    }
    else {
        printf("The year %d is not a leap year.\n", y1);
    }
}