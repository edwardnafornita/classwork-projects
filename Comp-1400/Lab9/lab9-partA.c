/*
Assignment: Comp-1400 Lab 9
Developer: Edward Nafornita
Date: November 24th 2021
*/

// declaring necessary libraries
#include <stdio.h>
#include <math.h>

// function prototype for the areaOfCircle
double areaOfCircle(int r);

// declaring main function
int main(void) {
    int r=0;
    // receiving the value for the radius of the circle
    puts("Please enter a value for the radius of a circle: ");
    scanf("%d", &r);

    // displaying the value of the area of the circle
    printf("The area of the circle is %.2lf.", areaOfCircle(r));
}

// computing the area of the circle using the function
double areaOfCircle(int r) {
    double area=0;
    area = M_PI*pow(r, 2.0);
    return area;
}