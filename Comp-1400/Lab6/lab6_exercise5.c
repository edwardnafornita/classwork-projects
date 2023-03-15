#include <stdio.h>

int main(void) {
    int num, day, count=1;
    puts("Please enter a number between 1 and 7: ");
    scanf("%d", &num);
    
    switch(num) {
        case 1:
            printf("The %dst day of the week is Monday.", num);
            break;
        case 2:
            printf("The %dnd day of the week is Tuesday.", num);
            break;
        case 3:
            printf("The %drd day of the week is Wednesday.", num);
            break;
        case 4:
            printf("The %dth day of the week is Thursday.", num);
            break;
        case 5:
            printf("The %dth day of the week is Friday.", num);
            break;
        case 6:
            printf("The %dth day of the week is Saturday.", num);
            break;
        case 7:
            printf("The %dth day of the week is Sunday.", num);
            break;
        default:
            printf("Please enter a number between 1 and 7!");
    }

}