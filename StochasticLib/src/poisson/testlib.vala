using Cairo;

class Demo.HelloWorld : GLib.Object {



    public static int main(string[] args) {
        // png generation
        Cairo.ImageSurface cst = new Cairo.ImageSurface (Cairo.Format.ARGB32, 600, 600);
        Cairo.Context ctx = new Cairo.Context(cst);
        stdout.printf("status 1:%s (%u)\n", ctx.status().to_string(), ctx.get_reference_count());
        
		Cairo.Context returnedCtx = StochasticLib.echo_cairo_t(ctx);
		stdout.printf("status 2:%s (%u)\n", returnedCtx.status().to_string(), returnedCtx.get_reference_count());
		// DEBUG
		cst.write_to_png ("img.png");

		// load an image
		int width[1], height[1], channels[1], sz = 0;
		StochasticLib.imageSize("cl.jpg", width, height, channels);
		sz = width[0] * height[0] * channels[0];
        stdout.printf("array size:%d\n", sz);
        stdout.printf("width:%d\n", width[0]);
        stdout.printf("height:%d\n", height[0]);
        stdout.printf("comp:%d\n", channels[0]);

        // reserving array of enough space to keep image bytes
        char[] imageBytes = {};
        for (int i = 0; i < sz; i++)
            imageBytes += ' ';
        stdout.printf("reserved: %d\n", imageBytes.length);

        // load image for real
        StochasticLib.loadImage("cl.jpg", imageBytes);

        // create a cairo surface with previous image
        Cairo.ImageSurface cst2 = new Cairo.ImageSurface (Cairo.Format.ARGB32, width[0], height[0]);
        Cairo.Context ctx2 = new Cairo.Context(cst2);
        stdout.printf("status Cairo Context:%s (%u)\n", ctx2.status().to_string(), ctx2.get_reference_count());

        // do some stuff on cairo surface
		Cairo.Context returnedCtx2 = StochasticLib.do_sth_with_image_cairo_t(ctx2, imageBytes, sz, width[0], height[0], channels[0]);
		stdout.printf("status 2:%s (%u)\n", returnedCtx2.status().to_string(), returnedCtx2.get_reference_count());

		cst2.write_to_png ("img2.png");

        return 0;
    }
}
