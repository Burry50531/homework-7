#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Random [0.0, 1.0]: %f\n", (double)rand() / RAND_MAX);

    double n = 10.0;
    printf("Random [0.0, %.1f]: %f\n", n, ((double)rand() / RAND_MAX) * n);

    return 0;
}
