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
 * Complete the 'obtenerDiagonal' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY matriz as parameter.
 */

 /*
  * To return the integer array from the function, you should:
  *     - Store the size of the array to be returned in the result_count variable
  *     - Allocate the array statically or dynamically
  *
  * For example,
  * int* return_integer_array_using_static_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     static int a[5] = {1, 2, 3, 4, 5};
  *
  *     return a;
  * }
  *
  * int* return_integer_array_using_dynamic_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     int *a = malloc(5 * sizeof(int));
  *
  *     for (int i = 0; i < 5; i++) {
  *         *(a + i) = i + 1;
  *     }
  *
  *     return a;
  * }
  *
  */
int* obtenerDiagonal(int matriz_rows, int matriz_columns, int** matriz) {
    int i;
    int* diag = (int*)calloc(matriz_rows, sizeof(int));
    for (i = 0; i < matriz_rows; i++)
        diag[i] = matriz[i][i];
    return diag;
}

/*
 * Complete the 'sumaFilasyColumnas' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matriz
 *  2. 2D_INTEGER_ARRAY refSumColumnas
 */

 /*
  * To return the integer array from the function, you should:
  *     - Store the size of the array to be returned in the result_count variable
  *     - Allocate the array statically or dynamically
  *
  * For example,
  * int* return_integer_array_using_static_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     static int a[5] = {1, 2, 3, 4, 5};
  *
  *     return a;
  * }
  *
  * int* return_integer_array_using_dynamic_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     int *a = malloc(5 * sizeof(int));
  *
  *     for (int i = 0; i < 5; i++) {
  *         *(a + i) = i + 1;
  *     }
  *
  *     return a;
  * }
  *
  */
int* sumaFilasyColumnas(int matriz_rows, int matriz_columns, int** matriz, int** refSumColumnas) {
    int i, j, fil = 0, col = 0;
    int* sumaFila = (int*)calloc(matriz_rows, sizeof(int));
    if (sumaFila == NULL) return NULL;
    for (i = 0; i < matriz_rows; i++) {
        fil = 0;
        for (j = 0; j < matriz_columns; j++) {
            fil += matriz[i][j];
        }
        sumaFila[i] = fil;
    }
    for (i = 0; i < matriz_columns; i++) {
        col = 0;
        for (j = 0; j < matriz_rows; j++) {
            col += matriz[j][i];
        }
        (*refSumColumnas)[i] = col;
    }
    return sumaFila;
}

/*
 * Complete the 'procesandoMatriz' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER modo
 *  2. 2D_INTEGER_ARRAY matriz
 */

void procesandoMatriz(int modo, int matriz_rows, int matriz_columns, int** matriz) {
    int i;
    int* diag, * sumaDiag, * sumaFila;
    int* sumaColumna = (int*)calloc(matriz_columns, sizeof(int));
    if (sumaColumna == NULL) return;
    if (modo == 0 && matriz_rows != matriz_columns) {
        printf("No se puede obtener la diagonal de una matriz NO cuadrada");
        return;
    }
    else if (modo == 1 && matriz_rows != matriz_columns) {
        printf("No se puede obtener la suma de diagonal de una NO matriz cuadrada");
        return;
    }
    if (modo == 0 || modo == 1) {
        diag = obtenerDiagonal(matriz_rows, matriz_columns, matriz);
        if (modo == 0) {
            printf("Mi Diagonal:");
            for (i = 0; i < matriz_columns; i++)
                printf(" %d", diag[i]);
        }
        else {
            sumaDiag = sumaFilasyColumnas(1, matriz_columns, &diag, &sumaColumna);
            printf("Suma Diagonal: %d", *sumaDiag);
        }
    }
    else {
        sumaFila = sumaFilasyColumnas(matriz_rows, matriz_columns, matriz, &sumaColumna);
        printf("Suma De Cada Fila:");
        for (i = 0; i < matriz_rows; i++) {
            printf(" %d", sumaFila[i]);
        }
        printf("\nSuma De Cada Columna:");
        for (i = 0; i < matriz_columns; i++) {
            printf(" %d", sumaColumna[i]);
        }
    }
    free(sumaColumna);
}

int main()
{
    int modoMatriz = parse_int(ltrim(rtrim(readline())));

    //char** first_multiple_input = split_string(rtrim(readline()));

    int alto = parse_int(ltrim(rtrim(readline())));
    int ancho = parse_int(ltrim(rtrim(readline())));
    int** in_matriz = malloc(alto * sizeof(int*));

    for (int i = 0; i < alto; i++) {
        *(in_matriz + i) = malloc(ancho * (sizeof(int)));

        char** in_matriz_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < ancho; j++) {
            int in_matriz_item = parse_int(*(in_matriz_item_temp + j));

            *(*(in_matriz + i) + j) = in_matriz_item;
        }
    }

    procesandoMatriz(modoMatriz, alto, ancho, in_matriz);

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
