//
// Created by Алина on 01.11.2023.
//

#include "../include/image.h"
#include <stdlib.h>

struct image create_image(const size_t width, const size_t height) {
    struct pixel* pixel = (struct pixel*) malloc(width * height * STRUCT_SIZE);
    if (pixel == NULL) return (struct image) {0};
    return (struct image) {
            .height = height,
            .width = width,
            .data = pixel
    };
}

void delete_image(struct image* img) {
    free(img -> data);
    img -> data = NULL;
}

uint32_t get_padding(const uint32_t width) {
    return (FACT_SIZE - (width * STRUCT_SIZE) % FACT_SIZE) % FACT_SIZE;
}
