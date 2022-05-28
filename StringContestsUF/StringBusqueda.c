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
 * Complete the 'BusquedaEnString' function below.
 *
 * The function accepts following parameters:
 *  1. STRING palabra
 *  2. STRING mi_frase
 */

void BusquedaEnString(char* palabra, char* mi_frase) {
    // Write your code here
    int palabrasRepetidas = 0, vocalesContadorA = 0, vocalesContadorE = 0, vocalesContadorI = 0, vocalesContadorO = 0, vocalesContadorU = 0, i = 0, nullTester = 0;
    char cpyMiFrase[9999];
    char* sameString;
    char* vocal;
    char vocalGuardado[9999];
    mi_frase[0] = tolower(mi_frase[0]);
    palabra[0] = tolower(palabra[0]);
    strcpy(cpyMiFrase, mi_frase);
    sameString = strstr(mi_frase, palabra);
    if (sameString == NULL) {
        printf("Palabra Repetida [%d]\t", palabrasRepetidas);
        nullTester = 1;
    }
    else if (sameString[strlen(palabra)] == ' ' || sameString[strlen(palabra)] == '\0') palabrasRepetidas++;
    while (sameString != NULL) {
        for (i = 0; i < strlen(palabra); i++) {
            sameString[i] = ' ';
        }
        sameString = strstr(mi_frase, palabra);
        if (sameString == NULL) break;
        else if (sameString[strlen(palabra)] == ' ' || sameString[strlen(palabra)] == '\0') palabrasRepetidas++;
    }
    if (nullTester == 0) {
        printf("Palabra Repetida [%d]\t", palabrasRepetidas);
    }
    vocal = strpbrk(cpyMiFrase, "aeiou");
    for (i = 0; vocal != NULL; i++) {
        vocalGuardado[i] = vocal[0];
        vocal = strpbrk(vocal + 1, "aeiou");
    }
    for (i = 0; i < strlen(vocalGuardado); i++) {
        if (vocalGuardado[i] == 'a') vocalesContadorA++;
        else if (vocalGuardado[i] == 'e') vocalesContadorE++;
        else if (vocalGuardado[i] == 'i') vocalesContadorI++;
        else if (vocalGuardado[i] == 'o') vocalesContadorO++;
        else if (vocalGuardado[i] == 'u') vocalesContadorU++;
    }
    printf("A[%d]-E[%d]-I[%d]-O[%d]-U[%d]", vocalesContadorA, vocalesContadorE, vocalesContadorI, vocalesContadorO, vocalesContadorU);
    return;
}

int main()
{
    char* palabra = readline();

    char* frase = readline();

    BusquedaEnString(palabra, frase);

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