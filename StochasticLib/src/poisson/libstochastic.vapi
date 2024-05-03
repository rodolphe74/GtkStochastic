[CCode (cheader_filename = "stochasticLib.h")]
namespace StochasticLib {
	[CCode (cname = "echo_number")]
	int echo_number(int value);
	
	[CCode (cname = "echo_cairo_t")]
	unowned Cairo.Context echo_cairo_t(Cairo.Context cairo_t_ptr);

	[CCode (cname = "do_sth_with_image_cairo_t")]
	unowned Cairo.Context do_sth_with_image_cairo_t(Cairo.Context cairo_t_ptr, char *data, int sz, int w, int h, int c);

	[CCode (cname = "load_image")]
	char []load_image(string filename, int *outWidth, int *outHeight, int *outComp, int *arrayLength);

	[CCode (cname = "imageSize")]
	void imageSize(string filename, int *w, int *h, int *c);

	[CCode (cname = "loadImage")]
	void loadImage(string filename, char *data);

	// [CCode (cname = "free_image")]
	// void free_image(char *image);

}
