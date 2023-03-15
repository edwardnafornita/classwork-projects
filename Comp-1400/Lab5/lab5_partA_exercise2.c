#include <stdio.h>

int main(void) {
    int num1=0, check=0;
    puts("Please enter a number: ");
    scanf("%d", &num1);

    check = num1 % 2;
    if (check == 0) { 
        printf("%d is an even number", num1);
    }
    else { 
        printf("%d is an odd number", num1);
    }
}