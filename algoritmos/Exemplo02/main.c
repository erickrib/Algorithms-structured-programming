#include <stdio.h>
#include <stdbool.h>

int main() {
    int intVar = 0;
    float floatVar = 0.0;
    double doubleVar = 0.0;
    long int longIntVar = 0;
    long long int longLongIntVar = 0;
    short int shortIntVar = 0;
    unsigned int unsignedIntVar = 0;
    char charVar = 'a';
    bool boolVar = true;

    printf("\n varint = %d", intVar);
    printf("\n varfloat = %f", floatVar);
    printf("\n vardouble = %f", doubleVar);
    printf("\n varlongint = %ld", longIntVar);
    printf("\n varlonglongint = %lld", longLongIntVar);
    printf("\n varshortint = %d", shortIntVar);
    printf("\n varunsignedint = %u", unsignedIntVar);
    printf("\n varchar = %c", charVar);
    printf("\n varbool = %d", boolVar);

    return 0;
}