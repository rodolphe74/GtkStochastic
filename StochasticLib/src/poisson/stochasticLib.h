#pragma once
#include <cairo/cairo.h>


#ifdef __cplusplus
extern "C" {
#endif
int echo_number(int value);
cairo_t *echo_cairo_t(cairo_t *cairo_t_ptr);
cairo_t *do_sth_with_image_cairo_t(cairo_t *cairo_t_ptr, char *data, int sz, int w, int h, int c);
char *load_image(unsigned char *filename, int *outWidth, int *outHeight, int *outComp, int *arrayLength, int *w, int *h, int *c);
void imageSize(unsigned char *filename, int *w, int *h, int *c);
void loadImage(unsigned char *filename, char *data);


// static void ditherOverCairoSurface(const std::string &imageFilename, int drawWidth, int drawHeight, int margin, int points, int dist);
#ifdef __cplusplus
}
#endif
