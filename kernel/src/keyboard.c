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

#include <keyboard.h>

bool left_shift = false;
bool right_shift = false;

bool ctrl = false;

bool alt = false;

char keymap[128] =
{
    0, 27,
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, /* Control */
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
    '`',
    0, /* Left shift */
    '\\',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    0, /* Right shift */
    '*',
    0, /* Alt */
    ' ',
    0, /* Caps lock */
    '\x83', '\x84', '\x85', '\x86', '\x87', '\x88', '\x89', '\x8A', '\x8B', /* F1 - F10 */
    0, /* Num lock */
    0, /* Scroll lock */
    '\x8E', /* Home */
    '\x8F', /* Up */
    '\x90', /* Page up */
    '-',
    '\x91', /* Left */
    0,
    '\x92', /* Right */
    '+',
    '\x93', /* End */
    '\x94', /* Down */
    '\x95', /* Page down */
    '\x96', /* Insert */
    '\x97', /* Delete */
    0, 0, 0,
    '\x98', /* F11 */
    '\x99', /* F12 */
    0,
};

char keymap_shift[128] =
{
    0, 27,
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b',
    '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',
    0, /* Control */
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"',
    '~',
    0, /* Left shift */
    '|',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
    0, /* Right shift */
    '*',
    0, /* Alt */
    ' ',
    0, /* Caps lock */
    '\x83', '\x84', '\x85', '\x86', '\x87', '\x88', '\x89', '\x8A', '\x8B', /* F1 - F10 */
    0, /* Num lock */
    0, /* Scroll lock */
    '\x8E', /* Home */
    '\x8F', /* Up */
    '\x90', /* Page up */
    '-',
    '\x91', /* Left */
    0,
    '\x92', /* Right */
    '+',
    '\x93', /* End */
    '\x94', /* Down */
    '\x95', /* Page down */
    '\x96', /* Insert */
    '\x97', /* Delete */
    0, 0, 0,
    '\x98', /* F11 */
    '\x99', /* F12 */
    0,
};

void keyboard_handler(registers *r)
{
    u8 scancode = inportb(0x60);

    key_event event;

    if (scancode & 0x80)
    {
        event.type = key_event_up;
        scancode = scancode & ~0x80;
    }
    else
        event.type = key_event_down;

    event.keycode = scancode;
    event.keychar = (left_shift || right_shift) ? keymap_shift[scancode] : keymap[scancode];
    event.shift = left_shift || right_shift;
    event.ctrl = ctrl;
    event.alt = alt;

    if (event.keycode == 0x2A && event.type == key_event_down)
        left_shift = true;
    else if (event.keycode == 0x2A && event.type == key_event_up)
        left_shift = false;
    else if (event.keycode == 0x36 && event.type == key_event_down)
        right_shift = true;
    else if (event.keycode == 0x36 && event.type == key_event_up)
        right_shift = false;
    else if (event.keycode == 0x1D && event.type == key_event_down)
        ctrl = true;
    else if (event.keycode == 0x1D && event.type == key_event_up)
        ctrl = false;
    else if (event.keycode == 0x38 && event.type == key_event_down)
        alt = true;
    else if (event.keycode == 0x38 && event.type == key_event_up)
        alt = false;
    else if (event.keycode == 0x60)
        /* Ignore */;
    else
    {
        /* TODO: Something with the event */
#ifdef DEBUG
        if (event.shift) puts("shift");
        if (event.ctrl) puts("ctrl");
        if (event.alt) puts("alt");
        if (event.type == key_event_down) putch(event.keychar);
#endif
    }
}

void keyboard_install()
{
    irq_install_handler(1, keyboard_handler);
}
