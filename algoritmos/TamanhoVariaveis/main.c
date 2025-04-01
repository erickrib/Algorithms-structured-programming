#include <stdio.h>
#include <stdbool.h>

int main() {
    int resposta;
    
    printf("Qual o tamanho de uma variável do tipo int?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(int));
    
    printf("Qual o tamanho de uma variável do tipo long int?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(long int));
    
    printf("Qual o tamanho de uma variável do tipo long long int?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(long long int));
    
    printf("Qual o tamanho de uma variável do tipo short int?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(short int));
    
    printf("Qual o tamanho de uma variável do tipo unsigned int?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(unsigned int));
    
    printf("Qual o tamanho de uma variável do tipo float?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(float));
    
    printf("Qual o tamanho de uma variável do tipo double?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(double));
    
    printf("Qual o tamanho de uma variável do tipo char?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(char));
    
    printf("Qual o tamanho de uma variável do tipo bool?\n");
    scanf("%d", &resposta);
    printf("Sua resposta: %d\n", resposta);
    printf("Resposta correta: %zu\n\n", sizeof(bool));
    
    return 0;
}
