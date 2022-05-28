#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    char descripcion[100];
    char codigo[10];
    int cantidad;
    float precio_unitario;
}sItem;

sItem ProcessLine(char* linea) {
    sItem item = { 0 };
    char* separateItems = NULL;
    char* lineaSinComa = (char*)calloc(46, sizeof(char));
    separateItems = strtok(linea, ";");
    (void)sscanf(separateItems, "%[^\n]", item.descripcion);
    while (separateItems != NULL) {
        separateItems = strtok(NULL, ";");
        if (separateItems == NULL) break;
        strcat(lineaSinComa, separateItems);
    }
    (void)sscanf(lineaSinComa, "%s %d %f", item.codigo, &item.cantidad, &item.precio_unitario);
    free(lineaSinComa);
    return item;
}
char* ProcesarItem(sItem item) {
    char* oracion = (char*)calloc(10000, sizeof(char));
    if (oracion == NULL) return NULL;
    sprintf(oracion, "%-10s%-30s%10d%15.2f%20.2f\n", item.codigo, item.descripcion, item.cantidad, item.precio_unitario, (float)(item.precio_unitario * item.cantidad));
    return oracion;
}

void inputCleaning() { while (getchar() != '\n'); }

int main() {
    int nItems = 0, i, j = 0, contCambios = 0;
    float total = 0;
    (void)scanf("%d", &nItems);
    sItem auxSort;
    sItem* items = (sItem*)calloc(nItems, sizeof(sItem));
    if (items == NULL) return -1;
    sItem* auxItems = (sItem*)calloc(nItems, sizeof(sItem));
    if (auxItems == NULL) return -1;
    char** lineas = (char**)calloc(nItems, sizeof(char*));
    if (lineas == NULL) return -1;
    for (i = 0; i < nItems; i++) {
        lineas[i] = (char*)calloc(46, sizeof(char));
        if (lineas[i] == NULL) return -1;
    }
    for (i = 0; i < nItems; i++) {
        inputCleaning();
        (void)scanf("%[^\n]", lineas[i]);
    }
    for (i = 0; i < nItems; i++)
        items[i] = ProcessLine(lineas[i]);
    for (i = 0; i < nItems - 1; i++) {
        contCambios = 0;
        for (j = 0; j < nItems - 1; j++) {
            if (strcmp(items[j].codigo, items[j + 1].codigo) > 0) {
                auxSort = items[j];
                items[j] = items[j + 1];
                items[j + 1] = auxSort;
                contCambios++;
            }
        }
        if (contCambios == 0) break;
    }
    j = 0;
    for (i = 0; i < nItems - 1; i++) {
        if (strcmp(items[i].codigo, items[i + 1].codigo) != 0)
            auxItems[j++] = items[i];
        else items[i + 1].cantidad += items[i].cantidad;
    }
    auxItems[j++] = items[nItems - 1];
    for (i = 0; i < j; i++)
        items[i] = auxItems[i];
    nItems = j;
    for (i = 0; i < nItems; i++) {
        total += items[i].precio_unitario * items[i].cantidad;
    }
    for (i = 0; i < nItems; i++)
        lineas[i] = ProcesarItem(items[i]);
    printf("%-10s%-30s%10s%15s%20s\n", "Codigo", "Descripcion", "Cantidad", "Precio", "Total");
    for (i = 0; i < nItems; i++)
        printf("%s", lineas[i]);
    printf("Total: %.2f", total);
    free(auxItems);
    for (i = 0; i < nItems; i++)
        free(lineas[i]);
    free(lineas);
    return 0;
}