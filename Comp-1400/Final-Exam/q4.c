#include <stdio.h>

int sumPositive(int n);
int sumOdd(int n);
float aveEven(int n);

int main(void) {
    int i=0;
    int executed = 1;
    int k=0;
    puts("How many numbers you want to enter: ");
    scanf("%d", &i);
    while (i <= 0) {
        puts("Your input is invalid, please try again.");
        puts("How many numbers you want to enter: ");
        scanf("%d", &i);
    }

    for (int j = 1; j <= i; j++) {
        executed = 1;
        k = 0;
        printf("\nEnter value %d: ", j);
        scanf("%d", &k);
        while (k <= 0) {
            puts("Your input is invalid, please try again.");
            printf("Enter value %d: ", j);
            scanf("%d", &k);
        }
        if (executed == 1) {
            printf("\n The sum of the first (%d) positive integers is %d", k, sumPositive(k));
            printf("\n The sum of the first (%d) odd numbers greater than or equal to %d is %d", k, k, sumOdd(k));
            printf("\n The average of the first (%d) even numbers strictly greater than %d is %.2f", k, k, aveEven(k));
            executed = 0;
        }
    }
}

int sumPositive(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    return sum;
}

int sumOdd(int n) { 
    int sum=0;
    int temp = n;
    if (temp%2 == 0) {
        temp++;
        n++;
    }
    for (int i = 1; i <= n; i++) {
        sum = sum + temp;
        temp += 2;
    }
    return sum;
}

float aveEven(int n) {
    float even=0;
    int sum = 0;
    int temp=n;

    if (temp%2 != 0) {
        temp++;
        n++;
    }
    for (int i = 1; i <= n; i++) {
        temp += 2;
        sum = sum + temp;
    }
    even = (float)sum / (float)n;
    return even;
}