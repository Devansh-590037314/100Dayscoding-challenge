#include <stdio.h>

int main(void)
{
    long long totalSeconds;

    printf("Enter time in seconds: ");
    if (scanf("%lld", &totalSeconds) != 1 || totalSeconds < 0) {
        printf("Please enter a non-negative whole number of seconds.\n");
        return 1;
    }

    long long hours = totalSeconds / 3600;
    long long minutes = (totalSeconds % 3600) / 60;
    long long seconds = totalSeconds % 60;

    printf("%02lld:%02lld:%02lld\n", hours, minutes, seconds);

    return 0;
}