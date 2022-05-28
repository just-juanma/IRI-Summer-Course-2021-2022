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
int main() {
    int entero1 = 0, entero2 = 0, i = 0, k = 0, comaCount = 0;
    float flotante1 = 0, flotante2 = 0;
    char letra;
    char palabra[51];
    char oracion1[201];
    char oracion2[201];
    char oracion3XL[999];
    char fecha[11];
    char sFloat[999];

    scanf("%s", &palabra);
    scanf("%d %f", &entero1, &flotante1);
    inputCleaning();
    scanf("%[^\n]s", &oracion1);
    inputCleaning();
    scanf("%[^\n]s", &oracion2);
    inputCleaning();
    scanf("%[^\n]s", &fecha);
    inputCleaning();
    scanf("%[^\n]s", &oracion3XL);
    printf("%s\n%d\n%.2f\n%s\n%s\n", palabra, entero1, flotante1, oracion1, oracion2);
    for (i = 0; i < strlen(fecha); i++) {
        if (fecha[i] == '-' || fecha[i] == '/') {
            printf("\n");
        }
        else printf("%c", fecha[i]);
    }
    printf("\n");
    for (i = 0; i < strlen(oracion3XL); i++) {
        if (oracion3XL[i] == ',') {
            printf("\n");
            comaCount++;
        }
        else {
            if (comaCount != 3)
                printf("%c", oracion3XL[i]);
        }
        if (comaCount == 3) {
            if (i + 1 != '\n') {
                sFloat[k] = oracion3XL[i + 1];
                k++;
            }
        }
    }
    sscanf(sFloat, "%f", &flotante2);
    printf("%.2f", flotante2);
    return 0;
}
void inputCleaning() { while (getchar() != '\n'); }
