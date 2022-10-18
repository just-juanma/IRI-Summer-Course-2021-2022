#include <stdio.h>
#include <string.h>

void MainWithArgs(int argc, char** argv) {
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
    // no testing main
    
    return 0;
}
