#include <stdio.h>

int main() {
    char operacao;
    float num1, num2, resultado;
    
    printf("Calculadora Básica\n");
    printf("Escolha uma operação:\n");
    printf("+ Soma\n");
    printf("- Subtração\n");
    printf("* Multiplicação\n");
    printf("/ Divisão\n");
    
    printf("Digite a operação desejada: ");
    fflush(stdin);
    scanf(" %c", &operacao);
    
    printf("Digite dois números: ");
    scanf("%f %f", &num1, &num2);
    
    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '-':
            resultado = num1 - num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '*':
            resultado = num1 * num2;
            printf("Resultado: %.2f\n", resultado);
            break;
        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("Resultado: %.2f\n", resultado);
            } else {
                printf("Erro: Divisão por zero!\n");
            }
            break;
        default:
            printf("Operação inválida!\n");
    }
    
    return 0;
}