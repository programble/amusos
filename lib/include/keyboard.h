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

#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <common.h>
#include <syscall.h>

/**
 * Key event types.
 */
typedef enum
{
    KeyEvent_down,
    KeyEvent_up
} KeyEvent_type;

/**
 * Information on a key event.
 */
typedef struct
{
    KeyEvent_type type;
    int keycode;
    char keychar;
    bool shift;
    bool ctrl;
    bool alt;
} KeyEvent;

KeyEvent get_key_event();

#endif
