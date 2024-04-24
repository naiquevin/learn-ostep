#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

long current_ts_micros()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    long micros = t.tv_sec * 1000000 + t.tv_usec;
    return micros;
}

int main(int argc, char *argv[])
{
    long num_iter;

    if (argc == 2) {
        num_iter = strtol(argv[1], NULL, 10);
    } else {
        num_iter = 1000;
    }

    printf("Number of iterations: %lu\n", num_iter);

    int n = num_iter;

    long start = current_ts_micros();
    printf("Before: %lu\n", start);

    while (n > 0) {
        read(0, NULL, 0);
        n--;
    }

    long end = current_ts_micros();
    printf("After: %lu\n", end);

    long elapsed = end - start;
    printf("Total time elapsed: %lu\n", elapsed);

    double duration = ((double)elapsed * 1000) / num_iter;
    printf("Per syscall duration (approx): %f nanosecs\n", duration);
    return 0;
}
