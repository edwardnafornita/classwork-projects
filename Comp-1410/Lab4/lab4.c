/* ===========================================================================
COMP-1410 Lab 4 - Edward Nafornita
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>

// swap_to_front(str, c) swaps the last character in the string str with the
//   character pointed to by c
// requires: str is a valid string that can be modified, length(str) >= 1
//           c points to a character in str
void swap_to_front(char str[], char * c);

// swap_to_back(str, c) swaps the last character in the string str with the
//   character pointed to by c
// requires: str is a valid string that can be modified, length(str) >= 1
//           c points to a character in str
void swap_to_back(char str[], char * c);

// select_max(str) returns a pointer to the character of maximal ASCII value
//   in the string str (the first if there are duplicates)
// requires: str is a valid string, length(str) >= 1
char * select_max(char str[]);

// str_sort(str) sorts the characters in a string in decending order
// requires: str points to a valid string that can be modified
void str_sort(char str[]);

int main(void) {
    // Implement your test code here

    char str1[6] = "hello";
    assert(*select_max(str1) == 'o');
    str_sort(str1);
    assert(strcmp(str1, "ollhe") == 0);

    char str2[16] = "computerscience";
    assert(*select_max(str2) == 'u');
    str_sort(str2);
    assert(strcmp(str2, "utsrponmieeeccc") == 0);

    char str3[12] = "appocalypse";
    assert(*select_max(str3) == 'y');
    str_sort(str3);
    assert(strcmp(str3, "yspppolecaa") == 0);

    char str4[5] = "tech";
    assert(*select_max(str4) == 't');
    str_sort(str4);
    assert(strcmp(str4, "thec") == 0);
    
    char str5[7] = "bingus";
    assert(*select_max(str5) == 'u');
    str_sort(str5);
    assert(strcmp(str5, "usnigb") == 0);

    printf("All tests passed successfully.\n");   
}

void swap_to_front(char str[], char *c) {
    char temp = str[0];
    str[0] = *c;
    *c = temp;
}

void swap_to_back(char str[], char *c) {
    int i = 0;
    while (str[i + 1] != '\0') {
        str++;
    }

    char temp = str[0];
    str[0] = *c;
    *c = temp;
}

char *select_max(char str[]) {
    char *dummy = str;
    int n = strlen(str);

    if (n >= 1) {
        for (int i = 0; i < n; i++) {
            if (str[i] > *dummy) {
                dummy = &str[i];
            }
        }
    }

    return dummy;
}

void str_sort(char str[]) {
    int n = strlen(str) - 1;

    for (int i = 0; i < n; i++) {
        swap_to_front(select_max(&str[i]), &str[i]);
    }
}