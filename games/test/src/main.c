/*  Copyright 2010 Curtis McEnroe <programble@gmail.com>
 *
 *  This file is part of AmusOS.
 *
 *  AmusOS is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  AmusOS is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with AmusOS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <text.h>

void _start()
{
    cls();
    char text[] = "RAINBOW";
    color fore[] = { blue, green, cyan, red, magenta, blue, green };
    color back[] = { magenta, red, cyan, green, blue, magenta, red };
    for (int i = 0; i < 7; i++)
    {
        set_colors(fore[i], true, back[i], false);
        putch(text[i]);
    }
    color foo;
    bool bar;
    get_foreground_color(&foo, &bar);
    if (foo == green)
        puts("baz");
    set_cursor_position(10, 10);
    puts("foo");
    char x = get_cursor_x();
    if (x == 13)
        puts("bar");
    warp_cursor(-2, +1);
    puts("baz");
}
