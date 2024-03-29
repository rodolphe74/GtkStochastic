#include <math.h>
#include "stochasticLib.h"
#include "cairoUtils.hpp"

int echo_number(int value)
{
    return value;
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
