#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char description[100];
    char code[10];
    int amount;
    float unitaryPrice;
}sItem;

sItem processLine(char* linea) {
    sItem item = { 0 };
    char* separateItems = NULL;
    char* lineWithoutComa = (char*)calloc(46, sizeof(char));
    separateItems = strtok(linea, ";");
    (void)sscanf(separateItems, "%[^\n]", item.description);
    while (separateItems != NULL) {
        separateItems = strtok(NULL, ";");
        if (separateItems == NULL) break;
        strcat(lineWithoutComa, separateItems);
    }
    (void)sscanf(lineWithoutComa, "%s %d %f", item.code, &item.amount, &item.unitaryPrice);
    free(lineWithoutComa);
    return item;
}

char* processItem(sItem item) {
    char* sentence = (char*)calloc(10000, sizeof(char));
    if (sentence == NULL) return NULL;
    sprintf(sentence, "%-10s%-30s%10d%15.2f%20.2f\n", item.code, item.description, item.amount, item.unitaryPrice, (float)(item.unitaryPrice * item.amount));
    return sentence;
}

void inputCleaning() { while (getchar() != '\n'); }

int main() {
    int nItems = 0, i, j = 0, changesCount = 0;
    float total = 0;
    (void)scanf("%d", &nItems);
    sItem auxSort;
    sItem* items = (sItem*)calloc(nItems, sizeof(sItem));
    if (items == NULL) return -1;
    sItem* auxItems = (sItem*)calloc(nItems, sizeof(sItem));
    if (auxItems == NULL) return -1;
    char** lines = (char**)calloc(nItems, sizeof(char*));
    if (lines == NULL) return -1;
    for (i = 0; i < nItems; i++) {
        lines[i] = (char*)calloc(46, sizeof(char));
        if (lines[i] == NULL) return -1;
    }
    for (i = 0; i < nItems; i++) {
        inputCleaning();
        (void)scanf("%[^\n]", lines[i]);
    }
    for (i = 0; i < nItems; i++)
        items[i] = processLine(lines[i]);
    for (i = 0; i < nItems - 1; i++) {
        changesCount = 0;
        for (j = 0; j < nItems - 1; j++) {
            if (strcmp(items[j].code, items[j + 1].code) > 0) {
                auxSort = items[j];
                items[j] = items[j + 1];
                items[j + 1] = auxSort;
                changesCount++;
            }
        }
        if (changesCount == 0) break;
    }
    j = 0;
    for (i = 0; i < nItems - 1; i++) {
        if (strcmp(items[i].code, items[i + 1].code) != 0)
            auxItems[j++] = items[i];
        else items[i + 1].amount += items[i].amount;
    }
    auxItems[j++] = items[nItems - 1];
    for (i = 0; i < j; i++)
        items[i] = auxItems[i];
    nItems = j;
    for (i = 0; i < nItems; i++) {
        total += items[i].unitaryPrice * items[i].amount;
    }
    for (i = 0; i < nItems; i++)
        lines[i] = processItem(items[i]);
    printf("%-10s%-30s%10s%15s%20s\n", "Code", "Description", "Ammount", "Unitary Price", "Total");
    for (i = 0; i < nItems; i++)
        printf("%s", lines[i]);
    printf("Total: %.2f", total);
    free(auxItems);
    for (i = 0; i < nItems; i++)
        free(lines[i]);
    free(lines);
    return 0;
}