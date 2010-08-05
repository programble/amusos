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
    color colors[] = { blue, green, cyan, red, magenta, blue, green };
    for (int i = 0; i < 7; i++)
    {
        set_foreground_color(colors[i], true);
        putch(text[i]);
    }
}
