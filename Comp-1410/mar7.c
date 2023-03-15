#include <stdio.h>
#include <assert.h>


// my_strcmp(s1, s2) returns negative if s1 < s2
//  returns 0 if s1 = s2 (as strings)
//  returns positive if s1 > s2
int my_strcmp(char s1[], char s2[]) {
    int i = 0;

    while (1) {
        if (s1[i] < s2[i]) {
            return -1;
        }

        if (s1 [i] > s2[i]) {
            return 1;
        }
        
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 0;
        }

        i++;
    }
}

int main(void) {

    assert(my_strcmp("a", "b") < 0);
    assert(my_strcmp("b", "a") > 0);
    assert(my_strcmp("a", "a") == 0);
    assert(my_strcmp("abc", "abc") == 0);
    assert(my_strcmp("abc", "abcabc") < 0);
    assert(my_strcmp("abcabc", "abc") > 0);
    assert(my_strcmp("", "") == 0);
    assert(my_strcmp("abcabc", "abcdbc") < 0);
    
}