//
// Created by Алина on 01.11.2023.
//

#ifndef IMAGE_TRANSFORMER_BMP_H
#define IMAGE_TRANSFORMER_BMP_H

#include <image.h>
#include <stdint.h>
#include <stdio.h>

#define BMP_STRUCT_SIZE sizeof(struct bmp_header)
#define BMP_TYPE 0x4D42
#define ZERO 0
#define BMP_SIZE 40
#define BMP_PLANES 1
#define BIT_COUNT 24
#define BMP_COMPRESSION_TYPE 0
#define PELS_PER_METER 2834

#pragma pack(push, 1)
struct bmp_header
{
    uint16_t bfType;
    uint32_t bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack(pop)

enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
};

enum read_status from_bmp(FILE* in, struct image* img);

enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status to_bmp(FILE* out, struct image const* img);

#endif //IMAGE_TRANSFORMER_BMP_H
