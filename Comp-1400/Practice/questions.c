#include <stdio.h>

int main() {
    printf("My Name is: Your Name\n");
    printf("**********\n");
    printf("Please enter 10 integer numbers seperated by comma, press \"Enter\" after that: \n");
    int arr[30];
    int sum=1;
    for (int i=0; i < 10; i++) {
        scanf("%d, ", &arr[i]);
    }
    printf("**********\n");
    for (int i=1; i < 10; i++) {
        if ((i%2==1)&&(arr[i]%2==0)&&(arr[i]!=0)) {
            sum *= arr[i];
        }
    }

    printf("The output is: %d\n", sum);
    printf("**********\n");
}