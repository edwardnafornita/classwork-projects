#include <stdio.h>

int main(void) {
    int startData, alterData, endData, num=0, num1=0, num2=0, num3=0, num4=0, count=0;
    puts("Please enter a 4-digit integer: ");
    scanf("%d", &startData);

    alterData = startData;
    while (alterData > 0) {
        num = alterData % 10;
        num = (num + 7) % 10;
        count++;
        if (count == 1) {
            num4 = num;
        }
        else if (count == 2) {
            num3 = num;
        }
        else if (count == 3) {
            num2 = num;
        }
        else {
            num1 = num;
        }
        alterData = alterData / 10;
    }
    endData = (num3 * 1000) + (num4 * 100) + (num1 * 10) + (num2);
    printf("Data %d encrypted to %d", startData, endData);
}