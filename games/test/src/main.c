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
#include <mm.h>
#include <timer.h>
#include <keyboard.h>

void main()
{
    const char text[23] = "This is the test game. ";
    for (int i = 0; i < 23; i++)
    {
        putch(text[i]);
        sleep(20);
    }
    /*while (1)
    {
        for (int i = 1; i < 16; i++)
        {
            set_cursor_height(i);
            sleep(10);
        }
        for (int i = 16; i > 0; i--)
        {
            set_cursor_height(i);
            sleep(10);
        }
        }*/
    while (1)
    {
        KeyEvent key = get_key_event();
        if (!key.type) putch(key.keychar);
    }
}
