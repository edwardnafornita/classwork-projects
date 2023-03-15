#include <stdio.h>

int main(void) {
    int num=0, sum=0, avg=0, count=1;

    while (count <= 10) {
        puts("Please enter a number: ");
        scanf("%d", &num);
        sum = sum + num;
        count++;
    }
    avg = sum / 10;

    printf("The sum of the 10 digits is %d, and the average is %d.\n", sum, avg);
}