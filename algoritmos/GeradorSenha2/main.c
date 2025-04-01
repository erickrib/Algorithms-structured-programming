#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PW_SIZE 32

int main(int argc, char *argv[]) {
    int pw_size = 0;
    char check[MAX_PW_SIZE + 1];
    char pw[MAX_PW_SIZE + 1];

    srand(time(NULL));

    if (argc < 2) {
        puts("Informe o tamanho da senha na linha de comando");
        return -1;
    }

    pw_size = atoi(argv[1]);

    if (pw_size <= 0) {
        puts("O tamanho da senha deve ser positivo e maior do que zero");
        return -1;
    }

    if (pw_size > MAX_PW_SIZE) {
        puts("O tamanho da senha deve ser no máximo 32");
        return -1;
    }

    for (int i = 0; i < pw_size; i++) {
        int tipo = rand() % 3;
        if (tipo == 0) {
            pw[i] = 'a' + rand() % 26;
        } else if (tipo == 1) {
            pw[i] = 'A' + rand() % 26;
        } else {
            pw[i] = '0' + rand() % 10;
        }
    }

    pw[pw_size] = '\0';

    puts(pw);

    puts("Digite a senha gerada:");

    fflush(stdin);
    fgets(check, MAX_PW_SIZE + 1, stdin);

    int len = strlen(check);
    if (check[len - 1] == '\n') {
        check[len - 1] = '\0';
    }

    if (strncmp(pw, check, MAX_PW_SIZE) == 0) {
        puts("Confirmado!");
    } else {
        puts("Negado!");
    }

    return 0;
}