#include <stdio.h>
#include <string.h>

int main() {
    int integer1 = 0, integer2 = 0, i = 0, k = 0, comaCount = 0;
    float float1 = 0, float2 = 0;
    char letter;
    char word[51];
    char sentence1[201];
    char sentence2[201];
    char sentence3XL[999];
    char date[11];
    char sFloat[999];

    scanf("%s", &word);
    scanf("%d %f", &integer1, &float1);
    inputCleaning();
    scanf("%[^\n]s", &sentence1);
    inputCleaning();
    scanf("%[^\n]s", &sentence2);
    inputCleaning();
    scanf("%[^\n]s", &date);
    inputCleaning();
    scanf("%[^\n]s", &sentence3XL);
    printf("%s\n%d\n%.2f\n%s\n%s\n", word, integer1, float1, sentence1, sentence2);
    for (i = 0; i < strlen(date); i++) {
        if (date[i] == '-' || date[i] == '/') {
            printf("\n");
        }
        else printf("%c", date[i]);
    }
    printf("\n");
    for (i = 0; i < strlen(sentence3XL); i++) {
        if (sentence3XL[i] == ',') {
            printf("\n");
            comaCount++;
        }
        else {
            if (comaCount != 3)
                printf("%c", sentence3XL[i]);
        }
        if (comaCount == 3) {
            if (i + 1 != '\n') {
                sFloat[k] = sentence3XL[i + 1];
                k++;
            }
        }
    }
    sscanf(sFloat, "%f", &float2);
    printf("%.2f", float2);
    return 0;
}

void inputCleaning() { while (getchar() != '\n'); }
