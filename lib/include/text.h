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
void puts(const string s);

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

/**
 * Set the text-mode hardware cursor's x position.
 * @param x The x position to set
 */
void set_cursor_x(unsigned char x);

/**
 * Set the text-mode hardware cursor's y position.
 * @param y The y position to set
 */
void set_cursor_y(unsigned char y);

/**
 * Set the text-mode hardware cursor's position.
 * @param x The x position to set
 * @param y The y position to set
 */
void set_cursor_position(unsigned char x, unsigned char y);

/**
 * Get the text-mode hardware cursor's x position.
 * @return The x position
 */
unsigned char get_cursor_x();

/**
 * Get the text-mode hardware cursor's y position.
 * @return The y position
 */
unsigned char get_cursor_y();

/**
 * Get the text-mode hardware cursor's position.
 * @param x Where to store the x position
 * @param y Where to store the y position
 */
void get_cursor_position(unsigned char *x, unsigned char *y);

/**
 * Warp the text-mode hardware cursor's x position.
 * @param x How much to warp by
 * @return The new x position
 */
unsigned char warp_cursor_x(signed char x);

/**
 * Warp the text-mode hardware cursor's y position.
 * @param y How much to warp by
 * @return The new y position
 */
unsigned char warp_cursor_y(signed char y);

/**
 * Warp the text-mode hardware cursor's position.
 * @param x How much to warp x by
 * @param y How much to warp y by
 */
void warp_cursor(signed char x, signed char y);

/**
 * Hide the text-mode hardware cursor.
 */
void hide_cursor();

/**
 * Show the text-mode hardware cursor.
 */
void show_cursor();

/**
 * Change the text-mode hardware cursor's height.
 * @param height The height
 */
void set_cursor_height(unsigned int height);

/**
 * Get the text-mode hardware cursor's height.
 * @return The height
 */
unsigned int get_cursor_height();

#endif
