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

/**
 * Clears the text-mode screen.
 * Fills the entire text-mode screen with blanks
 * and positions the text-mode cursor in the top-left.
 */
void cls();

/**
 * Sets the text-mode foreground color.
 * Sets the text-mode foreground color
 * and brightness.
 * @param foreground The color to set
 * @param bright Whether or not the color should be bright
 */
void set_foreground_color(color foreground, bool bright);

/**
 * Sets the text-mode background color.
 * Sets the text-mode background color
 * and brightness.
 * @param background The color to set
 * @param bright Whether or not the color should be bright
 */
void set_background_color(color background, bool bright);

/**
 * Sets the text-mode foreground and background colors.
 * Sets the text-mode foreground and background colors and brightnesses.
 * @param foreground The foreground color
 * @param forebright The brightness of the foreground color
 * @param background The background color
 * @param backbright The background brightness
 */
void set_colors(color foreground, bool forebright, color background, bool backbright);

/**
 * Gets the current text-mode foreground color.
 * Gets the current text-mode foreground color and brightness.
 * @param foreground Where to store the color
 * @param bright Where to store the brightness
 */
void get_foreground_color(color *foreground, bool *bright);

/**
 * Gets the current text-mode background color.
 * Gets the current text-mode background color and brightness.
 * @param background Where to store the color
 * @param bright Where to store the brightness
 */
void get_background_color(color *background, bool *bright);

/**
 * Gets the current text-mode foreground and background colors.
 * Gets the current text-mode foreground and background
 * colors and brightnesses.
 * @param foreground Where to store the foreground color
 * @param forebright Where to store the foreground brightness
 * @param background Where to store the background color
 * @param backbright Where to store the background brightness
 */
void get_colors(color *foreground, bool *forebright, color *background, bool *backbright);

#endif
