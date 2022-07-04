#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* getDiagonal(int n, int m, int** matrix) {
    int i;
    int* diag = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
        diag[i] = matrix[i][i];
    return diag;
}

int* sumRowsandColumns(int n, int m, int** matrix, int** refSumColumns) {
    int i, j, fil = 0, col = 0;
    int* sumRow = (int*)calloc(n, sizeof(int));
    if (sumRow == NULL) return NULL;
    for (i = 0; i < n; i++) {
        fil = 0;
        for (j = 0; j < m; j++) {
            fil += matrix[i][j];
        }
        sumRow[i] = fil;
    }
    for (i = 0; i < m; i++) {
        col = 0;
        for (j = 0; j < n; j++) {
            col += matrix[j][i];
        }
        (*refSumColumns)[i] = col;
    }
    return sumRow;
}

void ProcessedMatrices(int mode, int n, int m, int** matrix) {
    int i;
    int* diag, * sumDiag, * sumRow;
    int* sumColumn = (int*)calloc(m, sizeof(int));
    if (sumColumn == NULL) return;
    if (mode == 0 && n != m) {
        printf("Cannot obtain the diagonal sum of a NON square matrix");
        return;
    }
    else if (mode == 1 && n != m) {
        printf("Cannot obtain the diagonal sum of a square NON matrix");
        return;
    }
    if (mode == 0 || mode == 1) {
        diag = getDiagonal(n, m, matrix);
        if (mode == 0) {
            printf("My Diagonal:");
            for (i = 0; i < m; i++)
                printf(" %d", diag[i]);
        }
        else {
            sumDiag = sumRowsandColumns(1, m, &diag, &sumColumn);
            printf("Diagonal Sum: %d", *sumDiag);
        }
    }
    else {
        sumRow = sumRowsandColumns(n, m, matrix, &sumColumn);
        printf("Sum Of Each Row:");
        for (i = 0; i < n; i++) {
            printf(" %d", sumRow[i]);
        }
        printf("\nSum Of Each Column:");
        for (i = 0; i < m; i++) {
            printf(" %d", sumColumn[i]);
        }
    }
    free(sumColumn);
}

int main()
{

   // ProcessedMatrices(MatrixMode, high, width, inMatrix); no main

    return 0;
}
