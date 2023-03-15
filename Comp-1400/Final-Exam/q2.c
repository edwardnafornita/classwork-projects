#include <stdio.h>

int main(void) {
    long int n=0;
    int count=0, temp=0;
    int digit0=0, digit1=0, digit2=0, digit3=0, digit4=0, digit5=0, digit6=0, digit7=0, digit8=0, digit9=0;

    puts("Please enter an integer number: ");
    scanf("%ld", &n);

    long int number=n;
    while(number > 0) {
        number = number/10;
        count++;
    }

    for (int i=count; i > 0; i--) {
        temp = n;
        temp = temp%10;

        switch(temp) {
            case 0:
                digit0++;
                break;
            case 1:
                digit1++;
                break;
            case 2:
                digit2++;
                break;
            case 3:
                digit3++;
                break;
            case 4:
                digit4++;
                break;
            case 5:
                digit5++;
                break;
            case 6:
                digit6++;
                break;
            case 7:
                digit7++;
                break;
            case 8:
                digit8++;
                break;
            case 9:
                digit9++;
                break;
        }
        n = n/10;
    }

    if (digit0 > 0) {
        if (digit0 == 1) {
            printf("Digit 0 has been repeated 1 time\n");
        }
        else {
            printf("Digit 0 has been repeated %d times\n", digit0);
        }
    }

    if (digit1 > 0) {
        if (digit1 == 1) {
            printf("Digit 1 has been repeated 1 time\n");
        }
        else {
            printf("Digit 1 has been repeated %d times\n", digit1);
        }
    }

    if (digit2 > 0) {
        if (digit2 == 1) {
            printf("Digit 2 has been repeated 1 time\n");
        }
        else {
            printf("Digit 2 has been repeated %d times\n", digit2);
        }
    }

    if (digit3 > 0) {
        if (digit3 == 1) {
            printf("Digit 3 has been repeated 1 time\n");
        }
        else {
            printf("Digit 3 has been repeated %d times\n", digit3);
        }
    }

    if (digit4 > 0) {
        if (digit4 == 1) {
            printf("Digit 4 has been repeated 1 time\n");
        }
        else {
            printf("Digit 4 has been repeated %d times\n", digit4);
        }
    }

    if (digit5 > 0) {
        if (digit5 == 1) {
            printf("Digit 5 has been repeated 1 time\n");
        }
        else {
            printf("Digit 5 has been repeated %d times\n", digit5);
        }
    }

    if (digit6 > 0) {
        if (digit6 == 1) {
            printf("Digit 6 has been repeated 1 time\n");
        }
        else {
            printf("Digit 6 has been repeated %d times\n", digit6);
        }
    }

    if (digit7 > 0) {
        if (digit7 == 1) {
            printf("Digit 7 has been repeated 1 time\n");
        }
        else {
            printf("Digit 7 has been repeated %d times\n", digit7);
        }
    }

    if (digit8 > 0) {
        if (digit8 == 1) {
            printf("Digit 8 has been repeated 1 time\n");
        }
        else {
            printf("Digit 8 has been repeated %d times\n", digit8);
        }
    }

    if (digit9 > 0) {
        if (digit9 == 1) {
            printf("Digit 9 has been repeated 1 time\n");
        }
        else {
            printf("Digit 9 has been repeated %d times\n", digit9);
        }
    }
}