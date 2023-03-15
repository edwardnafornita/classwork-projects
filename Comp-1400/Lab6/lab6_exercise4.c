#include <stdio.h>

int main(void) {
    int num, multiple, count=1, calc;
    puts("Please enter a number: ");
    scanf("%d", &num);

    while (count <= 10) {
        multiple = multiple + 1;
        calc = num * multiple;
        printf("%d X %d = %d\n", num, multiple, calc);
        count++;
    }
}