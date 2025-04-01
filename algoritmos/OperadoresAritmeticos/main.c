#include <stdio.h>

int main() {
    int a = 10; 
    int b = 20; 
    int c = 0;
    
    int sum = a + b;
    int sub = a - b;
    int mul = a * b;
    int div = a / b;
    
    printf("Select an operation: \n");
    printf("1. Sum\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    scanf("%d", &c);

    switch (c) {
        case 1:
            printf("Sum: %d\n", sum);
            break;
        case 2:
            printf("Subtraction: %d\n", sub);
            break;
        case 3:
            printf("Multiplication: %d\n", mul);
            break;
        case 4:
            printf("Division: %d\n", div);
            break;
        default:
            printf("Invalid operation\n");
    }
}