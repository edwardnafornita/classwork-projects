/* ============================================================================
COMP-1410 Lab 6 - Edward Nafornta (110076381)
============================================================================ */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of structure for storing student information
struct student {
    int id;
    char *name;
};

// create_student(id, name) creates a new student record with given id and name;
//  allocates memory to store structure and name (must free with free_student)
//  and returns NULL if memory allocation fails
// requires: name points to a valid string
struct student *create_student(int id, char *name) {
   struct student * s = (struct student *)malloc(sizeof(struct student));
    if (s == NULL) {
        return NULL;
    }
    s -> id = id;

    if (name == NULL) {
        free(s);
        return NULL;
    }
    s -> name = (char *)malloc((strlen(name) + 1) * sizeof(char));

    if (s -> name == NULL) {
        s -> name = NULL;
    } 
    else {
        strcpy(s -> name, name);
    }
    return s;
}

// change_name(s, new_name) renames the student s to have the name given by
//   new_name; allocates memory to hold new_name (must free with free_student)
//   returns true when the name was successfully changed
// requires: s points to a valid student and new_name points to a valid string
bool change_name(struct student *s, char *new_name) {
    s -> name = (char *)realloc(s -> name, ((strlen(new_name) + 1) * sizeof(char)));

    if (s == NULL) {
        free(s -> name);
        return false;
    }

    if (s -> name == NULL || new_name == NULL) {
        free(s -> name);
        return false;
    }
    else {
        strcpy(s -> name, new_name);
        return true;
    }
}

// free_student(s) frees the memory associated with the student record s
// requires: s is a student record created using dynamic memory allocation
void free_student(struct student *s) {
    free(s -> name);
    free(s);
}

int main(void) {
    int id = 110084783;
    char *name = "Robert";
    struct student * s1 = create_student(id, name);
    printf("The first Student's name, and ID are: %s, %d\n", s1 -> name, s1 -> id);
    
    char *new_name = "Rob";
    assert(change_name(s1, new_name) == true);
    assert(strcmp(s1 -> name, new_name) == 0);
    printf("The first Student's name is now: %s\n", s1 -> name);
    free_student(s1);

    int id2 = 110076381;
    char *name2 = "Edward Nafornita";
    struct student *s2 = create_student(id2, name2);
    printf("The second Student's name, and ID are: %s, %d\n", s2 -> name, s2 -> id);

    char *new_name2 = "Eddie";
    assert(change_name(s2, new_name2) == true);
    assert(strcmp(s2 -> name, new_name2) == 0);
    printf("The second Student's name is now: %s\n", s2 -> name);
    free_student(s2);

    int id3 = 110012312;
    char *name3 = "Jonathan";
    struct student *s3 = create_student(id3, name3);
    printf("The third Student's name, and ID are: %s, %d\n", s3 -> name, s3 -> id);

    char *new_name3 = "Jonny";
    assert(change_name(s3, new_name3) == true);
    assert(strcmp(s3 -> name, new_name3) == 0);
    printf("The third Student's name is now: %s\n", s3 -> name);
    free_student(s3);

    printf("All tests passed successfully\n");
}