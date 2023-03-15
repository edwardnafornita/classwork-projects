#include <stdio.h>

int isPerfect(int num);

int main(void) {
    int num=0;

    for (int i = 1; i <= 1000; i++) {
        num = i;
        if (isPerfect(num) == 1) {
            printf("The number %d is a perfect number\n", num);
        }

    }
}

int isPerfect(int num) {
    int value=1;

    for (int i = 2; i <= num/2; i++) {
        if (num % i == 0) {
            value = value + num / i;
        }
    }
    
    if (value == num) {
        return 1;
    }
    else {
        return 0;
    }
}