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
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

float parse_float(char*);
int parse_int(char*);

/*
 * Complete the 'SuperImpresora' function below.
 *
 * The function accepts following parameters:
 *  1. STRING calle
 *  2. INTEGER numero
 *  3. INTEGER piso
 *  4. CHARACTER letra
 *  5. FLOAT saldo
 *  6. INTEGER numero_width
 *  7. INTEGER piso_width
 *  8. INTEGER llenar_con_cero
 */

void SuperImpresora(char* calle, int numero, int piso, char letra, float saldo, int numero_width, int piso_width, int llenar_con_cero) {
    if (strlen(calle) > 20) return;
    if (llenar_con_cero == 1) {
        printf("%-20s %0*d %0*d %c %15.*f\n", calle, numero_width, numero, piso_width, piso, letra, numero_width, saldo);
    }
    else printf("%-20s %*d %*d %c %15.*f\n", calle, numero_width, numero, piso_width, piso, letra, numero_width, saldo);
    return;

}

int main()
{
    int lines = parse_int(ltrim(rtrim(readline())));

    for (int lines_itr = 0; lines_itr < lines; lines_itr++) {
        char** first_multiple_input = split_string(rtrim(readline()));

        char* calle = *(first_multiple_input + 0);

        int numero = parse_int(*(first_multiple_input + 1));

        int piso = parse_int(*(first_multiple_input + 2));

        char* letra = **(first_multiple_input + 3);

        float saldo = parse_float(*(first_multiple_input + 4));

        int numero_width = parse_int(*(first_multiple_input + 5));

        int piso_width = parse_int(*(first_multiple_input + 6));

        int llenar_con_cero = parse_int(*(first_multiple_input + 7));

        SuperImpresora(calle, numero, piso, letra, saldo, numero_width, piso_width, llenar_con_cero);
    }

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

float parse_float(char* str) {
    char* endptr;
    float value = strtof(str, &endptr);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
