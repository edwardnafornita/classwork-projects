#include <stdio.h>
#include <math.h>

int main(void) {
    char varInput;
    float a=0.0, b=0.0, c=0.0, d=0.0, e=0.0;
    float array[5] = {a,b,c,d,e};
    float value = 0.0;
    
    for (int i=0; i<5; i++) {
        puts("Enter a value:");
        scanf("%f", &value);
        array[i] = value;
    }
    for (int i=0; i<5; ++i) {
        printf("%.1f", array[i]);
    }

}


case 'A':
case 'a':
case 'B':
case 'b':
case 'C':
case 'c':
case 'D':
case 'd':
case 'E':
case 'e':