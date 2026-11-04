#include <stdio.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main(void)
{
    enum TrafficLight light = RED;

    switch (light) {
        case RED:
            printf("Stop\n");
            break;
        case YELLOW:
            printf("Wait\n");
            break;
        case GREEN:
            printf("Go\n");
            break;
        default:
            fprintf(stderr, "Invalid traffic light value.\n");
            return 1;
    }

    return 0;
}