#include <stdio.h>
#include <math.h>

long int binaryCalc(int num);
int num;

int main ( void ){
    puts("Enter a number: ");
    scanf("%d", &num);
    printf("%d in binary is %ld\n", num,binaryCalc(num));
}

long int binaryCalc(int num){
    long int binary = 0;
    int j;
    for (int i=0; pow(2,i)<=num; i++){
        j=i;
    }
    for (j; j>=0; j--){

        if ((num-pow(2,j)>=0)){
            binary = (binary*10)+1;
            num = num - pow(2,j);
        }
        else if (num-pow(2,j)<0){
            binary = binary*10;
        }
    }

    return binary;
}