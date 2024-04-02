#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("child (pid: %d)\n", (int) getpid());
        char *myargs[3];
        // @TODO: What does strdup do? Why it's needed?
        myargs[0] = strdup("wc");      // program: "wc"
        myargs[1] = strdup("p3.c");    // arg: input file
        // @TODO: Why is an additional element in the array required?
        myargs[2] = NULL;              // mark end of array
        // @TODO: Why is the first arg passed separately? What if it's
        // different from the one present in the array passed as 2nd
        // arg?
        // [ref: syscall_exec]
        execvp(myargs[0], myargs);     // runs word count
        printf("this shouldn't print out\n");
    } else {
        // parent goes down this path
        int rc_wait = wait(NULL);
        printf("parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}

