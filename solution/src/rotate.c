//
// Created by Алина on 01.11.2023.
//

#include "../include/rotate.h"
#include "../include/image.h"
#include <stdlib.h>

struct image rotate(struct image const source, int angle) {
    struct image rotated_image = {0};
    //angle = ((angle % 360) + 360) % 360;
    uint32_t x;
    uint32_t y;
    uint32_t new_height = source.height;
    uint32_t new_width = source.width;
    if (angle == 180) {
        rotated_image.height = new_height;
        rotated_image.width = new_width;
    } else {
        rotated_image.height = new_width;
        rotated_image.width = new_height;
    }
    rotated_image.data = malloc(rotated_image.width * rotated_image.height * STRUCT_SIZE);
    for (uint32_t i = 0; i < new_height; i++) {
        for (uint32_t j = 0; j < new_width; j++) {
            switch (angle) {
                case 90:
                case -270:
                    x = new_width - i -1;
                    y = j;
                    break;
                case 180:
                case -180:
                    x = new_width - j - 1;
                    y = new_height - i - 1;
                    break;
                case 270:
                case -90:
                    x = i;
                    y = new_height - j - 1;
                    break;
                default:
                    x = j;
                    y = i;
                    break;
            }
            struct pixel curr = source.data[i * new_width + j];
            rotated_image.data[y * rotated_image.width + x] = curr;
            //rotated_image.data[new_width + x * new_width - y - 1] = source.data[y + new_height * x];

        }
    }
    return rotated_image;
}
