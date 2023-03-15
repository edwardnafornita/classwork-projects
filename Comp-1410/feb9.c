#include <stdio.h>

// prints the contents of array "a" of length "len" to the screen.
void print_array(int a[], int len) {
    for (int i = 0; i < len; i++) {
        if (i == len - 1) {
            printf("%d ", a[i]);
        }
        else {
            printf("%d, ", a[i]);
        }
    }
    printf("\n");
}

// negates the values in the array "a" of length "len".
void negate_array(int *a, int len) {
    for (int i = 0; i < len; i++) {
        a[i] = -a[i];
    }
}

int main(void) {
    int a[6] = {1,2,3,4,5,6};

    negate_array(&a[0], 6);
   
    print_array(a, 6);
