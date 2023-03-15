//initialising required libraries
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char firstMainScreen(void);
char shortMainScreen(void);
char aScreen(void);
char aShortScreen(void);
char uScreen(void);
float bFunction(void);
float uFunction(void);
float bFunctionResult(float num1, float num2, char op);
float uFunctionResult(float num1, char op);
float caseA_GetVarOneValueB(float varValues[]);
float caseA_GetVarTwoValueB(float varValues[]);
float caseA_GetValueOneB(float varValues[]);
float caseA_GetValueTwoB(char op, float varValues[]);
float aFunctionBResult(float num1, float num2, char op);
float aFunctionUResult(char uOp, float varValues[]);
float aFunctionB(float varValues[]);
float aFunctionU(float varValues[]);
float aFunctionX(void);
float aFunction(float varValues[]);
void vFunction(float varValues[]);
int xFunction(void);
float getNumOne(void);
float getNumTwo(void);
float getNumOneU(char op);
char getOperationB(void);
char getOperationU(void);

int main(void) {
    float varValues[5];
    //welcome message
    puts("Welcome to my Command-Line Calculator (CLC)");
    puts("Developer: Edward Nafornita");
    puts("Version: 2, Assignment 2");
    puts("Date: 14th November 2021");
    puts("----------------------------------------------------------------");

    //intialising required variables
    int start=1, begin=1;
    char choice;

    while (start == 1) {
        if (begin == 1) {
            choice = firstMainScreen();
            begin = 0;
        }
        else {
            choice = shortMainScreen();
        }

        switch (choice) {
            case 'B':
                bFunction();
                break;
            case 'U':
                uFunction();
                break;
            case 'A':
                aFunction(varValues);
                break;
            case 'V':
                vFunction(varValues);
                break;
            case 'X':
                start = xFunction();
                break;
        }
    }
}

char firstMainScreen(void) {
    char choice;

    //full selection menu
    puts("Select one of the following items:");
    puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
    puts("U) - Unary Mathematical Operations, such as square root, and log.");
    puts("A) - Advanced Mathematical Operations, using variables, arrays.");
    puts("V) - Define variables and assign them values.");
    puts("X) - Exit");
    scanf(" %c", &choice);
    choice = toupper(choice);

    while(choice != 'B' && choice != 'U' && choice != 'A' && choice != 'V' && choice != 'X') {
        choice = shortMainScreen();
    }

    return choice;
}

char shortMainScreen(void) {
    char choice;

    do {
        puts("Please select your option (B - (Binary operation), U - (Unary operation) , A - (Advanced), V - (Variables), X - (Exit))");
        scanf(" %c", &choice); //writing the selection to a variable
        choice = toupper(choice);
    } while(choice != 'B' && choice != 'U' && choice != 'A' && choice != 'V' && choice != 'X');

    return choice;
}

float getNumOne(void) {
    float num1=0.0;
    scanf("%f", &num1); //reading the first number
    return num1;
}

float getNumTwo(void) {
    float num2=0.0; 
    scanf("%f", &num2); //reading the second number
    return num2;
}

// For Case B-----------------------------------------
char getOperationB(void) {
    char op;
    puts("Please enter the operation (+, -, *, /, %, ^)");
    scanf(" %c", &op); //reading the operation
    
    //checking for operator validity
    while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^') {
        puts("Please enter a valid operation.");
        puts("Please enter the operation (+, -, *, /, %, ^)");
        scanf(" %c", &op); //reading the operation
    }

    return op;
}

float bFunctionResult(float num1, float num2, char op) {
    float bResult=0.0;
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

    return bResult;
}

float bFunction(void) {
    float num1=0.0, num2=0.0;
    char op, final;

    puts("Please enter the first number:");
    num1 = getNumOne();
    op = getOperationB();

    do {
        puts("Please enter the second number (non-zero):");
        num2 = getNumTwo();
    } while (num2 == 0 && op == '/');

    final = printf("The result of %.2f %c %.2f is %.2f\n", num1, op, num2, bFunctionResult(num1, num2, op));
    return final;
}

// For Case U-----------------------------------------
char getOperationU(void) {
    char op = 0;
    puts("Please enter the operation (S - (for square root) , L - (for logarithm) , E - (for exponential) , C - (for ceil) , F - (for floor))");
    scanf(" %c", &op); //writing the selection to a variable
    op = toupper(op);

    //checking for operation validity
    while ((op != 'S') && (op != 'L') && (op != 'E') && (op != 'C') && (op != 'F')) {
        puts("Please enter a valid operation.");
        puts("Please enter the operation (S - (for square root) , L - (for logarithm) , E - (for exponential) , C - (for ceil) , F - (for floor))");
        scanf(" %c", &op); //writing the selection to a variable
        op = toupper(op);
    }
    return op;
}

