#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
    int paginas;
    char color[20];
}sLibro;
void inputCleaning() { while (getchar() != '\n'); }
int main() {
    int estantes_totales = 0, pedidos_totales = 0, repetidos = 0, i, j = 0, k = 0, nLibros = 0, columna = 0, nLibrosFila = 0, sumatoriaLibrosFila = 0, sumatoriaLibrosFilaColor = 0, contRepetidosPrimerParametro = 0;
    (void)scanf("%d %d", &estantes_totales, &pedidos_totales);
    int* pedidos = (int*)calloc(pedidos_totales, sizeof(int));
    if (pedidos == NULL) return -1;
    int* filas = (int*)calloc(pedidos_totales, sizeof(int));
    if (filas == NULL) return -1;
    int* columnas = (int*)calloc(pedidos_totales, sizeof(int));
    if (columnas == NULL) return -1;
    int* tercerParametro = (int*)calloc(pedidos_totales, sizeof(int));
    if (tercerParametro == NULL) return -1;
    sLibro* libros = (sLibro*)calloc(pedidos_totales, sizeof(sLibro));
    if (libros == NULL) return -1;
    char** colores = (char**)calloc(pedidos_totales, sizeof(char*));
    if (colores == NULL) return -1;
    for (i = 0; i < pedidos_totales; i++) {
        colores[i] = (char*)calloc(20, sizeof(char));
        if (colores[i] == NULL) return -1;
    }
    for (i = 0; i < pedidos_totales; i++) {
        inputCleaning();
        (void)scanf("%d %d", &pedidos[i], &filas[i]);
        if (pedidos[i] == 1) {
            (void)scanf("%d %s", &tercerParametro[i], colores[i]);
            contRepetidosPrimerParametro++;
        }
        else if (pedidos[i] == 2) (void)scanf("%d", &tercerParametro[i]);
        else if (pedidos[i] == 5) (void)scanf("%s", colores[i]);
        if (filas[i] >= estantes_totales) return 0;
    }
    for (i = 0; i < contRepetidosPrimerParametro; i++) {
        for (j = i + 1; j < contRepetidosPrimerParametro; j++)
            if (filas[i] == filas[j])
                repetidos++;
        columnas[i] = repetidos + 1;
        repetidos = 0;
    }
    for (i = 0; i < pedidos_totales; i++) {
        switch (pedidos[i])
        {
        case 1:
            nLibros++;
            libros[i].x = filas[i];
            for (j = 0; j < nLibros; j++)
                if (filas[i] == libros[j].x)
                    columna++;
            libros[i].y = columna - 1;
            libros[i].paginas = tercerParametro[i];
            strcpy(libros[i].color, colores[i]);
            columna = 0;
            break;
        case 2:
            for (j = 0; j < nLibros; j++)
                if (filas[i] == libros[j].x && tercerParametro[i] == libros[j].y)
                    printf("%d %s", libros[j].paginas, libros[j].color);
            break;
        case 3:
            for (j = 0; j < nLibros; j++)
                if (filas[i] == libros[j].x) {
                    for (k = j + 1; k < columnas[j]; k++) {
                        if (strcmp(libros[j].color, libros[k].color) == 0 && libros[j].paginas == libros[k].paginas)
                            nLibrosFila--;
                    }
                    nLibrosFila++;
                }
            printf("%d", nLibrosFila);
            nLibrosFila = 0;
            break;
        case 4:
            for (j = 0; j < nLibros; j++)
                if (filas[i] == libros[j].x)
                    sumatoriaLibrosFila += libros[j].paginas;
            printf("%d", sumatoriaLibrosFila);
            sumatoriaLibrosFila = 0;
            break;
        case 5:
            for (j = 0; j < nLibros; j++)
                if (filas[i] == libros[j].x && strcmp(colores[i], libros[j].color) == 0)
                    sumatoriaLibrosFilaColor += libros[j].paginas;
            printf("%d", sumatoriaLibrosFilaColor);
            sumatoriaLibrosFilaColor = 0;
            break;
        default:
            break;
        }
        if (pedidos[i] != 1 && i < pedidos_totales - 1) printf("\n");
    }
    free(pedidos);
    free(filas);
    free(columnas);
    free(tercerParametro);
    free(libros);
    for (i = 0; i < pedidos_totales; i++) free(colores[i]);
    free(colores);
    return 0;
}