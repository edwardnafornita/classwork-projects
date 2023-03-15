#include <stdio.h>
#include <string.h>

struct simpleNode {
    int val;
    struct simpleNode *next;
};

void encodeDNA (int size, char dna[]);

int countOdd (struct simpleNode *head);

int countOddRec (struct simpleNode *head);

int main(void) {

}

void encodeDNA (int size, char dna[]) {
    char pivot = dna[0];
    int count = 1;

    for (int i = 0; i < size - 1; i++) {
        if (dna[i] == dna[i + 1]) {
            count++;
        }
        else {
            if (count <= 1) {
                printf("%c", pivot);
            }
            else {
                printf("%c%d", pivot, count);
            }
            pivot = dna[i + 1];
            count = 1;
        }
    }
    puts("");
}

int countOdd (struct simpleNode *head) {
    int count = 0;

    while (head != NULL) {
        if (head -> value % 2) {
            count++;
        }
        head = head -> next;
    }

    return count;
}

int countOddRec (struct simpleNode *head) {
    if (head == NULL) {
        return 0;
    }

    return head -> value % 2 + countOddRec(head -> next);
}