#include <stdio.h>

int main(void)
{
    long long num;
    int freq[10] = {0};
    int maxCount = 0;
    int mostFrequentDigit = 0;

    printf("Enter an integer: ");
    scanf("%lld", &num);

    if (num < 0)
        num = -num;

    if (num == 0) {
        printf("Most frequent digit: 0\n");
        return 0;
    }

    while (num > 0) {
        int digit = num % 10;
        freq[digit]++;
        num /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            mostFrequentDigit = i;
        }
    }

    printf("The digit that occurs the most is: %d\n", mostFrequentDigit);

    return 0;
}
