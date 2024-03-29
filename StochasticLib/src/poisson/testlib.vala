using Cairo;

class Demo.HelloWorld : GLib.Object {
    public static int main(string[] args) {
		int v = StochasticLib.echo_number(23);
        stdout.printf("echo:%d\n", v);
        
        Cairo.ImageSurface cst = new Cairo.ImageSurface (Cairo.Format.ARGB32, 600, 600);
        Cairo.Context ctx = new Cairo.Context(cst);
        stdout.printf("status 1:%s (%u)\n", ctx.status().to_string(), ctx.get_reference_count());
        
		Cairo.Context returnedCtx = StochasticLib.echo_cairo_t(ctx);
		stdout.printf("status 2:%s (%u)\n", returnedCtx.status().to_string(), returnedCtx.get_reference_count());
		
		cst.write_to_png ("img.png");
		
        return 0;
    }
}
