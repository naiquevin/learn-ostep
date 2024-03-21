#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int
main(int argc, char *argv[]) {
    // @TODO: Assumption: p is a pointer and *p dereferences the
    // pointer i.e. it's the value in memory that the pointer points
    // to. Is this correct? Also, the int in the type declaration is
    // type of the pointer and not the value.
    int *p = malloc(sizeof(int));                               // a1
    // @TODO: Assumption: Checking !NULL here to ensure that the
    // memory is allocated.
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p);  // a2
    *p = 0;                                                     // a3
    while (1) {
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);                   // a4
    }
    return 0;
}
