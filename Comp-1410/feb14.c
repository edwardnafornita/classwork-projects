#include <stdio.h>

void swap(int *a, int *b) {
    int dummy = *a;
    *a = *b;
    *b = dummy;
}

void selection_sort(int a[], int n) {
    for (int j = 0; j < n; j++) {
        int init = a[j];
        int *ptr_init = &a[j];

        for (int i = j; i < n; i++) {
            if (a[i] < init)  {
                init = a[i];
                ptr_init = &a[i];
            }
        }
        
        swap(&a[j], ptr_init);
    }
}

void insertion_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 1 && a[j - 1] > a[j]; --j) {
            swap(&a[j], &a[j - 1]);
        }
    }
}

int linear_search(int a[, int n, int item) {
    for ( int i = 0; i < n; i++) {
        if (a[i] == item) {
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int n, int item) {
    while (low <= hi) {
        int low = 0;
        int high = n -1;

        int mid = (low - high) / 2;
        int mid_entry = a[mid];

        if (mid_entry == item) {
            return mid;
        }
        else if (mid_entry > item) {
            high = mid;
        }
        else if (mid_entry < item) {
            low = mid - 1;
        }
    }
    return -1;
}

int main(void) {
    int a[7] = {8, 6, 7, 5, 3, 0, 9};

    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    
    insertion_sort(a, 7);

    for (int i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}