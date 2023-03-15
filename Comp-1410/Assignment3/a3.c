/* ===========================================================================
COMP-1410 Assignment 3
Credit to: Sarah Bellaire
April 15th, 2022
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked list node that holds a student record
struct snode {
    int id;
    char * name;
    struct snode * next;
};

// Student list structure
struct slist {
    struct snode * front;
};

// create_list() returns an empty newly-created list of students
// note: caller must free using free_list
struct slist * create_list();

// insert_student(id, name, lst) attempts to add a student with given id and
//   name into the given list lst; if a student with that id is already in the
//   list then return false, otherwise lst is modified and true is returned
bool insert_student(int id, char name[], struct slist * lst);

// remove_student(id, lst) attempts to remove a student with given id from the
//   given list and free the memory allocated to that student; true is returned
//   if successful and false otherwise
bool remove_student(int id, struct slist * lst);

// find_student(id, lst) returns the name of the student with given id in the
//   given list lst in a dynamically-allocated string (that the caller must
//   free) or NULL if no student has that id
char * find_student(int id, struct slist * lst);

// free_list (lst) deallocates all memory associated with the given list lst
//   including the memory used by the student records in the list
void free_list(struct slist * lst);

void print_lst(struct slist * lst);

// merge_lists(out, lst1, lst2) merges the student records from lst1 and lst2
//   into the list out with the students in sorted order;
//   lst1 and lst2 are then freed
// requires: out starts as an empty list
void merge_lists(struct slist * out, struct slist * lst1, struct slist * lst2);

// Tree node holding the numeric value that a word compresses to
struct treenode {
    char word[10];
    int value;
    struct treenode * left;
    struct treenode * right;
};

struct treenode * create_leaf(char word[], int value);

// insert_node(word, value, tree) inserts a new node containing the given word
//   and value into the tree with given root (or NULL denoting an empty tree)
//   returns the root node of the tree following the insert
// requires: word is not already in the given tree
//           tree satisfies the ordering property
struct treenode * insert_node(char word[], int value, struct treenode * tree);

// lookup_word(word, tree) returns the numeric value associated with the given
//   word in the given tree (or 0 if the word does not appear in the tree);
//   tree points to the root node or is NULL (denoting an empty tree)
// requires: tree satisfies the ordering property
int lookup_word(char word[], struct treenode * tree);

// free_tree(tree) frees all memory associated in the tree with given root node
void free_tree(struct treenode * tree);

// PART ONE

struct slist * create_list() {
    struct slist * lst = (struct slist *) malloc(sizeof(struct slist));

    if(lst == NULL) {                   // if memory allocation fails
        return NULL;
    }

    lst->front = NULL;
    return lst;
}

bool insert_student(int id, char name[], struct slist * lst) {
    struct snode * temp = lst->front;

    struct snode * student = (struct snode *) malloc(sizeof(struct snode));

    if(student == NULL) {               // if memory allocation fails
        return false;
    }

    if(name == NULL) {
        free(student);
        return false;
    }

    student->name = malloc((strlen(name) + 1) * sizeof(char));

    if(student->name == NULL) {         // if memory allocation fails
        free(student->name);
        free(student);

        return false;
    }

    if(lst->front == NULL) {
        lst->front = student;
        student->id = id;
        strcpy(student->name, name);
        student->next = NULL;

        return true;
    }

    while(temp != NULL) {
        if(temp->id == id) {            // if that student already exists
            free(student->name);
            free(student);
            
            return false;
        }
        else if(lst->front->id >= id) {
            student->next = lst->front;
            student->id = id;
            strcpy(student->name, name);
            lst->front = student;

            return true;
        }
        else if(id >= temp->id) {       // aaaaa
            student->next = temp->next; 
            temp->next = student;                      
            student->id = id;
            strcpy(student->name, name);

            return true;
        }
        else {
            temp = temp->next;
        }
    }
}

bool remove_student(int id, struct slist * lst) {
    struct snode * temp = lst->front;
    struct snode * oldFront = NULL;
    struct snode * oldTemp = NULL;

    if(temp == NULL) {          // if list is empty
        return false;
    }

    if(temp->id == id) {        // if the front is the one to be deleted
        oldFront = temp;
        lst->front = temp->next;
        free(oldFront->name);
        free(oldFront);
    }

    while(temp->next != NULL && temp->next->id != id) {
        temp = temp->next;
    }

    if(temp->next == NULL) {    // if the student doesn't exist
        return false;
    }

    oldTemp = temp->next;
    temp->next = temp->next->next;

    free(oldTemp->name);
    oldTemp->name = NULL;

    free(oldTemp);
    oldTemp = NULL;    

    return true;
}

char * find_student(int id, struct slist * lst) {
    struct snode * temp = lst->front;

    while(temp != NULL) {
        if(temp->id == id) {
            return temp->name;
        }
        else {
            temp = temp->next;
        }
    }

    return NULL;
}

void print_lst(struct slist * lst) {
    struct snode * temp = lst->front;

    while(temp != NULL) {
        if(temp->next == NULL) {
            printf("%d\n", temp->id);
            break;
        }
        printf("%d -> ", temp->id);
        temp = temp->next;
    }
}

void free_list(struct slist * lst) {
    struct snode * start = lst->front;
    struct snode * temp = NULL;

    if(lst != NULL) {
        while(start != NULL) {
            temp = start;
            start = start->next;

            temp->next = NULL;
            free(temp->name);

            free(temp);
            temp = NULL;
        }

        lst->front = NULL;
        free(lst);
        lst = NULL;
    }
}

void merge_lists(struct slist * out, struct slist * lst1, struct slist * lst2) {
    struct snode * temp1 = lst1->front;
    struct snode * temp2 = lst2->front;

    struct snode * outNode = NULL;
    struct snode * lastNode = NULL;

    if(temp1 == NULL && temp2 == NULL) {
        out->front = NULL;

        temp1 = NULL;
        temp2 = NULL;
    }
    else if(temp1 == NULL) {     // if list1 is empty, return list2 as out
        out->front = temp2;

        temp1 = NULL;
        temp2 = NULL;
    }
    else if(temp2 == NULL) {    // if list2 is empty, return list1 as out
        out->front = temp1;

        temp1 = NULL;
        temp2 = NULL;
    }

    while(temp1 != NULL || temp2 != NULL) {
        if(temp1 == NULL) {
            outNode = temp2;
        }
        else if(temp2 == NULL) {
            outNode = temp1;
        }
        else {
            if(temp1->id < temp2->id) {     // ensure sorting property
                outNode = temp1;
            }
            else if(temp1->id >= temp2->id){
                outNode = temp2;
            }
        }

        // traverse through the list's nodes
        if(outNode == temp1) {
            temp1 = temp1->next;
        }
        else if(outNode == temp2) {
            temp2 = temp2->next;
        }

        if(lastNode == NULL) {    // if out is empty
            out->front = outNode;      
        }
        else {
            lastNode->next = outNode;
        }

        outNode->next = NULL;
        lastNode = outNode;
    }

    free(lst1);
    free(lst2);
}

bool sorted_list(struct slist * lst) {
    if(lst == NULL) {   // if list is empty, return NULL right away
        return true;
    }

    struct snode * temp = lst->front;
    struct snode * temp_next = temp->next;

    if(lst->front == NULL) {
        return true;
    }

    while(temp != NULL && temp_next != NULL) {
        if(temp->id > temp_next->id) {  // if increasing order isn't followed
            return false;
        }

        temp = temp->next;
        temp_next = temp_next->next;
    }

    return true;
}

// PART 2

struct treenode * create_leaf(char word[], int value) {
    struct treenode * new_leaf = (struct treenode *) malloc(sizeof(struct treenode));

    if(new_leaf == NULL) {      // if memory allocation fails
        return NULL;
    }

    new_leaf->left = NULL;
    new_leaf->right = NULL;
    new_leaf->value = value;
    strcpy(new_leaf->word, word);

    return new_leaf;
}

struct treenode * insert_node(char word[], int value, struct treenode * tree) {    
    int i = 0;

    if(tree == NULL) {
        return create_leaf(word, value);
    }

    while(i < 10) {                     // while the char is still in the word
        // handle the alphabetical order
        if(word[i] < tree->word[i]) {   
            if(tree->left == NULL) {    // if we reach space for a leaf
                tree->left = create_leaf(word, value);
                return tree->left;
            }
            else {                      // otherwise, keep recursing until we find space
                return insert_node(word, value, tree->left);
            }
        }
        else if(word[i] > tree->word[i]) {
           if(tree->right == NULL) {
                tree->right = create_leaf(word, value);
                return tree->right;
            }
            else {
                return insert_node(word, value, tree->right);
            } 
        }
        else {  // if the char's equal one another
            i ++;
        }
    }
    return NULL;
}

int lookup_word(char word[], struct treenode * tree) {
    int leftVal = 0;
    int rightVal = 0;

    if(tree == NULL) {      // if tree is empty
        return 0;
    }

    if(strcmp(word, tree->word) == 0) { // check if it's the word before traversing
        return tree->value;
    }
    
    if(tree->left != NULL) {   
        leftVal = lookup_word(word, tree->left);    
        if(leftVal != 0) {
            return leftVal;
        }
    }        

    if(tree->right != NULL) {
        rightVal = lookup_word(word, tree->right);
        if(rightVal != 0) {
            return rightVal;
        }
    }

    return 0;

}

void print_tree(struct treenode * root) {
    if(root == NULL) {
        return;
    }

    print_tree(root->left);
    printf("%s, %d\n", root->word, root->value);
    print_tree(root->right);
}

void free_tree(struct treenode * tree) {
    if(tree == NULL) {
        return;
    }

    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

int main(void) {
    // PART ONE

    struct slist * lst1 = create_list();
    struct slist * lst2 = create_list();
    struct slist * out1 = create_list();

    assert(insert_student(110076263, "Sarah", lst1) == true);
    assert(lst1->front != NULL);
    assert(lst1->front->next == NULL);
    assert(strcmp(lst1->front->name, "Sarah") == 0);
    assert(lst1->front->id == 110076263);
    assert(strcmp(find_student(110076263, lst1), "Sarah") == 0);  

    assert(insert_student(3748348, "Harold", lst1) == true);
    assert(strcmp(lst1->front->name, "Harold") == 0);
    assert(strcmp(lst1->front->next->name, "Sarah") == 0);

    assert(remove_student(110076263, lst1) == true);
    assert(find_student(110076263, lst1) == NULL);

    merge_lists(out1, lst1, lst2);
   
    assert(sorted_list(out1) == true);
    assert(out1->front != NULL);
    assert(out1->front->id == 3748348);
    assert(strcmp(out1->front->name, "Harold") == 0);

    free_list(out1);

    struct slist * out2 = NULL;
    assert(sorted_list(out2) == true);

    struct slist * out3 = create_list();
    assert(insert_student(110076263, "Sarah", out3) == true);
    assert(insert_student(1234567, "Kate", out3) == true);
    assert(insert_student(123, "Bellaire", out3) == true);
    assert(insert_student(89854, "Taylor", out3) == true);
    assert(insert_student(63463, "Ron", out3) == true);
    assert(insert_student(1234, "Cam", out3) == true);
    
    assert(sorted_list(out3) == true);
    print_lst(out3);

    free_list(out3);

    struct slist * lst3 = create_list();
    struct slist * lst4 = create_list();
    struct slist * out4 = create_list();

    assert(insert_student(110076263, "Sarah", lst3) == true);
    assert(insert_student(1234567, "Kate", lst3) == true);
    assert(insert_student(123, "Bellaire", lst3) == true);

    assert(insert_student(584694, "Evan", lst4) == true);
    assert(insert_student(12, "Bryan", lst4) == true);
    assert(insert_student(1, "Julia", lst4) == true);

    print_lst(lst3);
    print_lst(lst4);

    merge_lists(out4, lst3, lst4);
    assert(sorted_list(out4)==true);
    print_lst(out4);

    // PART TWO

    bool valInput = true;
    char input[10] = "";

    struct treenode * root2 = NULL;
    int value = 0;

    
    do {
        puts("Please enter your sentence here: ");
        scanf("%s", input);

        if(strcmp(input, ".") == 0) {   // end program when user enters a single period
            valInput = false;
            puts("Goodbye!");
        }
        else {
            if(root2 == NULL) {         // for the first node
                value ++;
                root2 = insert_node(input, value, root2);
                printf("%s is now in the tree.\n", input);
            }
            else if(lookup_word(input, root2) != 0) {       // if word exists in the tree
                printf("This word is already in the tree. It's numeric value is: %d\n", lookup_word(input, root2));
            }
            else {                      // if word isn't in the tree and it's non-root
                value ++;
                insert_node(input, value, root2);
                printf("%s is now in the tree.\n", input);
            }
        }
    }
    while(valInput != false);

    print_tree(root2);
    free_tree(root2);

    struct treenode * root1 = NULL;
    root1 = insert_node("Sarah", 1, root1);
    insert_node("Bellaire", 2, root1);
    insert_node("Zebra", 3, root1);
    insert_node("Aang", 4, root1);
    insert_node("Under", 5, root1);

    assert(lookup_word("Sarah", root1) == 1);
    assert(lookup_word("Bellaire", root1) == 2);
    assert(lookup_word("Zebra", root1) == 3);
    assert(lookup_word("Aang", root1) == 4);
    assert(lookup_word("Zebra", root1) == 3);
    assert(lookup_word("Under", root1) == 5);

    assert(lookup_word("mklsgl", root1) == 0);

    print_tree(root1);
    free_tree(root1);

    struct treenode * root3 = NULL;
    assert(lookup_word("Sarah", root3) == 0);

    print_tree(root3);
    free_tree(root3);

    struct treenode * root4 = NULL;
    root4 = insert_node("Sarah", 1, root4);
    assert(lookup_word("Sarah", root4) == 1);
    assert(lookup_word("Bellaire", root4) == 0);

    print_tree(root4);
    free_tree(root4);

    puts("All tests passed successfully.");
}