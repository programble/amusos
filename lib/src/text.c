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

void putch(char c)
{
    syscall1(0x03, c);
}

void puts(string s)
{
    for (char *c = s; *c != 0x0; c++)
      putch(*c);
}

void cls()
{
    syscall0(0x02);
}

void set_foreground_color(color c, bool b)
{
    syscall2(4, c, b);
}

void set_background_color(color c, bool b)
{
    syscall2(5, c, b);
}

void set_colors(color f, bool fb, color b, bool bb)
{
    set_foreground_color(f, fb);
    set_background_color(b, bb);
}
