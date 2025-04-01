#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSorteado, tentativa;

    srand(time(NULL));
    numeroSorteado = rand() % 100;

    printf("Jogo de Adivinhação (for)\n");

    for (int i = 1; i <= 10; i++) {
        printf("Tentativa %d de 10 - Digite um número entre 0 e 99: ", i);
        scanf("%d", &tentativa);

        if (tentativa == numeroSorteado) {
            printf("Parabéns! Você acertou o número!\n");
            return 0;
        } else if (tentativa < numeroSorteado) {
            printf("O número sorteado é maior!\n");
        } else {
            printf("O número sorteado é menor!\n");
        }
    }

    printf("Você perdeu! O número era: %d\n", numeroSorteado);
    return 0;
}
