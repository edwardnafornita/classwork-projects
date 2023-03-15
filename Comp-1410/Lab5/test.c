#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

struct student {
    int id; 
    char name[20];
};

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

int main(void) {
    struct student arr[] = {
        {785438678, "John"},
        {584952314, "Bob"},
        {986543784, "Henry"},
        {578943565, "Thomas"},
        {437854334, "Henry"}
    };

    int ids[5] = {0, 0, 0, 0, 0};
    char name[6] = "Henry";

    int dummy = find_name(&name[0], &arr[0], 5, &ids[0]);
    assert(dummy == 2);
    // for (int i = 0; i < 5; i++) {
    //     if (ids[i] != '\0') {
    //         printf("%d\n", ids[i]);
    //     }
    // }

}