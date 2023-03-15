// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// size_t resultSize = 1;
// float *result = (float *)malloc(resultSize*sizeof(float));


// float bFunction(size_t resultSize);
// float bFunctionResult(float num1, float num2, char op, size_t resultSize);
// char getOperationB(void);
// float getNumOne(void);
// float getNumTwo(void);

// void ansFunc(size_t resultSize, float calc);

// int main(void) {
//     for (int i = 0; i <= 1; i++) {
//         bFunction(resultSize);
//     }
// }

// float getNumOne(void) {
//     float num1=0.0;
//     scanf("%f", &num1); //reading the first number
//     return num1;
// }

// float getNumTwo(void) {
//     float num2=0.0; 
//     scanf("%f", &num2); //reading the second number
//     return num2;
// }

// char getOperationB(void) {
//     char op;
//     puts("Please enter the operation (+, -, *, /, %, ^)");
//     scanf(" %c", &op); //reading the operation
    
//     //checking for operator validity
//     while (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^') {
//         puts("Please enter a valid operation.");
//         puts("Please enter the operation (+, -, *, /, %, ^)");
//         scanf(" %c", &op); //reading the operation
//     }

//     return op;
// }

// float bFunctionResult(float num1, float num2, char op, size_t resultSize) {
//     float calc=0.0;
//     float bResult=0.0;
//     //computing the different possible operations
//     switch(op) {
//         case '+': //addition
//             bResult = num1 + num2;
//             break;
//         case '-': //subtraction
//             bResult = num1 - num2;
//             break;
//         case '*': //multiplication
//             bResult = num1 * num2;
//             break;
//         case '/': //division
//             bResult = num1 / num2;
//             break;
//         case '%': //remainder
//             bResult = fmod(num1, num2);
//             break;
//         case '^': //power
//             bResult = pow(num1, num2);
//             break;
//     }

//     calc = bResult;
//     ansFunc(resultSize, calc);
//     return bResult;
// }

// float bFunction(size_t resultSize) {
//     float num1=0.0, num2=0.0;
//     char op, final;

//     puts("Please enter the first number:");
//     num1 = getNumOne();
//     op = getOperationB();

//     do {
//         puts("Please enter the second number (non-zero):");
//         num2 = getNumTwo();
//     } while (num2 == 0 && op == '/');

//     final = printf("The result of %.2f %c %.2f is %.2f\n", num1, op, num2, bFunctionResult(num1, num2, op, resultSize));
//     return final;
// }

// void ansFunc(size_t resultSize, float calc) {
//     float dummy=0.0;
//     if (result == NULL) {
//         printf("Failed to allocate result");
//     }
//     if (resultSize == 1) {
//         result[0] = calc;
//         resultSize += 1;
//     }
//     else {
//         result = (float *)realloc(result, (resultSize * sizeof(float)));
//         if (result == NULL) {
//             printf("Failed to reallocate result");
//         }

//         for (int i = 0; i <= resultSize; i++) {
//             result[i] = result[i+1];
//         }
//         resultSize += 1;
//     }
//     result[0] = calc;

//     printf("%.2f\n", result[0]);
//     printf("%.2f\n", result[1]);
//     printf("%.2f\n", result[2]);
//     printf("%.2f\n", result[3]);
//     printf("%.2f\n", result[4]);
//     free(result);
// }
