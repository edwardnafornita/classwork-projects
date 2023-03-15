/* ===========================================================================
COMP-1410 Lab 5 - Edward Nafornita (110076381)
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Definition of structure for storing student information
struct student {
    int id;
    char name[20];
};

// find_id(id, arr, n, found_name) searches for a student with given id in arr;
//   returns true if such a student is found and found_name is updated to
//   hold the student's name; otherwise returns false
// requires: arr has length n
//           students in arr have unique ids
//           found_name points to enough memory to hold a name
bool find_id(int id, struct student arr[], int n, char *found_name);

// find_name(name, arr, n, ids) searches for student(s) with given name in arr;
//   returns the number of students found and the array ids is updated to
//   contain the id numbers of those students
// requires: arr has length n
//           students in arr have unique ids
//           ids points to enough memory to hold the found student ids
int find_name(char *name, struct student arr[], int n, int ids[]);

// change_name(s, new_name) renames the student s to have the name given by
//   new_name
// requires: s points to a valid student that can be modified
//           new_name points to a valid string of length at most 19
void change_name(struct student *s, char *new_name);

int main(void) {
    struct student arr[] = {
        {123456, "Billy"}, 
        {98763234, "Phill"},
        {32132132, "Bobby"}, 
        {7777777, "Phill"}, 
        {4637568, "Eden"},
        {7843785, "Phill"}
    };

    char *found_name;
    int ids[6] = {0, 0, 0, 0, 0};

    char name_to_find[6] = "Phill";
    int check = find_name(&name_to_find[0], &arr[0], 6, &ids[0]);
    assert(check == 3);
    printf("The IDS for the students named '%s' are: \n", name_to_find);
    for (int i = 0; i < 6; i++) {
        if (ids[i] != '\0') {
            printf("%d\n", ids[i]);
        }
    }

    char name_change[4] = "Bob";
    change_name(&arr[2], &name_change[0]);
    assert(strcmp(arr[2].name, name_change) == 0);

    printf("Assertions passed!\n");
}

bool find_id(int id, struct student arr[], int n, char *found_name) {
    for (int i = 0; i < n; i++) {
        if (id == arr[i].id) {
            strcpy(found_name, arr[i].name);
            return true;
        }
    }

    return false;
}

int find_name(char *name, struct student arr[], int n, int ids[]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            count++;
            ids[i] = arr[i].id;
        }
    }

    return count;
}

void change_name(struct student *s, char *new_name) {
    strcpy(s -> name, new_name);
}
