#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHABET_SIZE 26

void normalizeString(const char *input, char *output)
{
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (ch == '\n' || ch == '\r' || ch == ' ') {
            continue;
        }

        if (isalpha((unsigned char)ch)) {
            output[j++] = (char)tolower((unsigned char)ch);
        }
    }

    output[j] = '\0';
}

int areAnagrams(const char *str1, const char *str2)
{
    int freq1[ALPHABET_SIZE] = {0};
    int freq2[ALPHABET_SIZE] = {0};

    for (int i = 0; str1[i] != '\0'; i++) {
        int index = str1[i] - 'a';
        if (index >= 0 && index < ALPHABET_SIZE) {
            freq1[index]++;
        }
    }

    for (int i = 0; str2[i] != '\0'; i++) {
        int index = str2[i] - 'a';
        if (index >= 0 && index < ALPHABET_SIZE) {
            freq2[index]++;
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (freq1[i] != freq2[i]) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    char first[200], second[200];
    char normalized1[200], normalized2[200];

    printf("Enter first string: ");
    if (fgets(first, sizeof(first), stdin) == NULL) {
        printf("Input error!\n");
        return 1;
    }

    printf("Enter second string: ");
    if (fgets(second, sizeof(second), stdin) == NULL) {
        printf("Input error!\n");
        return 1;
    }

    normalizeString(first, normalized1);
    normalizeString(second, normalized2);

    if (areAnagrams(normalized1, normalized2) && strlen(normalized1) == strlen(normalized2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }

    return 0;
}
