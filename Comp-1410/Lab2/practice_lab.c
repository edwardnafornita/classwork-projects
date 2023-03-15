#include <stdio.h>
#include <assert.h>

void swap_pointers(int **a, int **b) {
    int *t = *a;
    *a = *b;
    *b = *t;
}

int main(void) {
    int a = 5, b = 10;
    assert(swap_pointers(&a, &b) == );
}