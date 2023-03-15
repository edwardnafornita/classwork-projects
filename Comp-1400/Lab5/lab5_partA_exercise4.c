#include <stdio.h>

int main(void) {
    //initiating variables
    int a, b, c;
    int bignum=0, smallnum=0;

    //collect variables
    puts("Please enter three numbers: ");
    scanf("%d, %d, %d", &a, &b, &c);

    //Checking for the largest number
    if (a < b && b < c) {
        bignum = c;
    }
    else if (a < b && b > c) {
        bignum = b;
    }
    else {
        bignum = a;
    }
    
    //Checking for the smallest number
    if (a < b && a < c) {
        smallnum = a;
    }
    else if (b < a && b < c){
        smallnum = b;
    }
    else {
        smallnum = c;
    }

    printf("The smallest number is %d, while the largest number is %d.", smallnum, bignum);
}