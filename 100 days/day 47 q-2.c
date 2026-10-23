#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int main(void)
{
    char sentence[MAX_LENGTH];
    int longestStart = 0;
    int longestLength = 0;
    int currentStart = 0;

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        fprintf(stderr, "Could not read the sentence.\n");
        return 1;
    }

    while (sentence[currentStart] != '\0' && sentence[currentStart] != '\n') {
        if (isalpha((unsigned char)sentence[currentStart])) {
            int start = currentStart;
            int length = 0;

            while (isalpha((unsigned char)sentence[currentStart])) {
                length++;
                currentStart++;
            }

            if (length > longestLength) {
                longestStart = start;
                longestLength = length;
            }
        } else {
            currentStart++;
        }
    }

    if (sentence[currentStart] == '\0' && currentStart == MAX_LENGTH - 1) {
        int nextCharacter = getchar();
        if (nextCharacter != '\n' && nextCharacter != EOF) {
            fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
            return 1;
        }
    }

    if (longestLength > 0) {
        printf("Longest word: %.*s\n", longestLength, sentence + longestStart);
    } else {
        printf("No words found.\n");
    }

    return 0;
}