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
 * Complete the 'ContarPalabras' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING separadores
 *  2. STRING frase
 */

int ContarPalabras(char* separadores, char* frase) {
    char* pch = NULL;
    int cant = 0, spaceCount = 0;
    char* cpyFrase = (char*)calloc(strlen(frase) + 1, sizeof(char));
    if (cpyFrase == NULL) return -1;
    char* buffer = (char*)calloc(strlen(frase) + 1, sizeof(char));
    if (buffer == NULL) return -1;
    sprintf(cpyFrase, "%s", frase);
    pch = strtok(cpyFrase, separadores);
    while (pch != NULL) {
        cant++;
        if (strlen(pch) >= 2 && strlen(pch) <= 4)
            RotadorDePalabras(pch, strlen(pch) / 2);
        strcat(buffer, pch);
        spaceCount += strlen(pch);
        buffer[spaceCount + (cant - 1)] = ' ';
        pch = strtok(NULL, separadores);
    }
    printf("Cantidad Palabras [%d]\tCantidad Caracteres [%d]\nFrase: %s", cant, strlen(frase), buffer);
    free(cpyFrase);
    free(buffer);
    return cant;

}

/*
 * Complete the 'RotadorDePalabras' function below.
 *
 * The function accepts following parameters:
 *  1. STRING palabra
 *  2. INTEGER palabraLongitudMitad
 */

void RotadorDePalabras(char* palabra, int palabraLongitudMitad) {
    int totalLength = strlen(palabra), i, aux = 0;
    for (i = 0; i < palabraLongitudMitad; i++) {
        aux = palabra[i];
        palabra[i] = palabra[totalLength - i - 1];
        palabra[totalLength - i - 1] = aux;
    }
    return;

}

/*
 * Complete the 'cadenaFinal' function below.
 *
 * The function accepts following parameters:
 *  1. STRING vocales
 *  2. STRING separadores
 *  3. STRING frase
 */

void cadenaFinal(char* vocales, char* separadores, char* frase) {
    int cantPalabras = ContarPalabras(separadores, frase);

}

int main()
{
    char* vocal = readline();

    char* separador = readline();

    char* frase = readline();

    cadenaFinal(vocal, separador, frase);

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