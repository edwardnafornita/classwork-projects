#include <stdio.h>
#include <assert.h>
#include <string.h>

void swapToFront(char str[], char *c);

void swapToBack(char str[], char *c);

char *select_max(char str[]);

void strSort(char str[]);

int main(void) {
    char str[3] = "Hi";
    char c[2] = "L";
    swapToBack(str, c);
    printf("%s and %s", c, str);

    char str2[9] = "macaroni";
    strSort(str2);
    printf("\n%s", str2);
}

void swapToFront(char str[], char *c) {
    char dummy = str[0];
    str[0] = *c;
    *c = dummy;
}

void swapToBack(char str[], char *c) {
    int length = strlen(str) - 1;

    swapToFront(&str[length], c);
}

char *select_max(char str[]) {
    int len = strlen(str);
    if (len < 1) {
        return NULL;
    }

    char *max = &str[0];
    for (int i = 1; i < len; i++) {
        if (*max < str[i]) {
            max = &str[i];
        }
    }

    return max;
}

void strSort(char str[]) {
    int len = strlen(str) - 1;

    for (int i = 0; i < len; i++) {
        swapToFront(select_max(&str[i]), &str[i]);
    }
}