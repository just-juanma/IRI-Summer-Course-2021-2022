#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'SumarNumeros' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY Numeros as parameter.
 */

int SumarNumeros(int Numeros_count, int* Numeros) {
    int i, sumatoria = 0;
    for (i = 0; i < Numeros_count; i++)
        sumatoria += Numeros[i];
    return sumatoria;
}

/*
 * Complete the 'separandoNumeros' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY Numeros
 *  2. 2D_INTEGER_ARRAY Pares
 *  3. 2D_INTEGER_ARRAY Impares
 */

void separandoNumeros(int Numeros_count, int* Numeros, int* Pares_rows, int** Pares, int* Impares_rows, int** Impares) {
    int i;
    for (i = 0; i < Numeros_count; i++) {
        if ((Numeros[i] % 2) == 0) {
            (*Pares)[*Pares_rows] = Numeros[i];
            (*Pares_rows)++;
        }
        else {
            (*Impares)[*Impares_rows] = Numeros[i];
            (*Impares_rows)++;
        }
    }

}

/*
 * Complete the 'ProcesandoDatos' function below.
 *
 * The function accepts INTEGER_ARRAY Numeros as parameter.
 */

void ProcesandoDatos(int Numeros_count, int* Numeros) {
    int cantPares = 0, cantImpares = 0, i, sumaPares = 0, sumaImpares = 0;
    int* pares = (int*)calloc(Numeros_count, sizeof(int));
    if (pares == NULL) return;
    int* impares = (int*)calloc(Numeros_count, sizeof(int));
    if (impares == NULL) return;
    separandoNumeros(Numeros_count, Numeros, &cantPares, &pares, &cantImpares, &impares);
    sumaPares = SumarNumeros(cantPares, pares);
    sumaImpares = SumarNumeros(cantImpares, impares);
    printf("Suma Pares: %d\nVector Pares:", sumaPares);
    for (i = 0; i < cantPares; i++)
        printf(" %d", pares[i]);
    printf("\nSuma Impares: %d\nVector Impares:", sumaImpares);
    for (i = 0; i < cantImpares; i++)
        printf(" %d", impares[i]);
    free(pares);
    free(impares);
}

int main()
{
    int numerosLong = parse_int(ltrim(rtrim(readline())));

    char** misNumeros_temp = split_string(rtrim(readline()));

    int* misNumeros = malloc(numerosLong * sizeof(int));

    for (int i = 0; i < numerosLong; i++) {
        int misNumeros_item = parse_int(*(misNumeros_temp + i));

        *(misNumeros + i) = misNumeros_item;
    }

    ProcesandoDatos(numerosLong, misNumeros);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    }
    else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        }
        else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}