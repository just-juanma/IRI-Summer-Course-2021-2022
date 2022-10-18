#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char* dividers, char* phrase) {
    char* pch = NULL;
    int count = 0, spaceCount = 0;
    char* cpyPhrase = (char*)calloc(strlen(phrase) + 1, sizeof(char));
    if (cpyPhrase == NULL) return -1;
    char* buffer = (char*)calloc(strlen(phrase) + 1, sizeof(char));
    if (buffer == NULL) return -1;
    sprintf(cpyPhrase, "%s", phrase);
    pch = strtok(cpyPhrase, dividers);
    while (pch != NULL) {
        count++;
        if (strlen(pch) >= 2 && strlen(pch) <= 4)
            wordRotator(pch, strlen(pch) / 2);
        strcat(buffer, pch);
        spaceCount += strlen(pch);
        buffer[spaceCount + (count - 1)] = ' ';
        pch = strtok(NULL, dividers);
    }
    printf("Words count [%d]\tCharacters count [%d]\nPhrase: %s", count, strlen(phrase), buffer);
    free(cpyPhrase);
    free(buffer);
    return count;

}

void wordRotator(char* word, int halfWordLength) {
    int totalLength = strlen(word), i, aux = 0;
    for (i = 0; i < halfWordLength; i++) {
        aux = word[i];
        word[i] = word[totalLength - i - 1];
        word[totalLength - i - 1] = aux;
    }
    return;

}

void cadenaFinal(char* vocales, char* separadores, char* frase) {
    int cantPalabras = countWords(separadores, frase);

}

int main()
{
    // no testing main
    return 0;
}