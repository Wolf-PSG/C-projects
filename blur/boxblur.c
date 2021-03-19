#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lodepng.h"
//http://arkanis.de/weblog/2018-08-30-iir-gauss-blur-h-a-gaussian-blur-single-header-file-library
#define IIR_GAUSS_BLUR_IMPLEMENTATION
#include "iir_gauss_blur.h"

int main(void) {
    const char * filename = "test.png";
    unsigned error;
    unsigned char *image = 0;
    unsigned width, height;
    unsigned char *png = 0;
    size_t pngsize;

    error = lodepng_load_file(&png, &pngsize, filename);
    if (!error)
        error = lodepng_decode32(&image, &width, &height, png, pngsize);
    if (error)
        printf("error %u: %s\n", error, lodepng_error_text(error));

    printf("%d", error);
    free(png);
    free(image);
}