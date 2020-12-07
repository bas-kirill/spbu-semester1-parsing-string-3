#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 256;

int main() {
    printf("%s", "> Enter input filename: ");
    char inputFilename[MAXN];
    fgets(inputFilename, MAXN, stdin);
    char *isBackslash = strrchr(inputFilename, '\n');
    if (isBackslash)
        *isBackslash = '\0';

    printf("%s", "> Enter output filename: ");
    char outputFilename[MAXN];
    fgets(outputFilename, MAXN, stdin);
    isBackslash = strrchr(inputFilename, '\n');
    if (isBackslash)
        *isBackslash = '\0';

    FILE *fileInput = fopen(inputFilename, "r");
    FILE *fileOutput = fopen(outputFilename, "a");

    char inputString[MAXN];
    fgets(inputString, MAXN, fileInput);

    char words[MAXN];
    memset(words, '\0', MAXN);
    char *word = strtok(inputString, " .");
    bool first = true;
    while (word != NULL) {
        if (!first)
            strcat(words, " ");
        first = false;
        strcat(words, word);
        word = strtok(NULL, " .\n");
    }

    fprintf(fileOutput, "%s\n", words);

    char *lastWord = strrchr(words, ' ');
    lastWord = strtok(lastWord, " \n");

    fprintf(fileOutput, "Last word: %s\n", lastWord);

    char *currentWord = strtok(words, " ");
    while (currentWord != NULL) {
        if (strcmp(lastWord, currentWord) != 0 && currentWord[0] == currentWord[strlen(currentWord) - 1])  //
            fprintf(fileOutput, "%s ", currentWord);
        currentWord = strtok (NULL, " .");
    }

    fclose(fileInput);
    fclose(fileOutput);
    return 0;
}
