#include <math.h>
#include <iostream>
#include <string>
#include "stochasticLib.h"
#include "cairoUtils.hpp"
#include "ImageUtils.hpp"

// A4 600 dpi
#define DRAW_WIDTH 4956
#define DRAW_HEIGHT 7014

// bypass strange border triangles
#define MARGIN 20



void imageSize(unsigned char *filename, int *w, int *h, int *c)
{
    Image im;
    std::string imageFilename = std::string((char *)filename);
    ImageUtils::loadImageAsRGBA(imageFilename.c_str(), &im);

    Image rszgr;
    int nw = DRAW_WIDTH - 2 * MARGIN;
    int nh = DRAW_HEIGHT - 2 * MARGIN;
	ImageUtils::resizeImage(&im, &rszgr, nw, nh);
	*w = rszgr.w;
	*h = rszgr.h;
	*c = rszgr.comp;

    printf("Name:%s  Size:%d (%d*%d*%d)\n", filename,  rszgr.w * rszgr.h * rszgr.comp, rszgr.w, rszgr.h, rszgr.comp);
}

void loadImage(unsigned char *filename, char *data)
{
    Image im, gr, rszgr;
    std::string imageFilename = std::string((char *)filename);
	ImageUtils::loadImageAsRGBA(imageFilename.c_str(), &im);
	ImageUtils::convertImageToGray(&im, &gr, 1.6, 255);
	ImageUtils::saveImageAsPNG("gray.png", &gr);

    int nw = DRAW_WIDTH - 2 * MARGIN;
    int nh = DRAW_HEIGHT - 2 * MARGIN;
	ImageUtils::resizeImage(&gr, &rszgr, nw, nh);

	ImageUtils::saveImageAsPNG("sized.png", &rszgr);

    printf("Image is at %p  comp=%d\n", (void *) rszgr.data, rszgr.comp);

    int i = 0;
    if(gr.data == NULL) {
        std::cout << "Error loading the image" << std::endl;
    } else {
        for (i = 0; i < rszgr.w * rszgr.h * rszgr.comp; i++) {
            data[i] = rszgr.data[i];
        }
    }
    std::cout << "i=" << i << std::endl;


    for (int i = 0; i < 20; i++) {
        std::cout << (int) data[i] << ",";
    }
    std::cout << std::endl;

    ImageUtils::freeImage(&im);
    ImageUtils::freeImage(&gr);
    ImageUtils::freeImage(&rszgr);
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
    int stride = cairo_format_stride_for_width (CAIRO_FORMAT_RGB24, w);
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
    cairo_rectangle(cr, 0, 0, w, h);
    cairo_fill(cr);
	cairo_surface_finish(imgSurface);

	delete[] formattedData;

	return cr;
}
