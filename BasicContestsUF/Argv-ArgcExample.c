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

int parse_int(char*);

/*
 * Complete the 'MainWithArgs' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER argc
 *  2. STRING_ARRAY argv
 */

void MainWithArgs(int argc, int argv_count, char** argv) {
    int i = 0, j = 0;
    float numArgv1 = 0, numArgv2 = 0;
    if (argc != 4) {
        printf("ERROR 1");
        return;
    }
    for (i = 1; i < 4; i += 2) {
        for (j = 0; j < strlen(argv[i]); j++) {
            if (!(argv[i][j] == '-' || argv[i][j] == '.' || (argv[i][j] < 58 && argv[i][j] > 47))) {
                printf("ERROR %d", i + 1);
                return;
            }
        }
    }
    sscanf(argv[1], "%f", &numArgv1);
    sscanf(argv[3], "%f", &numArgv2);
    if (strcmp(argv[2], "+") == 0) {
        printf("%.2f", numArgv1 + numArgv2);
    }
    else if (strcmp(argv[2], "-") == 0) {
        printf("%.2f", numArgv1 - numArgv2);
    }
    else if (strcmp(argv[2], "*") == 0) {
        printf("%.2f", numArgv1 * numArgv2);
    }
    else if (strcmp(argv[2], "/") == 0) {
        if (numArgv2 == 0) return;
        printf("%.2f", numArgv1 / numArgv2);
    }
    else if (strcmp(argv[2], "%") == 0) {
        printf("%.2f", (numArgv1 * numArgv2) / 100);
    }
    else  printf("ERROR 3");
    return;
}

int main()
{
    // No le den bola a (int argv_rows, int argv_columns,) son cosas que agrega el generador de codigo

    int argc = parse_int(ltrim(rtrim(readline())));

    char** argv_temp = split_string(rtrim(readline()));

    char** argv = malloc(argc * sizeof(char*));

    for (int i = 0; i < argc; i++) {
        char* argv_item = *(argv_temp + i);

        *(argv + i) = argv_item;
    }

    MainWithArgs(argc, argc, argv);

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