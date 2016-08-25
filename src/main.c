//
// Created by cvelez on 8/24/2016.
//
#include "bst.h"
#include "stdio.h"
#include "stdlib.h"

void main(int argc, char** argv) {
    // display command line args
    for (int x = 0; x < argc; ++x) {
        printf("%i - %s", x, argv[x]);
    }
    exit(0);
}
