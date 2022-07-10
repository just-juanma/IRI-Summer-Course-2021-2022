#include <stdio.h>
#include <stdlib.h>

int sumNumbers(int sizeNumbers, int* numbers) {
    int i, sumatoria = 0;
    for (i = 0; i < sizeNumbers; i++)
        sumatoria += numbers[i];
    return sumatoria;
}

void separandoNumeros(int sizeNumbers, int* numbers, int* pairRows, int** pairs, int* oddRows, int** odds) {
    int i;
    for (i = 0; i < sizeNumbers; i++) {
        if ((numbers[i] % 2) == 0) {
            (*pairs)[*pairRows] = numbers[i];
            (*pairRows)++;
        }
        else {
            (*odds)[*oddRows] = numbers[i];
            (*oddRows)++;
        }
    }

}

void ProcesandoDatos(int sizeNumbers, int* numbers) {
    int pairsCount = 0, oddsCount = 0, i, pairsSum = 0, oddsSum = 0;
    int* pairs = (int*)calloc(sizeNumbers, sizeof(int));
    if (pairs == NULL) return;
    int* odds = (int*)calloc(sizeNumbers, sizeof(int));
    if (odds == NULL) return;
    separandoNumeros(sizeNumbers, numbers, &pairsCount, &pairs, &oddsCount, &odds);
    pairsSum = sumNumbers(pairsCount, pairs);
    oddsSum = sumNumbers(oddsCount, odds);
    printf("Suma Pares: %d\nVector Pares:", pairsSum);
    for (i = 0; i < pairsCount; i++)
        printf(" %d", pairs[i]);
    printf("\nSuma Impares: %d\nVector Impares:", oddsSum);
    for (i = 0; i < oddsCount; i++)
        printf(" %d", odds[i]);
    free(pairs);
    free(odds);
}

int main()
{

    // ProcesandoDatos(numerosLong, misNumeros); no main

    return 0;
}