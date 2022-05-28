#define _CRT_SECURE_NO_WARNINGS
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
#define PI 3.14159265359
char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'Perimetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY longitudes as parameter.
 */

int Perimetro(int longitudes_count, int* longitudes) {
    if (longitudes_count == 1) return 2 * PI * longitudes[0];
    else if (longitudes_count == 3) return longitudes[0] + longitudes[1] + longitudes[2];
    else return (longitudes[0] * 2) + (longitudes[1] * 2);
}

/*
 * Complete the 'Area' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY longitudes as parameter.
 */

int Area(int longitudes_count, int* longitudes) {
    if (longitudes_count == 1) return PI * pow(longitudes[0], 2);
    else if (longitudes_count == 3) return (longitudes[0] * longitudes[1]) / 2;
    else return longitudes[0] * longitudes[1];
}

/*
 * Complete the 'TipoFigura' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY longitudes as parameter.
 */

 /*
  * To return the string from the function, you should either do static allocation or dynamic allocation
  *
  * For example,
  * char* return_string_using_static_allocation() {
  *     static char s[] = "static allocation of string";
  *
  *     return s;
  * }
  *
  * char* return_string_using_dynamic_allocation() {
  *     char* s = malloc(100 * sizeof(char));
  *
  *     s = "dynamic allocation of string";
  *
  *     return s;
  * }
  *
  */
char* TipoFigura(int longitudes_count, int* longitudes) {
    if (longitudes_count == 1) return "Circulo";
    else if (longitudes_count == 3) return "Triangulo Rectangulo";
    else {
        if (longitudes[0] == longitudes[1]) return "Cuadrado";
        else return "Rectangulo";
    }

}

/*
 * Complete the 'RecorriendoArray' function below.
 *
 * The function accepts INTEGER_ARRAY longitudes as parameter.
 */

void RecorriendoArray(int longitudes_count, int* longitudes) {
    int area = 0, perimetro = 0;
    char* figura = TipoFigura(longitudes_count, longitudes);
    area = Area(longitudes_count, longitudes);
    perimetro = Perimetro(longitudes_count, longitudes);
    printf("%s\nArea [%d]\nPerimetro [%d]", figura, area, perimetro);
    return;
}

int main()
{
    int lados = parse_int(ltrim(rtrim(readline())));

    char** LongitudLados_temp = split_string(rtrim(readline()));

    int* LongitudLados = malloc(lados * sizeof(int));

    for (int i = 0; i < lados; i++) {
        int LongitudLados_item = parse_int(*(LongitudLados_temp + i));

        *(LongitudLados + i) = LongitudLados_item;
    }

    RecorriendoArray(lados, LongitudLados);

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

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
