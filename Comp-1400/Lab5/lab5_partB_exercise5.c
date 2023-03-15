#include <stdio.h>

int main(void) {
    long long int isbn;
    int count=1, sum=0, rem, digit, checkDigit;

    puts("Enter the first 12 digits of the ISBN-13 number: ");
    scanf("%lld", &isbn);

    while (isbn > 0) {
        digit = isbn % 10;

        if (count % 2 == 0) {
            sum = sum + (digit * 1);
            count = 1;
        }
        else {
            sum = sum + (digit * 3);
            count = 2;
        }
        
        isbn = isbn / 10;
    }
    
    rem = sum % 10;
    checkDigit = 10 - rem;

    printf("The check digit of the ISBN-13 number is %d.", checkDigit);
}