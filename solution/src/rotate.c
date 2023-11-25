//
// Created by Алина on 01.11.2023.
//

#include "../include/rotate.h"
#include "../include/image.h"
#include <stdint.h>

static void rotate90(struct image const* oldImage, struct image* newImage) {
    for (size_t i = 0; i < newImage->height; i++) {
        for (size_t j = 0; j < newImage->width; j++) {
            newImage->data[i * newImage->width + j] = oldImage->data[(j + 1) * oldImage->width - i - 1];
        }
    }
}

static void rotate180(struct image const* oldImage, struct image* newImage) {
    for (size_t i = 0; i < newImage->height; i++) {
        for (size_t j = 0; j < newImage->width; j++) {
            newImage->data[oldImage->height * oldImage->width - i * oldImage->width - j - 1] = oldImage->data[i * oldImage->width + j];
        }
    }
}

static void rotate270(struct image const* oldImage, struct image* newImage) {
    for (size_t i = 0; i < newImage->width; i++) {
        for (size_t j = 0; j < newImage->height; j++) {
            newImage->data[(j + 1) * newImage->width - i - 1] = oldImage->data[i * oldImage->width + j];
        }
    }
}

struct image rotate(struct image const* source, int angle) {
    struct image rotated_image = {0};
    switch (angle) {
        case 90:
        case -270:
            rotated_image = create_image(source->height, source->width);
            if(rotated_image.data)
                rotate90(source, &rotated_image);
            break;
        case 180:
        case -180:
            rotated_image = create_image(source->width, source->height);
            if(rotated_image.data)
                rotate180(source, &rotated_image);
            break;
        case 270:
        case -90:
            rotated_image = create_image(source->height, source->width);
            if(rotated_image.data)
                rotate270(source, &rotated_image);
            break;
        default:
            rotated_image = create_image(source->width, source->height);
            for (size_t i = 0; i < source->width * source->height; i++){
                rotated_image.data[i] = source->data[i];
            }
            break;
    }
    return rotated_image;
}