float getNumOneU(char op) {
    float num1=0.0;

    switch (op) {
        case 'S':
            do {
                puts("Please enter a positive value:");
                num1 = getNumOne();
            } while(num1 < 0.0);
            break;
        case 'L':
            do {
                puts("Please enter a positive non-zero value:");
                num1 = getNumOne();
            } while(num1 < 0.0);
            break;
        case 'E':
        case 'C':
        case 'F':
            puts("Please enter a number:");
            num1 = getNumOne();
            break;
    }
    return num1;
}

float uFunctionResult(float num1, char op) {
    float uResult=0.0;
    //calculates the different operations
    switch(op) {
        case 'S':
            uResult = sqrtf(num1); //square root
            break;
        case 'L':
            uResult = log10(num1); //base-10 logarithms
            break;
        case 'E':
            uResult = exp(num1); //exponentials (e^x)
            break;
        case 'C':
            uResult = ceil(num1); //ceiling
            break;
        case 'F':
            uResult = floor(num1); //floor
            break;
    }
    return uResult;
}

float uFunction(void) {
    float num1=0.0;
    char op, final;

    op = getOperationU();
    num1 = getNumOneU(op);
    
    final = printf("The result is %.2f\n", uFunctionResult(num1, op));
    return final;
}

// For Case A-----------------------------------------
char aScreen(void) {
    char aChoice;
    //display selection menu
    puts("Select one of the following items:");
    puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
    puts("U) - Unary Mathematical Operations, such as square root, and log.");
    puts("X) - Exit and back to the main menu.");
    scanf(" %c", &aChoice);
    aChoice = toupper(aChoice);

    while (aChoice != 'B' && aChoice != 'U' && aChoice != 'X') {
        aChoice = aShortScreen();
    }

    return aChoice;
}

char aShortScreen(void) {
    char aChoice;
    do {
        //display shortened selection menu for case a
        puts("Please select your option (B - (Binary operation), U - (Unary operation) , A - (Advanced), V - (Variables), X - (Exit))");
        scanf(" %c", &aChoice);
    } while(aChoice != 'B' && aChoice != 'U' && aChoice != 'X');

    return aChoice;
}

float caseA_GetVarOneValueB(float varValues[]) {
    char varInput;
    float num1=0.0;

    scanf(" %c", &varInput);
    varInput = toupper(varInput);

    //validating the variable
    while (varInput != 'A' && varInput != 'B' && varInput != 'C' && varInput != 'D' && varInput != 'E') {
        puts("Please enter the first number or a variable ('a' to 'e'):");
        scanf(" %c", &varInput);
        varInput = toupper(varInput);
    }

    //comprehending the variable
    switch (varInput) {
        case 'A':
            num1 = varValues[0];
            break;
        case 'B':
            num1 = varValues[1];
            break;
        case 'C':
            num1 = varValues[2];
            break;
        case 'D':
            num1 = varValues[3];
            break;
        case 'E':
            num1 = varValues[4];
            break;
    }

    return num1;
}

float caseA_GetValueOneB(float varValues[]) {
    int aIsNum=0, aIsVar=0;
    float num1=0.0;
    char varInput;

    puts("Please enter the first number or variable ('a' to 'e'):");
    //checking if it was a number or variable
    if (scanf("%f", &num1)) {
        aIsNum = 1; //user input a number
    }
    else {
        aIsVar = 1;
        num1 = caseA_GetVarOneValueB(varValues); //user input a variable
    }
    return num1;
}

