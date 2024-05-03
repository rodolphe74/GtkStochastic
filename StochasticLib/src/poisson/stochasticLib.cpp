#include <math.h>
#include <iostream>
#include "stochasticLib.h"
#include "cairoUtils.hpp"

 #define STB_IMAGE_IMPLEMENTATION
 #include <stb/stb_image.h>
 #define STB_IMAGE_WRITE_IMPLEMENTATION
 #include <stb/stb_image_write.h>

int echo_number(int value)
{
    return value;
}

char *load_image(unsigned char *filename, int *outWidth, int *outHeight, int *outComp, int *arrayLength)
{
    std::cout << filename << std::endl;

    int width, height, channels;
    char *img =  (char *) stbi_load((const char *) filename, &width, &height, &channels, 0);

    printf("Image is at %p\n", (void *) img);

    if(img == NULL) {
        std::cout << "Error loading the image" << std::endl;
        return nullptr;
    }
    std::cout << "Image:" << width << "*" << height << "*"  << channels << std::endl;
    // *arrayLength = width * height * channels;
    *outWidth = width;
    *outHeight = height;
    *outComp = channels;

    for (int i = 0; i < 20; i++) {
        std::cout << (int) img[i] << ",";
    }
    std::cout << std::endl;
    return img;
}

void imageSize(unsigned char *filename, int *w, int *h, int *c)
{
    int width, height, channels;
    char *img =  (char *) stbi_load((const char *) filename, &width, &height, &channels, 0);
    *w = width;
    *h = height;
    *c = channels;
    printf("Name:%s  Size:%d\n", filename,  width * height * channels);
}

void loadImage(unsigned char *filename, char *data)
{
    int width, height, channels;
    char *img =  (char *) stbi_load((const char *) filename, &width, &height, &channels, 0);
    printf("Image is at %p\n", (void *) data);

    if(data == NULL) {
        std::cout << "Error loading the image" << std::endl;
    } else {
        for (int i = 0; i < height * width * channels; i++) {
            data[i] = img[i];
        }
    }

    for (int i = 0; i < 20; i++) {
        std::cout << (int) data[i] << ",";
    }
    std::cout << std::endl;

    stbi_image_free(img);
}


cairo_t *echo_cairo_t(cairo_t *cr)
{
	// Draw something
	cairo_arc (cr, 128.0, 128.0, 76.8, 0, 2 * M_PI);
	cairo_clip (cr);

	cairo_new_path (cr);  /* current path is not
							 consumed by cairo_clip() */
	cairo_rectangle (cr, 0, 0, 256, 256);
	cairo_fill (cr);
	cairo_set_source_rgb (cr, 0, 1, 0);
	cairo_move_to (cr, 0, 0);
	cairo_line_to (cr, 256, 256);
	cairo_move_to (cr, 256, 0);
	cairo_line_to (cr, 0, 256);
	cairo_set_line_width (cr, 10.0);
	cairo_stroke (cr);
	
	return cr;
}

cairo_t *do_sth_with_image_cairo_t(cairo_t *cr, char *data, int sz, int w, int h, int c)
{
    printf("w=%d h=%d c=%d\n", w, h, c);

    int stride = cairo_format_stride_for_width (CAIRO_FORMAT_RGB24, w);
    printf("stride:%d\n", stride);
    unsigned char *formattedData = new unsigned char[stride * h];


    int count = 0;
    for (int i = 0; i < 4 * w * h; i+=4) {
        formattedData[i] = data[count + 2];
        formattedData[i + 1] = data[count + 1];
        formattedData[i + 2] = data[count];
        formattedData[i + 3] = 0;
        count += c;
    }
    printf("count=%d\n", count);

    cairo_surface_t *imgSurface = cairo_image_surface_create_for_data(formattedData, CAIRO_FORMAT_RGB24, w, h, stride);
    cairo_set_source_surface(cr, imgSurface, 0, 0);
    cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
    cairo_rectangle(cr, 0, 0, 640, 918);
    cairo_fill(cr);
	cairo_surface_finish(imgSurface);

	delete[] formattedData;

	return cr;
}
