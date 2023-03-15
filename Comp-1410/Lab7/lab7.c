/* ===========================================================================
COMP-1410 Lab 7 - Edward Nafornita (110076381)
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// Linked list node storing a string of at most 4 characters
struct strnode {
    char str[5];
    struct strnode *next;
};

// create_node(str, next) creates a strnode containing the string str
//  and given next pointer; caller must free allocated memory using free_node
// requires: str has length at most 4
//          next is NULL or points to a strnode
// note: returns NULL if memory cannot be allocated
struct strnode *create_node(char str[], struct strnode *next) {
    struct strnode *new_node = (struct strnode *)malloc(sizeof(struct strnode));

    if (new_node == NULL) {
        return NULL;
    }

    strcpy(new_node -> str, str);
    new_node -> next = next;
    return new_node;
}

// free_node(node) frees the memory associated with the given node; returns a
//  pointer to the next node in the list previously headed by the given node
// requires: node is a valid strnode allocated dynamically
struct strnode *free_node(struct strnode *node) {
    struct strnode *next_node = node -> next;
    free(node);
    return next_node;
}

// concat_nodes(head, str) modifies str to be a string representation of the
//  contents of the list with given head
// requires: str points to enough memory to store the output string
//          head is NULL or points to a strnode
void concat_nodes(struct strnode *head, char *str) {
    while (head -> next != NULL) {
        strcat(str, head -> str);
        head = head -> next;
        
        if (head -> next != NULL) {
            strcat(str, " ");
        }
    }
}

int main(void) {
    char str[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    struct strnode *next_node = NULL;
    struct strnode *init_node = NULL;
    char null[2] = "";

    for (int i = 0; i <= 26; i++) {
        null[0] = str[26 - i];
        init_node = create_node(null, next_node);
        next_node = init_node;
    }

    char concat_llist[100] = "";
    char concat_expected[] = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
    concat_nodes(next_node, &concat_llist[0]);
    assert(strcmp(concat_expected, concat_llist) == 0);
    printf("%s\n", concat_llist);

    while (next_node != NULL) {
        next_node = free_node(next_node);
    }

    char str2[9] = "ehbeesea";
    struct strnode *next_node2 = NULL;
    struct strnode *init_node2 = NULL;
    char null2[2] = "";

    for (int i = 0; i <= 9; i++) {
        null2[0] = str2[9 - i];
        init_node2 = create_node(null2, next_node2);
        next_node2 = init_node2;
    }

    char concat_llist2[100] = "";
    char concat_expected2[] = "e h b e e s e a ";
    concat_nodes(next_node2, &concat_llist2[0]);
    assert(strcmp(concat_expected2, concat_llist2) == 0);
    printf("%s\n", concat_llist2);

    while (next_node2 != NULL) {
        next_node2 = free_node(next_node2);
    }

    char str3[2] = "";
    struct strnode *next_node3 = NULL;
    struct strnode *init_node3 = NULL;
    char null3[2] = "";

    for (int i = 0; i <= 2; i++) {
        null2[0] = str3[2 - i];
        init_node3 = create_node(null3, next_node3);
        next_node3 = init_node3;
    }

    char concat_llist3[100] = "";
    char concat_expected3[] = "";
    concat_nodes(next_node3, &concat_llist2[0]);
    assert(strcmp(concat_expected3, concat_llist3) == 0);
    printf("%s\n", concat_llist3);

    while (next_node3 != NULL) {
        next_node3 = free_node(next_node3);
    }

    puts("All tests passed successfully!");
}