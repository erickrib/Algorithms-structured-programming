#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SORTEIO_MIN  ('a')
#define SORTEIO_MAX  ('z')
#define SORTEIO()    (char)(rand() % (SORTEIO_MAX - SORTEIO_MIN + 1) + SORTEIO_MIN)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamanho_da_senha>\n", argv[0]);
        return 1;
    }

    int tamanho = atoi(argv[1]);

    if (tamanho <= 0) {
        printf("Tamanho inválido. Informe um número inteiro positivo.\n");
        return 1;
    }

    srand(time(NULL));

    char senha[tamanho + 1];
    for (int i = 0; i < tamanho; i++) {
        senha[i] = SORTEIO();
    }
    senha[tamanho] = '\0';

    printf("Senha gerada: %s\n", senha);

    char tentativa[tamanho + 1];
    printf("Digite a senha gerada: ");
    scanf("%s", tentativa);

    if (strcmp(senha, tentativa) == 0) {
        printf("Senha correta!\n");
    } else {
        printf("Senha incorreta.\n");
    }

    return 0;
}