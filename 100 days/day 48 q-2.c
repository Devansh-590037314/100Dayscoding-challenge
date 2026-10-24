#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(void)
{
    char sentence[MAX_LENGTH];

    printf("Enter a sentence: ");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL) {
        fprintf(stderr, "Could not read the sentence.\n");
        return 1;
    }

    size_t length = strlen(sentence);
    if (length > 0 && sentence[length - 1] == '\n') {
        sentence[length - 1] = '\0';
    } else if (length == sizeof(sentence) - 1 && !strchr(sentence, '\n')) {
        int extraChar = getchar();
        while (extraChar != '\n' && extraChar != EOF) {
            extraChar = getchar();
        }
        fprintf(stderr, "Input is too long. Enter at most %d characters.\n", MAX_LENGTH - 1);
        return 1;
    }

    int i = 0;
    while (sentence[i] != '\0') {
        while (sentence[i] != '\0' && isspace((unsigned char)sentence[i])) {
            i++;
        }

        if (sentence[i] == '\0') {
            break;
        }

        int start = i;
        while (sentence[i] != '\0' && !isspace((unsigned char)sentence[i])) {
            i++;
        }

        int end = i - 1;
        while (start < end) {
            char temp = sentence[start];
            sentence[start] = sentence[end];
            sentence[end] = temp;
            start++;
            end--;
        }
    }

    printf("Reversed words: %s\n", sentence);
    return 0;
}
