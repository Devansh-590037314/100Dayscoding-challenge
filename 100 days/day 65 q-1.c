#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000];
    char t[1000];
    int frequencies[26] = {0};

    if (scanf("%999s %999s", s, t) != 2) {
        return 1;
    }

    if (strlen(s) != strlen(t)) {
        printf("Not Anagram\n");
        return 0;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        frequencies[s[i] - 'a']++;
        frequencies[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (frequencies[i] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");
    return 0;
}