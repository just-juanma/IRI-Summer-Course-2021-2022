#include <stdio.h>
#include <string.h>

typedef struct {
    int x;
    int y;
    int pages;
    char color[20];
}sBook;

void inputCleaning() { while (getchar() != '\n'); }
int main() {
    int total_shelves = 0, total_orders = 0, repeated = 0, i, j = 0, k = 0, nBooks = 0, column = 0, nBooksRow = 0, sumBooksRow = 0, sumBooksRowColor = 0, contRepeatedFirstParameter = 0;
    (void)scanf("%d %d", &total_shelves, &total_orders);
    int* requests = (int*)calloc(total_orders, sizeof(int));
    if (requests == NULL) return -1;
    int* rows = (int*)calloc(total_orders, sizeof(int));
    if (rows == NULL) return -1;
    int* columns = (int*)calloc(total_orders, sizeof(int));
    if (columns == NULL) return -1;
    int* thirdParameter = (int*)calloc(total_orders, sizeof(int));
    if (thirdParameter == NULL) return -1;
    sBook* books = (sBook*)calloc(total_orders, sizeof(sBook));
    if (books == NULL) return -1;
    char** colors = (char**)calloc(total_orders, sizeof(char*));
    if (colors == NULL) return -1;
    for (i = 0; i < total_orders; i++) {
        colors[i] = (char*)calloc(20, sizeof(char));
        if (colors[i] == NULL) return -1;
    }
    for (i = 0; i < total_orders; i++) {
        inputCleaning();
        (void)scanf("%d %d", &requests[i], &rows[i]);
        if (requests[i] == 1) {
            (void)scanf("%d %s", &thirdParameter[i], colors[i]);
            contRepeatedFirstParameter++;
        }
        else if (requests[i] == 2) (void)scanf("%d", &thirdParameter[i]);
        else if (requests[i] == 5) (void)scanf("%s", colors[i]);
        if (rows[i] >= total_shelves) return 0;
    }
    for (i = 0; i < contRepeatedFirstParameter; i++) {
        for (j = i + 1; j < contRepeatedFirstParameter; j++)
            if (rows[i] == rows[j])
                repeated++;
        columns[i] = repeated + 1;
        repeated = 0;
    }
    for (i = 0; i < total_orders; i++) {
        switch (requests[i])
        {
        case 1:
            nBooks++;
            books[i].x = rows[i];
            for (j = 0; j < nBooks; j++)
                if (rows[i] == books[j].x)
                    column++;
            books[i].y = column - 1;
            books[i].pages = thirdParameter[i];
            strcpy(books[i].color, colors[i]);
            column = 0;
            break;
        case 2:
            for (j = 0; j < nBooks; j++)
                if (rows[i] == books[j].x && thirdParameter[i] == books[j].y)
                    printf("%d %s", books[j].pages, books[j].color);
            break;
        case 3:
            for (j = 0; j < nBooks; j++)
                if (rows[i] == books[j].x) {
                    for (k = j + 1; k < columns[j]; k++) {
                        if (strcmp(books[j].color, books[k].color) == 0 && books[j].pages == books[k].pages)
                            nBooksRow--;
                    }
                    nBooksRow++;
                }
            printf("%d", nBooksRow);
            nBooksRow = 0;
            break;
        case 4:
            for (j = 0; j < nBooks; j++)
                if (rows[i] == books[j].x)
                    sumBooksRow += books[j].pages;
            printf("%d", sumBooksRow);
            sumBooksRow = 0;
            break;
        case 5:
            for (j = 0; j < nBooks; j++)
                if (rows[i] == books[j].x && strcmp(colors[i], books[j].color) == 0)
                    sumBooksRowColor += books[j].pages;
            printf("%d", sumBooksRowColor);
            sumBooksRowColor = 0;
            break;
        default:
            break;
        }
        if (requests[i] != 1 && i < total_orders - 1) printf("\n");
    }
    free(requests);
    free(rows);
    free(columns);
    free(thirdParameter);
    free(books);
    for (i = 0; i < total_orders; i++) free(colors[i]);
    free(colors);
    return 0;
}