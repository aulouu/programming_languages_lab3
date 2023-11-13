//
// Created by Алина on 01.11.2023.
//

#include "../include/file.h"

FILE* open(char* filename, char* mode) {
    FILE* open_file = fopen(filename, mode);
    return open_file;
}
