#include <limits.h>
#include <stdio.h>

int main(void)
{
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Could not open numbers.txt");
        return 1;
    }

    long long sum = 0;
    long long number;
    size_t count = 0;
    int result;

    while ((result = fscanf(file, "%lld", &number)) == 1) {
        if ((number > 0 && sum > LLONG_MAX - number) ||
            (number < 0 && sum < LLONG_MIN - number)) {
            fprintf(stderr, "The sum exceeds the supported range.\n");
            fclose(file);
            return 1;
        }

        sum += number;
        count++;
    }

    if (result != EOF) {
        fprintf(stderr, "numbers.txt contains invalid data.\n");
        fclose(file);
        return 1;
    }

    if (ferror(file)) {
        perror("Could not read numbers.txt");
        fclose(file);
        return 1;
    }

    if (fclose(file) == EOF) {
        perror("Could not close numbers.txt");
        return 1;
    }

    if (count == 0) {
        fprintf(stderr, "numbers.txt contains no integers.\n");
        return 1;
    }

    printf("Sum: %lld\n", sum);
    printf("Average: %.2f\n", (double)sum / (double)count);
    return 0;
}
