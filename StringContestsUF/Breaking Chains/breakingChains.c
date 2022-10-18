#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestWord(int wordCount, char** words, int* wordPosition) {
    int i, num = 0, max = 0;
    for (i = 0; i < wordCount; i++) {
        num = strlen(words[i]);
        if (i == 0 || num > max) {
            *wordPosition = i;
            max = num;
        }
    }
    return max;
}

int totalNumberOfWords(char* dividers, char* sentence) {
    char* pch = NULL;
    int count = 0;
    char* cpySentence = (char*)calloc(strlen(sentence) + 1, sizeof(char));
    if (cpySentence == NULL) return -1;
    strcpy(cpySentence, sentence);
    pch = strtok(cpySentence, dividers);
    while (pch != NULL) {
        count++;
        pch = strtok(NULL, dividers);
    }
    free(cpySentence);
    return count;

}

char** dividingWords(char* sentence, char* dividers, int* wordsNumber) {
    int i;
    char* pch = NULL;
    char* cpySentence = (char*)calloc(strlen(sentence) + 1, sizeof(char));
    if (cpySentence == NULL) return NULL;
    strcpy(cpySentence, sentence);
    *wordsNumber = totalNumberOfWords(dividers, cpySentence);
    char** wordsMatrix = (char**)calloc(*wordsNumber, sizeof(char*));
    if (wordsMatrix == NULL) return NULL;
    pch = strtok(cpySentence, dividers);
    for (i = 0; pch != NULL; i++) {
        wordsMatrix[i] = (char*)calloc(strlen(pch), sizeof(char));
        if (wordsMatrix[i] == NULL) return NULL;
        wordsMatrix[i] = pch;
        pch = strtok(NULL, dividers);
    }
    return wordsMatrix;

}

void breakingChains(char* dividers, char* sentence) {
    int wordsTotalNumber = 0, wordPosition = 0, wordsNumber;
    char** matrix = dividingWords(sentence, dividers, &wordsTotalNumber);
    if (matrix == NULL) return -1;
    wordsNumber = longestWord(wordsTotalNumber, matrix, &wordPosition);
    printf("There are %d words, but the longest [%s -> %d words]", wordsTotalNumber, matrix[wordPosition], wordsNumber);

}

int main()
{
    // no testing main
    return 0;
}