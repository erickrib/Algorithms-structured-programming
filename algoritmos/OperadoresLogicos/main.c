#include <stdio.h>

int main() {
    float a, b;
    int x, y;
    
    // Operações Aritméticas
    printf("Digite dois números (float) para operações aritméticas: ");
    scanf("%f %f", &a, &b);
    
    printf("Soma: %.2f + %.2f = %.2f\n", a, b, a + b);
    printf("Subtração: %.2f - %.2f = %.2f\n", a, b, a - b);
    printf("Multiplicação: %.2f * %.2f = %.2f\n", a, b, a * b);
    
    if (b != 0) {
        printf("Divisão: %.2f / %.2f = %.2f\n", a, b, a / b);
    } else {
        printf("Erro: divisão por zero!\n");
    }
    
    // Operação de Módulo (Apenas Inteiros)
    printf("\nDigite dois números inteiros para a operação de módulo: ");
    scanf("%d %d", &x, &y);
    
    if (y != 0) {
        printf("Resto da divisão: %d %% %d = %d\n", x, y, x % y);
    } else {
        printf("Erro: módulo por zero!\n");
    }
    
    // Operações Binárias
    printf("\nDigite dois números inteiros para operações binárias: ");
    scanf("%d %d", &x, &y);
    
    printf("AND: %d & %d = %d\n", x, y, x & y);
    printf("OR: %d | %d = %d\n", x, y, x | y);
    printf("XOR: %d ^ %d = %d\n", x, y, x ^ y);
    printf("Inversão: ~%d = %d\n", x, ~x);
    
    // Operações de Comparação
    printf("\nComparações:\n");
    printf("%d == %d: %d\n", x, y, x == y);
    printf("%d > %d: %d\n", x, y, x > y);
    printf("%d >= %d: %d\n", x, y, x >= y);
    printf("%d < %d: %d\n", x, y, x < y);
    printf("%d <= %d: %d\n", x, y, x <= y);
    printf("%d != %d: %d\n", x, y, x != y);
    
    // Operações Lógicas
    printf("\nDigite dois números inteiros para operações lógicas (0 ou 1): ");
    scanf("%d %d", &x, &y);
    
    printf("AND lógico: %d && %d = %d\n", x, y, x && y);
    printf("OR lógico: %d || %d = %d\n", x, y, x || y);
    printf("Inversão lógica: !%d = %d\n", x, !x);
    
    return 0;
}
