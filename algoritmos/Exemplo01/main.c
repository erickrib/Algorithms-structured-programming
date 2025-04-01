#include <stdio.h>
#include <stdbool.h>

int main() {
    int int_var;
    long int long_int_var;
    short int short_int_var;
    unsigned int unsigned_int_var;
    float float_var;
    double double_var;
    char char_var;
    bool bool_var;

    printf("Tamanho de int: %zu bytes\n", sizeof(int_var));
    printf("Tamanho de long int: %zu bytes\n", sizeof(long_int_var));
    printf("Tamanho de short int: %zu bytes\n", sizeof(short_int_var));
    printf("Tamanho de unsigned int: %zu bytes\n", sizeof(unsigned_int_var));
    printf("Tamanho de float: %zu bytes\n", sizeof(float_var));
    printf("Tamanho de double: %zu bytes\n", sizeof(double_var));
    printf("Tamanho de char: %zu bytes\n", sizeof(char_var));
    printf("Tamanho de bool: %zu bytes\n", sizeof(bool_var));

    return 0;
}
