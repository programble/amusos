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

#ifndef __TEXT_H__
#define __TEXT_H__

#include <common.h>
#include <syscall.h>

/**
 * Text-mode colors.
 * Enumeration of colors text-mode is capable of
 * displaying.
 */
typedef enum
{
    black,
    blue,
    green,
    cyan,
    red,
    magenta,
    brown,
    gray
} color;

/**
 * Puts a character on screen in text-mode.
 * Puts a character at the current text-mode cursor
 * position and advances the cursor by one.
 * @param c The character to put on screen
 */
void putch(char c);

/**
 * Puts a string on screen in text-mode.
 * Puts a string at the current text-mode cursor position
 * and advances the cursor by the length of the string.
 * @param s The string to put on screen
 */
void puts(string s);

void cls();
void set_foreground_color(color, bool);
void set_background_color(color, bool);
void set_colors(color, bool, color, bool);

#endif
