#include <stdio.h>
int main(void) {
   int count, num, rows;
   puts("Please enter the number of rows you want to display: ");
   scanf("%d", &rows);

   for (count=1; count <= rows; count++) {
    for(num=1; num <= count; num++) {
	   printf("*");
    }
	printf("\n");
   }
}