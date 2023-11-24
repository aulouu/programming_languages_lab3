#include <stdio.h>
#include <stdlib.h>
#include "../include/file.h"
#include "../include/bmp.h"
#include "../include/rotate.h"

int main(int argc, char** argv) {

    if (argc != 4) {
        fprintf(stderr, "There must be 3 arguments. <source-image> <transformed-image> <angle>");
        return 1;
    }

    FILE* input = open(argv[1], "rb");
    FILE* output = open(argv[2], "wb");

    if (input == NULL) {
        fprintf(stderr, "Error with opening input file");
        return 1;
    }
    if (output == NULL) {
        fprintf(stderr, "Error with opening output file");
        return 1;
    }

    struct image* img = malloc(sizeof(struct image));

    if (from_bmp(input, img) != READ_OK) {
        fprintf(stderr, "Error with reading image");
        return 1;
    }

    int angle = atoi(argv[3]);
    if (angle % 90 != 0) {
        fprintf(stderr, "Angle is not correct");
    }

    struct image rotated_image = rotate(img, angle);

    if (rotated_image.data == NULL) {
        fprintf(stderr, "Image did not transform");
        return 1;
    }

    if (to_bmp(output, &rotated_image) != WRITE_OK) {
        fprintf(stderr, "Error with writing image");
        return 1;
    }

    fclose(input);
    fclose(output);
    delete_image(img);
    delete_image(&rotated_image);

    return 0;
}
