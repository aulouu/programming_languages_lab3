//
// Created by Алина on 01.11.2023.
//

#include "../include/bmp.h"
#include <stdlib.h>

struct bmp_header create_new_bmp_header(struct image const* img) {
    uint32_t size = img -> height * (img -> width * STRUCT_SIZE + get_padding(img -> width));
    return (struct bmp_header) {
        .bfType = BMP_TYPE,
        .bfileSize = size + BMP_STRUCT_SIZE,
        .bfReserved = ZERO,
        .bOffBits = BMP_STRUCT_SIZE,
        .biSize = BMP_SIZE,
        .biWidth = img -> width,
        .biHeight = img -> height,
        .biPlanes = BMP_PLANES,
        .biBitCount = BIT_COUNT,
        .biCompression = BMP_COMPRESSION_TYPE,
        .biSizeImage = size,
        .biXPelsPerMeter = PELS_PER_METER,
        .biYPelsPerMeter = PELS_PER_METER,
        .biClrUsed = ZERO,
        .biClrImportant = ZERO
    };
}

enum read_status from_bmp(FILE* in, struct image* img) {
    if (!in || !img) return READ_INVALID_SIGNATURE;
    struct bmp_header* header = malloc(BMP_STRUCT_SIZE);
    if (!fread(header, BMP_STRUCT_SIZE, 1, in))
        return READ_INVALID_HEADER;
    *img = create_image(header -> biWidth, header -> biHeight);
    for (size_t i = 0; i < img -> height; i++) {
        if (!fread(img -> data + i * img -> width, STRUCT_SIZE, img -> width, in)){
            delete_image(img);
            return READ_INVALID_BITS;
        }
        if (fseek(in, get_padding(img -> width), SEEK_CUR)) {
            delete_image(img);
            return READ_INVALID_BITS;
        }

    }
    return READ_OK;
}

enum write_status to_bmp(FILE* out, struct image const* img) {
    if (!out || !img) return WRITE_ERROR;
    struct bmp_header header = create_new_bmp_header(img);
    if (!fwrite(&header, BMP_STRUCT_SIZE, 1, out))
        return WRITE_ERROR;
    for (size_t i = 0; i < img -> height; i++) {
        if (!fwrite(img -> data + i * img -> width, STRUCT_SIZE, img -> width, out))
            return WRITE_ERROR;
        if (fseek(out, get_padding(img -> width), SEEK_CUR))
            return WRITE_ERROR;
    }
    return WRITE_OK;
}
