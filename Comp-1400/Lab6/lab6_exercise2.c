#include <stdio.h>

int main(void) {
    int num=0, mod = 2, count = 1;

    puts("Please enter an integer number: ");
    scanf("%d", &num);

    while (mod < num) {
        if (num%mod == 0) {
            count = 0;
            break;
        }
        mod++;
    }
    if (count == 1) {
        printf("%d is a prime number\n", num);
    }
    else {
        printf("%d is not a prime number\n", num);
    }
}