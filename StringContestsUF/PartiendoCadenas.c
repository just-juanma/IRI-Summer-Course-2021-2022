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

/*
 * Complete the 'PalabraMasLarga' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY palabras
 *  2. INTEGER_ARRAY posicionPalabra
 */

int PalabraMasLarga(int palabras_count, char** palabras, int* posicionPalabra) {
    int i, num = 0, max = 0;
    for (i = 0; i < palabras_count; i++) {
        num = strlen(palabras[i]);
        if (i == 0 || num > max) {
            *posicionPalabra = i;
            max = num;
        }
    }
    return max;

}

/*
 * Complete the 'cantidadTotalPalabras' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING separadores
 *  2. STRING oracion
 */

int cantidadTotalPalabras(char* separadores, char* oracion) {
    char* pch = NULL;
    int cant = 0;
    char* cpyOracion = (char*)calloc(strlen(oracion) + 1, sizeof(char));
    if (cpyOracion == NULL) return -1;
    strcpy(cpyOracion, oracion);
    pch = strtok(cpyOracion, separadores);
    while (pch != NULL) {
        cant++;
        pch = strtok(NULL, separadores);
    }
    free(cpyOracion);
    return cant;

}

/*
 * Complete the 'SeparandoPalabras' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. STRING oracion
 *  2. STRING separadores
 *  3. INTEGER_ARRAY cantidadPalabras
 */

 /*
  * To return the string array from the function, you should:
  *     - Store the size of the array to be returned in the result_count variable
  *     - Allocate the array statically or dynamically
  *
  * For example,
  * char** return_string_array_using_static_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     static char* a[5] = {"static", "allocation", "of", "string", "array"};
  *
  *     return a;
  * }
  *
  * char** return_string_array_using_dynamic_allocation(int* result_count) {
  *     *result_count = 5;
  *
  *     char** a = malloc(5 * sizeof(char*));
  *
  *     for (int i = 0; i < 5; i++) {
  *         *(a + i) = malloc(20 * sizeof(char));
  *     }
  *
  *     *(a + 0) = "dynamic";
  *     *(a + 1) = "allocation";
  *     *(a + 2) = "of";
  *     *(a + 3) = "string";
  *     *(a + 4) = "array";
  *
  *     return a;
  * }
  *
  */
char** SeparandoPalabras(char* oracion, char* separadores, int* cantidadPalabras) {
    int i;
    char* pch = NULL;
    char* cpyOracion = (char*)calloc(strlen(oracion) + 1, sizeof(char));
    if (cpyOracion == NULL) return NULL;
    strcpy(cpyOracion, oracion);
    *cantidadPalabras = cantidadTotalPalabras(separadores, cpyOracion);
    char** matrizPalabras = (char**)calloc(*cantidadPalabras, sizeof(char*));
    if (matrizPalabras == NULL) return NULL;
    pch = strtok(cpyOracion, separadores);
    for (i = 0; pch != NULL; i++) {
        matrizPalabras[i] = (char*)calloc(strlen(pch), sizeof(char));
        if (matrizPalabras[i] == NULL) return NULL;
        matrizPalabras[i] = pch;
        pch = strtok(NULL, separadores);
    }
    return matrizPalabras;

}

/*
 * Complete the 'PartiendoCadenas' function below.
 *
 * The function accepts following parameters:
 *  1. STRING separadores
 *  2. STRING oracion
 */

void PartiendoCadenas(char* separadores, char* oracion) {
    int cantTotalPalabras = 0, posicionPalabra = 0, cantLetras;
    char** matriz = SeparandoPalabras(oracion, separadores, &cantTotalPalabras);
    if (matriz == NULL) return -1;
    cantLetras = PalabraMasLarga(cantTotalPalabras, matriz, &posicionPalabra);
    printf("Hay %d palabras, pero la mas larga [%s -> %d letras]", cantTotalPalabras, matriz[posicionPalabra], cantLetras);

}

int main()
{
    char* misSeparadores = readline();

    char* miOracion = readline();

    PartiendoCadenas(misSeparadores, miOracion);

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