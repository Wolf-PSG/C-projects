#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

//http://arkanis.de/weblog/2018-08-30-iir-gauss-blur-h-a-gaussian-blur-single-header-file-library
#define IIR_GAUSS_BLUR_IMPLEMENTATION
#include "iir_gauss_blur.h"

int main(void) {
    int width = 0, height = 0, channels = 0;
    uint8_t* img = stbi_load("test.png", &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }
    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);
    size_t img_size = width * height * channels;
    float sigma = 10;
    iir_gauss_blur(width, height, channels, img, sigma);

    // unsigned char * sepia = (unsigned char *) malloc(img_size);
    // for(unsigned char *p = img, *pg = sepia; p != img + img_size; p += channels, pg += channels) {
    //     *pg       = (uint8_t)fmin(0.393 * *p + 0.769 * *(p + 1) + 0.189 * *(p + 2), 255.0);         // red
    //     *(pg + 1) = (uint8_t)fmin(0.349 * *p + 0.686 * *(p + 1) + 0.168 * *(p + 2), 255.0);         // green
    //     *(pg + 2) = (uint8_t)fmin(0.272 * *p + 0.534 * *(p + 1) + 0.131 * *(p + 2), 255.0);         // blue        
    //     if(channels == 4) {
    //          *(pg + 3) = *(p + 3);
    //      }
    //  }



    // stbi_write_png("big.png", width, height, channels, img, width * channels);
    stbi_write_png("biggai.png", width, height, channels, img, 0);

    stbi_image_free(img);
    // free(sepia);
}