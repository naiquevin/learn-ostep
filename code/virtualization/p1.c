#include <stdio.h>
#include <stdlib.h>
// @TODO: What is this `unistd.h` header file and exactly which
// functions are coming from it.
#include <unistd.h>

int
main(int argc, char *argv[])
{
    // @TODO: Why is casting to int required here? It wasn't required
    // in `../intro/mem.c`
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (main)
        printf("parent of %d (pid: %d)\n", rc, (int) getpid());
    }
    return 0;
}
