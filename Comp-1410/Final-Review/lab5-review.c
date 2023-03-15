#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[20];
} Student;

bool findID (int id, Student arr[], int n, char *found_name);

int findName (char *name, Student arr[], int n, char *found_name);

void changeName (char *name, Student arr[], char *new_name);

int main(void) {
    Student arr[] = {
        {1234567, "Edward"},
        {1235435, "Brandon"},
        {7272727, "Evan"}
    };
}

bool findID (int id, Student arr[], int n, char *found_name) {

}