float caseA_GetVarTwoValueB(float varValues[]) {
    char varInputTwo;
    int checkNum=0;
    float num2=0.0;

    while (checkNum == 0) {
        scanf(" %c", &varInputTwo);
        varInputTwo = toupper(varInputTwo);

        //validates the variable input
        while (varInputTwo != 'A' && varInputTwo != 'B' && varInputTwo != 'C' && varInputTwo != 'D' && varInputTwo != 'E') {
            puts("Please enter the second number or a variable ('a' to 'e'):");
            scanf(" %c", &varInputTwo);
            varInputTwo = toupper(varInputTwo);
        }

        //ensures the variable inputted does not contain a value of zero
        switch (varInputTwo) {
            case 'A':
                if (varValues[0] == 0) {
                    puts("Denominator can't be zero.");
                }
                else {
                    num2 = varValues[0];
                    checkNum = 1;
                }
                break;
            case 'B':
                if (varValues[1] == 0) {
                    puts("Denominator can't be zero.");
                }
                else {
                    num2 = varValues[1];
                    checkNum = 1;
                }
                break;
            case 'C':
                if (varValues[2] == 0) {
                    puts("Denominator can't be zero.");
                }
                else {
                    num2 = varValues[2];
                    checkNum = 1;
                }
                break;
            case 'D':
                if (varValues[3] == 0) {
                    puts("Denominator can't be zero.");
                }
                else {
                    num2 = varValues[3];
                    checkNum = 1;
                }
                break;
            case 'E':
                if (varValues[4] == 0) {
                    puts("Denominator can't be zero.");
                }
                else {
                    num2 = varValues[4];
                    checkNum = 1;
                }
                break;
        }
    }
    return num2;
}

float caseA_GetValueTwoB(char op, float varValues[]) {
    int checkNum=0, bIsNum=0, bIsVar=0;
    float num2=0.0;
    char varInputTwo;
    
    while (checkNum == 0) {
        if (op == '/') {
            puts("Please enter the second number or a variable ('a' to 'e'):");
            if (scanf("%f", &num2)) {
                bIsNum=1;
                if (num2 == 0) {
                    puts("Denominator can't be zero.");
                }
                else {
                    checkNum = 1;
                }
            }
            else {
                bIsVar=1;
                num2 = caseA_GetVarTwoValueB(varValues);
                checkNum = 1;
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
                varInputTwo = toupper(varInputTwo);
                bIsVar = 1;

                while (varInputTwo != 'A' && varInputTwo != 'B' && varInputTwo != 'C' && varInputTwo != 'D' && varInputTwo != 'E') {
                    puts("Please enter the second number or a variable ('a' to 'e'):");
                    scanf(" %c", &varInputTwo);
                    varInputTwo = toupper(varInputTwo);
                }
                
                switch (varInputTwo) {
                    case 'A':
                        num2 = varValues[0];
                        break;
                    case 'B':
                        num2 = varValues[1];
                        break;
                    case 'C':
                        num2 = varValues[2];
                        break;
                    case 'D':
                        num2 = varValues[3];
                        break;
                    case 'E':
                        num2 = varValues[4];
                        break;
                }
                break;
            }
        }
    }
    checkNum = 0;
    return num2;
}

float aFunctionBResult(float num1, float num2, char op) {
    float aBResult=0.0;

    switch (op) {
        case '+':
            aBResult = num1 + num2;
            break;
        case '-':
            aBResult = num1 - num2;
            break;
        case '*':
            aBResult = num1 * num2;
            break;
        case '/':
            aBResult = num1 / num2;
            break;
        case '%':
            aBResult = fmod(num1, num2);
            break;
        case '^':
            aBResult = pow(num1, num2);
            break;
    }

    return aBResult;
}

float aFunctionB(float varValues[]) {
    int num1=0.0, num2=0.0;
    char op, final;

    num1 = caseA_GetValueOneB(varValues);
    op = getOperationB();
    num2 = caseA_GetValueTwoB(op, varValues);

    final = printf("The result is %.2f\n", aFunctionBResult(num1, num2, op));
    return final;
}

char uScreen(void) {
    char uOp;

    //displaying selection menu
    puts("Please enter the operation (S - (for square root) , L - (for logarithm) , E - (for exponential) , C - (for ceil) , F - (for floor))");
    scanf(" %c", &uOp);
    uOp = toupper(uOp);

    //checking for selection validity
    while (uOp != 'S' && uOp != 'L' && uOp != 'E' && uOp != 'C' && uOp != 'F') {
        puts("Please enter a valid operation.");
        puts("Please enter the operation (S - (for square root) , L - (for logarithm) , E - (for exponential) , C - (for ceil) , F - (for floor))");
        scanf(" %c", &uOp); //writing the selection to a variable
        uOp = toupper(uOp);
    }
    return uOp;
}

