// @TODO: What if I want to use an external library
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int
main(int argc, char *argv[])
// @TODO: Are argc and *argv mandatory for main function
//
// @TODO: Assuming that the square brackets in `argv[]` means it's an
// array.
//
// @TODO: Do we need to use *str here? Is it because the argument
// is `*argv`?
{
    if (argc != 2) {
        // @TODO: What's the difference between `fprintf` and
        // `printf`?
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    // @TODO: Why *str? Is it a pointer?
    //
    // @TODO: Why is the argument `*argv` instead of just `argv`
    char *str = argv[1];
    while (1) {
        // How to find out where the function `Spin` is defined?
        Spin(1);
        printf("%s\n", str);
    }
    // @TODO: Do we explicitly need to return an integer from main function?
    return 0;
}
