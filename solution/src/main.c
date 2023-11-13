#include <stdio.h>
#include "../include/file.h"

int main(int argc, char** argv) {

    if (argc != 4) {
        fprintf(stderr, "There must be 3 arguments. <source-image> <transformed-image> <angle>");
        return 1;
    }

    FILE* source = open(argv[1], "rb");
    FILE* transformed = open(argv[2], "wb");
    if (source == NULL) {
        fprintf(stderr, "Error with reading");
        return 1;
    }
    if (transformed == NULL) {
        fprintf(stderr, "Error with writing");
        return 1;
    }

    return 0;
}
