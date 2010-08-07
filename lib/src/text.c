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
    syscall1(4, c);
}

void puts(string s)
{
    for (char *c = s; *c != 0x0; c++)
      putch(*c);
}

void cls()
{
    syscall0(3);
}

void set_foreground_color(color c, bool b)
{
    syscall2(5, c, b);
}

void set_background_color(color c, bool b)
{
    syscall2(6, c, b);
}

void set_colors(color f, bool fb, color b, bool bb)
{
    set_foreground_color(f, fb);
    set_background_color(b, bb);
}

void get_foreground_color(color *c, bool *b)
{
    syscall2(7, c, b);
}

void get_background_color(color *c, bool *b)
{
    syscall2(8, c, b);
}

void get_colors(color *f, bool *fb, color *b, bool *bb)
{
    get_foreground_color(f, fb);
    get_background_color(b, bb);
}

void set_cursor_x(unsigned char x)
{
    syscall1(9, x);
}

void set_cursor_y(unsigned char y)
{
    syscall1(10, y);
}

void set_cursor_position(unsigned char x, unsigned char y)
{
    set_cursor_x(x);
    set_cursor_y(y);
}

unsigned char get_cursor_x()
{
    unsigned char x;
    unsigned char *p = &x;
    syscall1(11, p);
    return x;
}

unsigned char get_cursor_y()
{
    unsigned char y;
    unsigned char *p = &y;
    syscall1(12, p);
    return y;
}

void get_cursor_position(unsigned char *x, unsigned char *y)
{
    *x = get_cursor_x();
    *y = get_cursor_y();
}

unsigned char warp_cursor_x(signed char x)
{
    unsigned char old = get_cursor_x();
    unsigned char new = old + x;
    set_cursor_x(new);
    return new;
}

unsigned char warp_cursor_y(signed char y)
{
    unsigned char old = get_cursor_y();
    unsigned char new = old + y;
    set_cursor_y(new);
    return new;
}

void warp_cursor(signed char x, signed char y)
{
    warp_cursor_x(x);
    warp_cursor_y(y);
}

void hide_cursor()
{
    syscall0(14);
}

void show_cursor()
{
    syscall0(13);
}

void set_cursor_height(unsigned int height)
{
    syscall1(15, height);
}

unsigned int get_cursor_height()
{
    unsigned int height;
    unsigned int *p = &height;
    syscall1(16, p);
    return height;
}
