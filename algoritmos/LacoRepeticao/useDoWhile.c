#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSorteado, tentativa, tentativas = 0;

    srand(time(NULL));
    numeroSorteado = rand() % 100;

    printf("Jogo de Adivinhação (do...while)\n");

    do {
        printf("Tentativa %d de 10 - Digite um número entre 0 e 99: ", tentativas + 1);
        scanf("%d", &tentativa);
        tentativas++;

        if (tentativa == numeroSorteado) {
            printf("Parabéns! Você acertou o número!\n");
            return 0;
        } else if (tentativa < numeroSorteado) {
            printf("O número sorteado é maior!\n");
        } else {
            printf("O número sorteado é menor!\n");
        }
    } while (tentativas < 10);

    printf("Você perdeu! O número era: %d\n", numeroSorteado);
    return 0;
}
