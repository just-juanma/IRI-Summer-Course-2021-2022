#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringSearch(char* word, char* myPhrase) {
    int repeatedWords = 0, vowelsCounterA = 0, vowelsCounterE = 0, vowelsCounterI = 0, vowelsCounterO = 0, vowelsCounterU = 0, i = 0, nullTester = 0;
    char cpyMyPhrase[9999];
    char* sameString;
    char* vowel;
    char vowelSaved[9999];
    myPhrase[0] = tolower(myPhrase[0]);
    word[0] = tolower(word[0]);
    strcpy(cpyMyPhrase, myPhrase);
    sameString = strstr(myPhrase, word);
    if (sameString == NULL) {
        printf("Palabra Repetida [%d]\t", repeatedWords);
        nullTester = 1;
    }
    else if (sameString[strlen(word)] == ' ' || sameString[strlen(word)] == '\0') repeatedWords++;
    while (sameString != NULL) {
        for (i = 0; i < strlen(word); i++) {
            sameString[i] = ' ';
        }
        sameString = strstr(myPhrase, word);
        if (sameString == NULL) break;
        else if (sameString[strlen(word)] == ' ' || sameString[strlen(word)] == '\0') repeatedWords++;
    }
    if (nullTester == 0) {
        printf("Repeated word [%d]\t", repeatedWords);
    }
    vowel = strpbrk(cpyMyPhrase, "aeiou");
    for (i = 0; vowel != NULL; i++) {
        vowelSaved[i] = vowel[0];
        vowel = strpbrk(vowel + 1, "aeiou");
    }
    for (i = 0; i < strlen(vowelSaved); i++) {
        if (vowelSaved[i] == 'a') vowelsCounterA++;
        else if (vowelSaved[i] == 'e') vowelsCounterE++;
        else if (vowelSaved[i] == 'i') vowelsCounterI++;
        else if (vowelSaved[i] == 'o') vowelsCounterO++;
        else if (vowelSaved[i] == 'u') vowelsCounterU++;
    }
    printf("A[%d]-E[%d]-I[%d]-O[%d]-U[%d]", vowelsCounterA, vowelsCounterE, vowelsCounterI, vowelsCounterO, vowelsCounterU);
    return;
}

int main()
{
   // no testing main
   return 0;
}