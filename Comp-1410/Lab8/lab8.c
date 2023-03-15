/* ===========================================================================
COMP-1410 Lab 8 - Edward Nafornita (110076381)
=========================================================================== */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// Tree node storing a string of length at most 9
struct node {
    char str[10];
    struct node *left;
    struct node *right;
};

// create_node(str, left, right) creates and returns a tree node containing
//   given str and left/right pointers; caller must free allocated memory
// requires: left, right are NULL or point to tree nodes
// note: returns NULL if memory cannot be allocated
struct node *create_node(char str[], struct node *left, struct node *right) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    if (new_node == NULL) {
        return NULL;
    }
    
    strcpy(new_node -> str, str);
    new_node -> left = left;
    new_node -> right = right;

    return new_node;
}

// free_tree(root) frees the memory associated with the given root node and
//   all of the node's children
// requires: root is NULL or the root of a tree allocated dynamically
void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    
    free_tree(root -> left);
    free_tree(root -> right);
    free(root);
}

// print_tree(root) prints the contents of the tree using an in-order traversal
// requires: root is NULL or points to a valid tree root node
void print_tree(struct node *root) {
    if (root == NULL) {
        return;
    }

    print_tree(root -> left);
    printf("%s ", root -> str);
    print_tree(root -> right);
}

// height(root) returns the height of the tree with given root
// requires: root is NULL or points to a valid tree root node
int height(struct node *root) {
    if (!root) return 0;

    int left_height = height(root -> left);
    int right_height = height(root -> right);

    if (left_height >= right_height) return left_height + 1;
    return right_height + 1;
}

// concat_leaves(root, str) modifies str to be a string concatenation of the
//   leaf nodes of the tree with given root using an in-order traversal;
//   returns the length of the concatenated string
// requires: str points to enough memory to store the output string
//           root is NULL or points to a valid tree root node
int concat_leaves(struct node *root, char *str) {
    int len = 0;
    
    if (!root) return 0;

    len += concat_leaves(root -> left, str + len);

    if (!(root -> left) && !(root -> right)) {
        if (*(root -> str + i) != '\0') {
            *(str + len) = *(root -> str + i);
            len++;
        }
        else {
            *(str + len) = '\0';
            break;
        }
    }
    return 1;
}

int main(void) {
    char food[10] = "food";
    char meat[10] = "meat";
    char fruit[10] = "fruit";
    char apple[10] = "apple";
    char pear[10] = "pear";

    struct node *meat_node = create_node(meat, NULL, NULL);
    struct node *apple_node = create_node(apple, NULL, NULL);
    struct node *pear_node = create_node(pear, NULL, NULL);
    struct node *fruit_node = create_node(fruit, apple_node, pear_node);
    struct node *food_node = create_node(food, meat_node, fruit_node);

    print_tree(food_node);
    printf("\nThe height of the tree is: %d\n", height(food_node));
    free_tree(food_node);
}