#include <stdio.h>

int main() {
    int int_dividendo, int_divisor;
    float float_dividendo, float_divisor;
    int resultado_int;
    float resultado_float;

    // Primeira divisão (int / int)
    printf("Digite o dividendo (int): ");
    scanf("%d", &int_dividendo);
    printf("Digite o divisor (int): ");
    scanf("%d", &int_divisor);
    
    if (int_divisor != 0) {
        resultado_int = int_dividendo / int_divisor;
        printf("Resultado armazenado em int: %d\n", resultado_int);
    } else {
        printf("Erro: divisão por zero!\n");
    }
    
    // Segunda divisão (float / float)
    printf("\nDigite o dividendo (float): ");
    scanf("%f", &float_dividendo);
    printf("Digite o divisor (float): ");
    scanf("%f", &float_divisor);
    
    if (float_divisor != 0) {
        resultado_int = float_dividendo / float_divisor;
        resultado_float = float_dividendo / float_divisor;
        printf("Resultado armazenado em int: %d\n", resultado_int);
        printf("Resultado armazenado em float: %.2f\n", resultado_float);
    } else {
        printf("Erro: divisão por zero!\n");
    }
    
    // Terceira divisão (float / int)
    printf("\nDigite o dividendo (int): ");
    scanf("%d", &int_dividendo);
    printf("Digite o divisor (float): ");
    scanf("%f", &float_divisor);
    
    if (float_divisor != 0) {
        resultado_int = int_dividendo / float_divisor;
        resultado_float = int_dividendo / float_divisor;
        printf("Resultado armazenado em int: %d\n", resultado_int);
        printf("Resultado armazenado em float: %.2f\n", resultado_float);
    } else {
        printf("Erro: divisão por zero!\n");
    }
    
    // Quarta divisão (int / float)
    printf("\nDigite o dividendo (float): ");
    scanf("%f", &float_dividendo);
    printf("Digite o divisor (int): ");
    scanf("%d", &int_divisor);
    
    if (int_divisor != 0) {
        resultado_int = float_dividendo / int_divisor;
        resultado_float = float_dividendo / int_divisor;
        printf("Resultado armazenado em int: %d\n", resultado_int);
        printf("Resultado armazenado em float: %.2f\n", resultado_float);
    } else {
        printf("Erro: divisão por zero!\n");
    }
    
    return 0;
}