float aFunctionUResult(char uOp, float varValues[]) {
    int checkNum=0, aIsNum=0, aIsVar=0;
    float num1=0.0, aUResult=0.0;
    char varInput;

    //checking for number validity
    while (checkNum == 0) {
        if (uOp == 'S') { //in square root, there cannot be a negative number, this code will validate numbers and variables ensuring no negative numbers are inputted
            aIsNum=0;
            aIsVar=0;
            puts("Please enter a positive value or a variable ('a' to 'e'):");
            if (scanf("%f", &num1)) {
                aIsNum = 1;
                if (num1 < 0) {
                    puts("Must be a positive value.");
                }
                else {
                    checkNum = 1;
                }
            }
            else {
                scanf(" %c", &varInput);
                varInput = toupper(varInput);
                aIsVar = 1;

                while (varInput != 'A' && varInput != 'B' && varInput != 'C' && varInput != 'D' && varInput != 'E') {
                    puts("Please enter a positive value or a variable ('a' to 'e'):");
                    scanf(" %c", &varInput);
                    varInput = toupper(varInput);
                }
                
                switch (varInput) {
                    case 'A':
                        if (varValues[0] < 0) {
                            puts("Must be a positive number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'B':
                        if (varValues[1] < 0) {
                            puts("Must be a positive number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'C':
                        if (varValues[2] < 0) {
                            puts("Must be a positive number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'D':
                        if (varValues[3] < 0) {
                            puts("Must be a positive number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'E':
                        if (varValues[4] < 0) {
                            puts("Must be a positive number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                }
            }
        }
        else if (uOp == 'L') { //in logarithms, there cannot be a negative or zero number, this will validate numbers and variables ensuring no negative or zero number values are inputted
            aIsNum=0;
            aIsVar=0;
            puts("Please enter a positive non-zero value or a variable ('a' to 'e'):");
            if (scanf("%f", &num1)) {
                aIsNum = 1;
                if (num1 <= 0) {
                    puts("Must be a positive non-zero value.");
                }
                else {
                    checkNum = 1;
                }
            }
            else {
                aIsVar = 1;
                scanf(" %c", &varInput);
                varInput = toupper(varInput);

                while (varInput != 'A' && varInput != 'B' && varInput != 'C' && varInput != 'D' && varInput != 'E') {
                    puts("Please enter a positive non-zero value or a variable ('a' to 'e'):");
                    scanf(" %c", &varInput);
                    varInput = toupper(varInput);
                }
                
                switch (varInput) {
                    case 'A':
                        if (varValues[0] <= 0) {
                            puts("Must be a positive non-zero number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'B':
                        if (varValues[1] <= 0) {
                            puts("Must be a positive non-zero number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'C':
                        if (varValues[2] <= 0) {
                            puts("Must be a positive non-zero number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'D':
                        if (varValues[3] <= 0) {
                            puts("Must be a positive non-zero number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                    case 'E':
                        if (varValues[4] <= 0) {
                            puts("Must be a positive non-zero number.");
                        }
                        else {
                            checkNum = 1;
                        }
                        break;
                }
            }
        }
        else { //Here it doesn't matter what the user enters, there's no mathematical errors for exponential, ceiling or floor functions.
            aIsNum=0;
            aIsVar=0;
            puts("Please enter the second number or a variable ('a' to 'e'):");
            if (scanf("%f", &num1)) {
                aIsNum = 1;
                break;
            }
            else {
                scanf(" %c", &varInput);
                varInput = toupper(varInput);
                aIsVar = 1;

                while (varInput != 'A' && varInput != 'B' && varInput != 'C' && varInput != 'D' && varInput != 'E') {
                    puts("Please enter the second number or a variable ('a' to 'e'):");
                    scanf(" %c", &varInput);
                    varInput = toupper(varInput);
                }
                break;
            }

        }
    }
    checkNum = 0;

    //computes the requested calculation
    switch (uOp) {
        case 'S':
        case 's': //in each case it will check if the user entered a number or a variable and will then compute the requested calculation
            if (aIsNum == 1) {
                aUResult = sqrtf(num1);
            }
            if (aIsVar == 1) {
                switch (varInput) {                                          
                    case 'A':
                    case 'a':
                        aUResult = sqrtf(varValues[0]);
                        break;
                    case 'B':
                    case 'b':
                        aUResult = sqrtf(varValues[1]);
                        break;
                    case 'C':
                    case 'c':
                        aUResult = sqrtf(varValues[2]);
                        break;
                    case 'D':
                    case 'd':
                        aUResult = sqrtf(varValues[3]);
                        break;
                    case 'E':
                    case 'e':
                        aUResult = sqrtf(varValues[4]);
                        break;
                }
            }
            break;
        case 'L':
        case 'l':
            if (aIsNum == 1) {
                aUResult = log10(num1);
            }
            else {
                switch (varInput) {                                          
                    case 'A':
                    case 'a':
                        aUResult = log10(varValues[0]);
                        break;
                    case 'B':
                    case 'b':
                        aUResult = log10(varValues[1]);
                        break;
                    case 'C':
                    case 'c':
                        aUResult = log10(varValues[2]);
                        break;
                    case 'D':
                    case 'd':
                        aUResult = log10(varValues[3]);
                        break;
                    case 'E':
                    case 'e':
                        aUResult = log10(varValues[4]);
                        break;
                }
            }
            break;
        case 'E':
        case 'e':
            if (aIsNum == 1) {
                aUResult = exp(num1);
            }
            else {
                switch (varInput) {                                          
                    case 'A':
                    case 'a':
                        aUResult = exp(varValues[0]);
                        break;
                    case 'B':
                    case 'b':
                        aUResult = exp(varValues[1]);
                        break;
                    case 'C':
                    case 'c':
                        aUResult = exp(varValues[2]);
                        break;
                    case 'D':
                    case 'd':
                        aUResult = exp(varValues[3]);
                        break;
                    case 'E':
                    case 'e':
                        aUResult = exp(varValues[4]);
                        break;
                }
            }
            break;
        case 'C':
        case 'c':
            if (aIsNum == 1) {
                aUResult = ceil(num1);
            }
            else {
                switch (varInput) {                                          
                    case 'A':
                    case 'a':
                        aUResult = ceil(varValues[0]);
                        break;
                    case 'B':
                    case 'b':
                        aUResult = ceil(varValues[1]);
                        break;
                    case 'C':
                    case 'c':
                        aUResult = ceil(varValues[2]);
                        break;
                    case 'D':
                    case 'd':
                        aUResult = ceil(varValues[3]);
                        break;
                    case 'E':
                    case 'e':
                        aUResult = ceil(varValues[4]);
                        break;
                }
            }
            break;
        case 'F':
        case 'f':
            if (aIsNum == 1) {
                aUResult = floor(num1);
            }
            else {
                switch (varInput) {                                          
                    case 'A':
                    case 'a':
                        aUResult = floor(varValues[0]);
                        break;
                    case 'B':
                    case 'b':
                        aUResult = floor(varValues[1]);
                        break;
                    case 'C':
                    case 'c':
                        aUResult = floor(varValues[2]);
                        break;
                    case 'D':
                    case 'd':
                        aUResult = floor(varValues[3]);
                        break;
                    case 'E':
                    case 'e':
                        aUResult = floor(varValues[4]);
                        break;
                }
            }
            break;
    }

    return aUResult;
}

float aFunctionU(float varValues[]) {
    char uOp, final;

    uOp = uScreen();
    final = printf("The result is %.2f\n", aFunctionUResult(uOp, varValues));

    return final;
}

float aFunctionX(void) {
    int aStart = 1;
    return aStart;
}

float aFunction(float varValues[]) {
    int aStart = 0, aBegin = 1, num1=0.0, num2=0.0;
    char aChoice, op, final;

    while (aStart == 0) {
        if (aBegin == 1) {
            aChoice = aScreen();
            aBegin = 0;
        }
        else {
            aChoice = aShortScreen();
        }

        switch(aChoice) {
            case 'B':
                final = aFunctionB(varValues);
                break;
            case 'U':
                final = aFunctionU(varValues);
                break;
            case 'X':
                final = aFunctionX();
                break;
        }
        aStart = 1;
    }
    aStart = 0;
    return final;
}

// For Case V-----------------------------------------
void vFunction(float varValues[]) {
    char var;
    float num;

    puts("Please enter the name of the variable (A single character between 'a' to 'e'):");
    scanf(" %c", &var); //writes the variable name to the variable named "var"
    var = toupper(var);

    //checks the validity of the name, between 'a' to 'e'
    while (var != 'A' && var != 'B' && var != 'C' && var != 'D' && var != 'E') {
        puts("Please enter the name of the variable (A single character between 'a' to 'e'):");
        scanf(" %c", &var);
        var = toupper(var);
    }
    
    puts("Please enter a value to assign to the variable:");
    scanf("%f", &num); //writes the numerical value of a number to a variable named "num1"

    printf("The variable %c is set to the value %.2f\n", var, num);

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
}

// For Case X-----------------------------------------
int xFunction(void) {
    int start = 1;
    puts("Thank you for using my Simple Calculator. Hope to see you again, Goodbye!");
    start = 0;
    return start;
}
