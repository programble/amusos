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

void _start()
{
    const char text[23] = "This is the test game. ";
    for (int i = 0; i < 23; i++)
    {
        putch(text[i]);
        sleep(10);
    }
    hide_cursor();
    while (1)
    {
        putch('_');
        sleep(50);
        putch('\b');
    }
}
