// C program for array of fucntion pointers
#include <stdio.h>  

int add(int a, int b) {
    return a + b;
}   

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main(void)
{
    int (*operations[3])(int, int) = {add, subtract, multiply};
    int choice, num1, num2, result;

    printf("Select operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    result = operations[choice - 1](num1, num2);
    printf("Result: %d\n", result);

    return 0;
}