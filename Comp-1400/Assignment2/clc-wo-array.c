//initialising required libraries 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//beginning main function
int main(void) {
    //welcome message
    puts("Welcome to my Command-Line Calculator (CLC)");
    puts("Developer: Edward Nafornita");
    puts("Version: 2, Assignment 2");
    puts("Date: November 2021");
    puts("----------------------------------------------------------------");

    //intialising required variables
    int start=1, bCheck=0, uCheck=0, vCheck=0, begin=1, aBegin=1, aStart=0, aIsNum=0, bIsNum=0, aIsVar=0, bIsVar=0, checkNum=0, numTwoCheck=0;
    float num=0.0, num1=0.0, num2=0.0, bResult=0.0, uResult=0.0, aBResult=0.0, aUResult=0.0;
    float a=0.0, b=0.0, c=0.0, d=0.0, e=0.0; //variables used in case v and a
    float varValues[5] = {0.0,0.0,0.0,0.0,0.0};
    char choice, aChoice, aSelect, op, var, varInput, varInputTwo, aStore, bStore;

    //full selection menu
    puts("Select one of the following items:");
    puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
    puts("U) - Unary Mathematical Operations, such as square root, and log.");
    puts("A) - Advanced Mathematical Operations, using variables, arrays.");
    puts("V) - Define variables and assign them values.");
    puts("X) - Exit"); 
    
    //beginning main loop
    while (start == 1) {
        if (begin == 1) {
            scanf(" %c", &choice); //writing the selection to a variable
            begin = 0;
        }
        else {
            puts("Please select your option (B - (Binary operation), U - (Unary operation) , A - (Advanced), V - (Variables), X - (Exit))");
            scanf(" %c", &choice); //writing the selection to a variable
        }
        
        //comprehending the selection
        switch(choice) {
            //binary mathematical operations
            case 'B':
            case 'b':
                puts("Please enter the first number:"); 
                scanf("%f", &num1); //reading the first number
                puts("Please enter the operation (+, -, *, /, %, ^)");
                scanf(" %c", &op); //reading the operation

                //checking for operator validity
                while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^') {
                    puts("Please enter a valid operation.");
                    puts("Please enter the operation (+, -, *, /, %, ^)");
                    scanf(" %c", &op); //reading the operation
                }

                //loop to validate the second number
                while(bCheck == 0) {
                    if (op == '/') { 
                        puts("Please enter the second number (non-zero):");
                        scanf("%f", &num2); //reading the second number for divison to make sure it's not zero

                        //checking for a division by zero
                        if (num2 == 0) {
                            bCheck = 0; //restarting loop
                        }
                        else {
                            bCheck = 1; //exiting loop
                        }
                    }
                    else {
                        puts("Please enter the second number:");
                        scanf("%f", &num2); //reading the second number for any operation
                        bCheck = 1; //exiting loop
                    }
                }
                bCheck = 0; //resets check loop

                //computing the different possible operations
                switch(op) {
                        case '+': //addition
                            bResult = num1 + num2;
                            break;
                        case '-': //subtraction
                            bResult = num1 - num2;
                            break;
                        case '*': //multiplication
                            bResult = num1 * num2;
                            break;
                        case '/': //division
                            bResult = num1 / num2;
                            break;
                        case '%': //remainder
                            bResult = fmod(num1, num2);
                            break;
                        case '^': //power
                            bResult = pow(num1, num2);
                            break;
                    }

                printf("The result is:\t\t%.2f\n", bResult); //displaying the result
                break;

            //unary mathematical operations
            case 'U':
            case 'u':
                puts("Please enter the operation (S - (for square root) , L - (for logarithm) , E - (for exponential) , C - (for ceil) , F - (for floor))");
                scanf(" %c", &op); //writing the selection to a variable

                //checking fro operation validity
                while ((op != 'S' && op != 's') && (op != 'L' && op != 'l') && (op != 'E' && op != 'e') && (op != 'C' && op != 'c') && (op != 'F' && op != 'f')) {
                    puts("Please enter a valid operation.");
                    puts("Please enter the operation (S - (for square root) , L - (for logarithm) , E - (for exponential) , C - (for ceil) , F - (for floor))");
                    scanf(" %c", &op); //writing the selection to a variable
                }

                //ensuring that the input for specific cases aren't mathematically invalid
                while (uCheck == 0) {
                    //cannot have a negative value when doing square root operations
                    if (op == 'S' || op == 's') {
                        puts("Enter a positive value:");
                        scanf("%f", &num1);

                        if (num1 < 0) {
                            uCheck = 0;
                        }
                        else {
                            uCheck = 1;
                        }
                    }
                    //cannot have values less than or equal to zero when doing logarithm operations
                    else if (op == 'L' || op == 'l') {
                        puts("Enter a non-zero positive value:");
                        scanf("%f", &num1);

                        if (num1 <= 0) {
                            uCheck = 0;
                        }
                        else {
                            uCheck = 1;
                        }
                    }
                    //read and writes the number that the user inputted
                    else {
                        puts("Please enter a number:");
                        scanf("%f", &num1);
                        uCheck = 1;
                    }
                }
                uCheck = 0; //resets check loop

                //calculates the different operations
                switch(op) {
                    case 'S':
                    case 's':
                        uResult = sqrtf(num1); //square root
                        break;
                    case 'L':
                    case 'l':
                        uResult = log10(num1); //base-10 logarithms
                        break;
                    case 'E':
                    case 'e':
                        uResult = exp(num1); //exponentials (e^x)
                        break;
                    case 'C':
                    case 'c':
                        uResult = ceil(num1); //ceiling
                        break;
                    case 'F':
                    case 'f':
                        uResult = floor(num1); //floor
                        break;
                }

                printf("The result is:\t\t%.2f\n", uResult); //displaying the result
                break;

            //advanced mathematical operations
            case 'A':
            case 'a':
                aIsNum = 0;
                aIsVar = 0;
                bIsNum = 0;
                bIsVar = 0;
                aStart = 0;
                puts("Select one of the following items:");
                puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
                puts("U) - Unary Mathematical Operations, such as square root, and log.");
                puts("X) - Exit and back to the main menu.");

                while (aStart == 0) {
                    if (aBegin == 1) {
                        scanf(" %c", &aChoice); //writing the selection to a variable
                        aBegin = 0;
                    }
                    else {
                        aBegin = 0;
                        puts("Please select your option (B - (Binary operation), U - (Unary operation), X - (Exit))");
                        scanf(" %c", &aChoice); //writing the selection to a variable
                    }
                    aBegin = 0;

                    switch (aChoice) {
                        case 'B':
                        case 'b':
                            puts("Please enter the first number or variable ('a' to 'e'):");
                            if (scanf("%f", &num1)) {
                                aIsNum = 1;
                            }
                            else {
                                aIsVar = 1;
                                scanf(" %c", &varInput);

                                while ((varInput != 'a' && varInput != 'A') && (varInput != 'b' && varInput != 'B') && (varInput != 'c' && varInput != 'C') && (varInput != 'd' && varInput != 'D') && (varInput != 'e' && varInput != 'E')) {
                                    puts("Please enter the first number or a variable ('a' to 'e'):");
                                    scanf(" %c", &varInput);
                                }

                                switch (varInput) {
                                    case 'A':
                                    case 'a':
                                        num1 = varValues[0];
                                        break;
                                    case 'B':
                                    case 'b':
                                        num1 = varValues[1];
                                        break;
                                    case 'C':
                                    case 'c':
                                        num1 = varValues[2];
                                        break;
                                    case 'D':
                                    case 'd':
                                        num1 = varValues[3];
                                        break;
                                    case 'E':
                                    case 'e':
                                        num1 = varValues[4];
                                        break;
                                }
                            }

                            puts("Please enter the operation (+, -, *, /, %, ^)");
                            scanf(" %c", &op); //reading the operation

                            //checking for operator validity
                            while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^') {
                                puts("Please enter a valid operation.");
                                puts("Please enter the operation (+, -, *, /, %, ^)");
                                scanf(" %c", &op); //reading the operation
                            }

                            while (checkNum == 0) {
                                if (op == '/') {
                                    bIsNum=0;
                                    bIsVar=0;
                                    puts("Please enter the second number or a variable ('a' to 'e'):");
                                    if (scanf("%f", &num2)) {
                                        bIsNum = 1;
                                        while (numTwoCheck == 0) {
                                            if (num2 == 0) {
                                                puts("Please enter the second number or a variable ('a' to 'e'):");
                                                scanf("%f", &num2);
                                            }
                                            else {
                                                numTwoCheck = 1;
                                                checkNum = 1;
                                            }
                                        }
                                    }
                                    else {
                                        bIsVar = 1;
                                        scanf(" %c", &varInputTwo);

                                        while ((varInputTwo != 'a' && varInputTwo != 'A') && (varInputTwo != 'b' && varInputTwo != 'B') && (varInputTwo != 'c' && varInputTwo != 'C') && (varInputTwo != 'd' && varInputTwo != 'D') && (varInputTwo != 'e' && varInputTwo != 'E')) {
                                            puts("Please enter the second number or a variable ('a' to 'e'):");
                                            scanf(" %c", &varInputTwo);
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                while (numTwoCheck == 0) {
                                                    if (varValues[0] == 0) {
                                                        puts("Please enter the second number or a variable ('a' to 'e'):");
                                                        scanf("%f", &num2);
                                                    }
                                                    else {
                                                        numTwoCheck = 1;
                                                        checkNum = 1;
                                                    }
                                                }
                                                break;
                                            case 'B':
                                            case 'b':
                                                while (numTwoCheck == 0) {
                                                    if (varValues[1] == 0) {
                                                        puts("Please enter the second number or a variable ('a' to 'e'):");
                                                        scanf("%f", &num2);
                                                    }
                                                    else {
                                                        numTwoCheck = 1;
                                                        checkNum = 1;
                                                    }
                                                }
                                                break;
                                            case 'C':
                                            case 'c':
                                                while (numTwoCheck == 0) {
                                                    if (varValues[2] == 0) {
                                                        puts("Please enter the second number or a variable ('a' to 'e'):");
                                                        scanf("%f", &num2);
                                                    }
                                                    else {
                                                        numTwoCheck = 1;
                                                        checkNum = 1;
                                                    }
                                                }
                                                break;
                                            case 'D':
                                            case 'd':
                                                while (numTwoCheck == 0) {
                                                    if (varValues[3] == 0) {
                                                        puts("Please enter the second number or a variable ('a' to 'e'):");
                                                        scanf("%f", &num2);
                                                    }
                                                    else {
                                                        numTwoCheck = 1;
                                                        checkNum = 1;
                                                    }
                                                }
                                                break;
                                            case 'E':
                                            case 'e':
                                                while (numTwoCheck == 0) {
                                                    if (varValues[4] == 0) {
                                                        puts("Please enter the second number or a variable ('a' to 'e'):");
                                                        scanf("%f", &num2);
                                                    }
                                                    else {
                                                        numTwoCheck = 1;
                                                        checkNum = 1;
                                                    }
                                                }
                                                break;
                                            default:
                                                num2 = varInputTwo;
                                                while (numTwoCheck == 0) {
                                                    if (num2 == 0) {
                                                        puts("Please enter the second number or a variable ('a' to 'e'):");
                                                        scanf("%f", &num2);
                                                    }
                                                    else {
                                                        bIsVar = 0;
                                                        bIsNum = 1;
                                                        numTwoCheck = 1;
                                                        checkNum = 1;
                                                    }
                                                }
                                                break;
                                        }
                                    }
                                }
                                else {
                                    bIsNum=0;
                                    bIsVar=0;
                                    puts("Please enter the second number or a variable ('a' to 'e'):");
                                    if (scanf("%f", &num2)) {
                                        bIsNum = 1;
                                        break;
                                    }
                                    else {
                                        scanf(" %c", &varInputTwo);
                                        bIsVar = 1;

                                        while ((varInputTwo != 'a' && varInputTwo != 'A') && (varInputTwo != 'b' && varInputTwo != 'B') && (varInputTwo != 'c' && varInputTwo != 'C') && (varInputTwo != 'd' && varInputTwo != 'D') && (varInputTwo != 'e' && varInputTwo != 'E')) {
                                            puts("Please enter the second number or a variable ('a' to 'e'):");
                                            scanf(" %c", &varInputTwo);
                                        }
                                        break;
                                    }

                                }
                            }
                            numTwoCheck = 0;
                            checkNum = 0;

                            switch (op) {
                                case '+':
                                    if (aIsNum == 1 && bIsNum == 1) {
                                        aBResult = num1 + num2;
                                    }
                                    else if (aIsNum == 1 && bIsVar == 1) {
                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                aBResult = num1 + varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = num1 + varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = num1 + varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = num1 + varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = num1 + varValues[4];
                                                break;
                                        }
                                    }
                                    else if (aIsVar == 1 && bIsNum == 1) {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aBResult = varValues[0] + num2;
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = varValues[1] + num2;
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = varValues[2] + num2;
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = varValues[3] + num2;
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = varValues[4] + num2;
                                                break;
                                        }
                                    }
                                    else {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aStore = varValues[4];
                                                break;
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                bStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                bStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                bStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                bStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                bStore = varValues[4];
                                                break;
                                        }
                                        aBResult = aStore + bStore;
                                    }
                                    break;
                                case '-':
                                    if (aIsNum == 1 && bIsNum == 1) {
                                        aBResult = num1 - num2;
                                    }
                                    else if (aIsNum == 1 && bIsVar == 1) {
                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                aBResult = num1 - varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = num1 - varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = num1 - varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = num1 - varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = num1 - varValues[4];
                                                break;
                                        }
                                    }
                                    else if (aIsVar == 1 && bIsNum == 1) {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aBResult = varValues[0] - num2;
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = varValues[1] - num2;
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = varValues[2] - num2;
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = varValues[3] - num2;
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = varValues[4] - num2;
                                                break;
                                        }
                                    }
                                    else {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aStore = varValues[4];
                                                break;
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                bStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                bStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                bStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                bStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                bStore = varValues[4];
                                                break;
                                        }
                                        aBResult = aStore - bStore;
                                    }
                                    break;
                                case '*':
                                    if (aIsNum == 1 && bIsNum == 1) {
                                        aBResult = num1 * num2;
                                    }
                                    else if (aIsNum == 1 && bIsVar == 1) {
                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                aBResult = num1 * varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = num1 * varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = num1 * varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = num1 * varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = num1 * varValues[4];
                                                break;
                                        }
                                    }
                                    else if (aIsVar == 1 && bIsNum == 1) {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aBResult = varValues[0] * num2;
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = varValues[1] * num2;
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = varValues[2] * num2;
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = varValues[3] * num2;
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = varValues[4] * num2;
                                                break;
                                        }
                                    }
                                    else {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aStore = varValues[4];
                                                break;
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                bStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                bStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                bStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                bStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                bStore = varValues[4];
                                                break;
                                        }

                                        aBResult = aStore * bStore;
                                    }
                                    break;
                                case '/':
                                    if (aIsNum == 1 && bIsNum == 1) {
                                        aBResult = num1 / num2;
                                    }
                                    else if (aIsNum == 1 && bIsVar == 1) {
                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                aBResult = num1 / varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = num1 / varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = num1 / varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = num1 / varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = num1 / varValues[4];
                                                break;
                                        }
                                    }
                                    else if (aIsVar == 1 && bIsNum == 1) {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aBResult = varValues[0] / num2;
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = varValues[1] / num2;
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = varValues[2] / num2;
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = varValues[3] / num2;
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = varValues[4] / num2;
                                                break;
                                        }
                                    }
                                    else {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aStore = varValues[4];
                                                break;
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                bStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                bStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                bStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                bStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                bStore = varValues[4];
                                                break;
                                        }

                                        aBResult = aStore / bStore;
                                    }
                                    break;
                                case '%':   
                                    if (aIsNum == 1 && bIsNum == 1) {
                                        aBResult = fmod(num1, num2);
                                    }
                                    else if (aIsNum == 1 && bIsVar == 1) {
                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                aBResult = fmod(num1, varValues[0]);
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = fmod(num1, varValues[1]);
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = fmod(num1, varValues[2]);
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = fmod(num1, varValues[3]);
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = fmod(num1, varValues[4]);
                                                break;
                                        }
                                    }
                                    else if (aIsVar == 1 && bIsNum == 1) {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aBResult = fmod(varValues[0], num2);
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = fmod(varValues[1], num2);
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = fmod(varValues[2], num2);
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = fmod(varValues[3], num2);
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = fmod(varValues[4], num2);
                                                break;
                                        }
                                    }
                                    else {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aStore = varValues[4];
                                                break;
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                bStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                bStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                bStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                bStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                bStore = varValues[4];
                                                break;
                                        }

                                        aBResult = fmod(aStore, bStore);
                                    }
                                    break;
                                case '^':
                                    if (aIsNum == 1 && bIsNum == 1) {
                                        aBResult = pow(num1, num2);
                                    }
                                    else if (aIsNum == 1 && bIsVar == 1) {
                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                aBResult = pow(num1, varValues[0]);
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = pow(num1, varValues[1]);
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = pow(num1, varValues[2]);
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = pow(num1, varValues[3]);
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = pow(num1, varValues[4]);
                                                break;
                                        }
                                    }
                                    else if (aIsVar == 1 && bIsNum == 1) {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aBResult = pow(varValues[0], num2);
                                                break;
                                            case 'B':
                                            case 'b':
                                                aBResult = pow(varValues[1], num2);
                                                break;
                                            case 'C':
                                            case 'c':
                                                aBResult = pow(varValues[2], num2);
                                                break;
                                            case 'D':
                                            case 'd':
                                                aBResult = pow(varValues[3], num2);
                                                break;
                                            case 'E':
                                            case 'e':
                                                aBResult = pow(varValues[4], num2);
                                                break;
                                        }
                                    }
                                    else {
                                        switch (varInput) {
                                            case 'A':
                                            case 'a':
                                                aStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                aStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                aStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                aStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                aStore = varValues[4];
                                                break;
                                        }

                                        switch (varInputTwo) {
                                            case 'A':
                                            case 'a':
                                                bStore = varValues[0];
                                                break;
                                            case 'B':
                                            case 'b':
                                                bStore = varValues[1];
                                                break;
                                            case 'C':
                                            case 'c':
                                                bStore = varValues[2];
                                                break;
                                            case 'D':
                                            case 'd':
                                                bStore = varValues[3];
                                                break;
                                            case 'E':
                                            case 'e':
                                                bStore = varValues[4];
                                                break;
                                        }

                                        aBResult = pow(aStore, bStore);
                                    }
                                    break;
                            }
                            printf("The result is:\t\t%.2f\n", aBResult);
                            break;
                        case 'U':
                        case 'u':
                        case 'X':
                        case 'x':
                            aStart = 1;
                            break;
                    }
                }
                break;
            //variable definition
            case 'V':
            case 'v':
                puts("Please enter the name of the variable (A single character between 'a' to 'e'):");
                scanf(" %c", &var); //writes the variable name to the variable named "var"

                //checks the validity of the name, between 'a' to 'e'
                while ((var != 'A' && var != 'a') && (var != 'B' && var != 'b') && (var != 'C' && var != 'c') && (var != 'D' && var != 'd') && (var != 'E' && var != 'e')) {
                    puts("Please enter the name of the variable (A single character between 'a' to 'e'):");
                    scanf(" %c", &var);
                }
                
                puts("Please a value to assign to the variable:");
                scanf("%f", &num); //writes the numerical value of a number to a variable named "num1"

                //assigns the numerical value to one of the designated variables between 'a' to 'e'
                switch (var) {
                    case 'A':
                    case 'a':
                        varValues[0] = num;
                        break;
                    case 'B':
                    case 'b':
                        varValues[1] = num;
                        break;
                    case 'C':
                    case 'c':
                        varValues[2] = num;
                        break;
                    case 'D':
                    case 'd':
                        varValues[3] = num;
                        break;
                    case 'E':
                    case 'e':
                        varValues[4] = num;
                        break;
                }

                //displays the value of the corrosponding variable
                printf("The variable %c is set to:\t%.2f\n", var, num);
                break;

            //exit case
            case 'X':
            case 'x':
                puts("Thanks for using my Simple Calculator. Hope to see you again, Goodbye!"); //displaying goodbye message
                start = 0; //stopping the main loop
                break;

            //if there's an invalid input
            default:
                printf("'%c' is not valid.\n", choice); //display error message if there's a wrong input
                break;
        }
    }
}
