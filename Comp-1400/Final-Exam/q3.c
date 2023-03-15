#include <stdio.h>
int n=9;
int myArray[9];
int isSymmetric(int myArray[], int n);

int main(void) {
    int executionValue=0;
    puts("Please enter 9 integer numbers: ");
    for (int i=0; i < n; i++) {
        scanf("%d", &myArray[i]);
    }

    executionValue = isSymmetric(myArray, 9);
    if (executionValue == 0) {
        printf("This array is not symmetric.\n");
    }
    else {
        printf("This array is symmetric.\n");
    }

}

int isSymmetric(int myArray[], int n) {
    int execution=0;
    n = n-1;
    for (int i = 0; i < n; i++) {
        if(myArray[i] == myArray[n-i]) {
            execution = 1;
        }
        else {
            execution = 0;
        }
    }

    return execution;
    
}