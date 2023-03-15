#include <stdio.h>
#include <ctype.h>

int charToNum(char c[], int size);
char numToChar(int n, char c[]);


int main(void) {
    int size = 6;
    char temp;
    char c[size];
    puts("Guideline: Z=0, O=1, T=2, H=3, F=4, V=5, X=6, S=7, E=8, N=9");
    puts("Enter the first set of characters (6): ");
    for (int i=0; i < size; i++) {
        scanf(" %c", &temp);
        temp = toupper(temp);
        c[i] = temp;
    }

    printf("Characters to numbers: %d", charToNum(c, size));

    puts("Enter the second set of characters (6): ");
}

int charToNum(char c[], int size) {
    int i[size];
    int charToNumValues=0;
    for (int j=0; j < size; j++) {
        switch(c[j]) {
            case 'Z':
                i[j] = 0;
                break;
            case 'O':
                i[j] = 1;
                break;
            case 'T':
                i[j] = 2;
                break;
            case 'H':
                i[j] = 3;
                break;
            case 'F':
                i[j] = 4;
                break;
            case 'V':
                i[j] = 5;
                break;
            case 'X':
                i[j] = 6;
                break;
            case 'S':
                i[j] = 7;
                break;
            case 'E':
                i[j] = 8;
                break;
            case 'N':
                i[j] = 9;
                break;
        }
    }

    for (int j = 1; j < size; j++) {
        charToNumValues = charToNumValues + i[j];
        charToNumValues = charToNumValues * 10;
    }
    return charToNumValues;
}

char charToNum(int n, char c[]) {

}