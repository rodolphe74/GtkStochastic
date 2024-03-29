#pragma once
#include <cairo/cairo.h>

#ifdef __cplusplus
extern "C" {
#endif
int echo_number(int value);
cairo_t *echo_cairo_t(cairo_t *cairo_t_ptr);
#ifdef __cplusplus
}
#endif
