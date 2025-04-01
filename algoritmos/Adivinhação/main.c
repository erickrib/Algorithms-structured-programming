#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_RANGE (0)
#define MAX_RANGE (99)
#define RAND_IN_RANGE() (rand() % (MAX_RANGE - MIN_RANGE + 1) + MIN_RANGE)

int main() {
    int numero_sorteado, chute, tentativas = 0;
    
    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    numero_sorteado = RAND_IN_RANGE();
    
    printf("Jogo de Adivinhação! Tente adivinhar o número entre %d e %d.\n", MIN_RANGE, MAX_RANGE);
    
    while (1) {
        printf("Digite seu chute: ");
        scanf("%d", &chute);
        tentativas++;
        
        if (chute < MIN_RANGE || chute > MAX_RANGE) {
            printf("Por favor, insira um número entre %d e %d.\n", MIN_RANGE, MAX_RANGE);
            continue;
        }
        
        if (chute > numero_sorteado) {
            printf("O número sorteado é menor! Tente novamente.\n");
        } else if (chute < numero_sorteado) {
            printf("O número sorteado é maior! Tente novamente.\n");
        } else {
            printf("Parabéns! Você acertou o número em %d tentativas.\n", tentativas);
            break;
        }
    }
    
    return 0;
}
