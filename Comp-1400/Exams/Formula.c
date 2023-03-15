#include <stdio.h>

int main(void) {
    int a, b, c, x;
    int eqn=0;
    puts("Please enter four integer numbers for a, b, c, and x: ");
    scanf("%d, %d, %d, %d", &a, &b, &c, &x);

    if (x > 40000) {
        puts("Possible Overflow!");
    }
    else {
        eqn = a*b*x*x + b*b*x + c;
        printf("The result to the equation abx^2 + b^2x + c is %d", eqn);
    }
}