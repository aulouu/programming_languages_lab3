//
// Created by Алина on 01.11.2023.
//

#ifndef IMAGE_TRANSFORMER_IMAGE_H
#define IMAGE_TRANSFORMER_IMAGE_H

#include  <stdint.h>

#define STRUCT_SIZE sizeof(struct pixel)
#define FACT_SIZE 4

struct image {
    uint64_t width, height;
    struct pixel* data;
};

struct pixel {
    uint8_t b, g, r;
};

struct image create_image(const size_t width, const size_t height);

void delete_image(struct image* img);

uint32_t get_padding(const uint32_t width);

#endif //IMAGE_TRANSFORMER_IMAGE_H
