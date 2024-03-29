/* window.vala
 *
 * Copyright 2024 rodoc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

using Gtk;
using Cairo;

namespace Gtkstochastic {


    public class StochaticDrawingArea : Gtk.DrawingArea {

        public StochaticDrawingArea (Gtk.Application app) {
            set_draw_func (on_draw);
        }
    }

    private void on_draw (Gtk.DrawingArea drawing_area, Cairo.Context ctx, int width, int height) {
        int xc, yc;
        xc = width / 2;
        yc = height / 2;

        ctx.set_line_width (10.0);

        // draw red lines out from the center of the window
        ctx.set_source_rgb (0.8, 0.0, 0.0);
        ctx.move_to (0, 0);
        ctx.line_to (xc, yc);
        ctx.line_to (0, height);
        ctx.move_to (xc, yc);
        ctx.line_to (width, yc);
        ctx.stroke ();
    }
}
