#include <stdio.h>

int main(void) {
    //Variables
    int L, M, R, stID, alterID;
    int num1=0, num2=0, num3=0, num4=0, num5=0, num6=0, num7=0, num8=0, num9=0;
    int check = 1;
    int altL, altM, altR;
    int altS=0, S=0, hash=0;

    puts("Please enter your student ID number: ");
    scanf("%d", &stID);

    alterID = stID;

    //Assignment of each digit to a variable without the use of a loop
    num1 = alterID % 10;
    alterID = alterID / 10;

    num2 = alterID % 10;
    alterID = alterID / 10;

    num3 = alterID % 10;
    alterID = alterID / 10;

    num4 = alterID % 10;
    alterID = alterID / 10;

    num5 = alterID % 10;
    alterID = alterID / 10;

    num6 = alterID % 10;
    alterID = alterID / 10;

    num7 = alterID % 10;
    alterID = alterID / 10;
    
    num8 = alterID % 10;
    alterID = alterID / 10;

    num9 = alterID % 10;
    alterID = alterID / 10;

    //Summation of each digits in L, M, R
    L = num9 + num8 + num7;
    M = num6 + num5 + num4;
    R = num3 + num2 + num1;
    //Checking to make sure that there is no L, M, or R that is greater than 9
    while (check == 1) {
        if (L > 9) {
            altL = L % 10;
            L = L / 10;
            L = L + altL;
        }
        if (M > 9) {
            altM = M % 10;
            M = M / 10;
            M = M + altM;
        }
        if (R > 9) {
            altR = R % 10;
            R = R / 10;
            R = R + altR;
        }
        if (L && M && R < 9) {
            check = 0;
        }
        else {
            check = 1;
        }
    }
    //Summation of L, M, R stored in S
    S = L + M + R;
    check = 1;
    while (check == 1) {
        if (S > 9) {
            altS = S % 10;
            S = S / 10;
            S = S + altS;
        }
        else {
            check = 0;
        }
    }

    hash = M * 1000 + S * 100 + L * 10 + R;
    printf("The hash value of your ID(%d) is %d", stID, hash);
}