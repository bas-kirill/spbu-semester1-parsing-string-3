#include <stdio.h>
#include <string.h>
using namespace std;

const int MAXN = 256;

int main() {
    char str[MAXN];
    printf("> Enter string: ");
    fgets(str, MAXN, stdin);

    char words[MAXN];
    memset(words, '\0', MAXN);
    char *word = strtok(str, " .");
    bool first = true;
    while (word != NULL) {
        if (!first)
            strcat(words, " ");
        first = false;
        strcat(words, word);
        word = strtok(NULL, " .\n");
    }

    puts(words);

    char *lastWord = strrchr(words, ' ');
    lastWord = strtok(lastWord, " \n");
    printf("Last word: %s\n", lastWord);

    char *currentWord = strtok(words, " ");
    while (currentWord != NULL) {
        if (strcmp(lastWord, currentWord) != 0 && currentWord[0] == currentWord[strlen(currentWord) - 1])  //
            printf("%s ", currentWord);
        currentWord = strtok (NULL, " .");
    }

    return 0;
}
