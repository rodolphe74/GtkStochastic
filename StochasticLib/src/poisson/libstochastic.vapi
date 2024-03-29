[CCode (cheader_filename = "stochasticLib.h")]
namespace StochasticLib {
	[CCode (cname = "echo_number")]
	int echo_number(int value);
	
	[CCode (cname = "echo_cairo_t")]
	unowned Cairo.Context echo_cairo_t(Cairo.Context cairo_t_ptr);
}
