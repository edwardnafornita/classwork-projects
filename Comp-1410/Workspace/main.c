#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

struct student {
    int id; 
    char name[20];
};

int main(void) {
    struct student s1 = {123456, "John"};

    printf("%s has an ID of %d.\n", s1.id, s1.name);
}

