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
#include <timer.h>

void _start()
{
    cls();
    sleep(100);
    set_background_color(blue, false);
    cls();
    puts("\n\n\n\n\n\n\n\n");
    for (int i = 0; i < 34; i++)
        putch(' ');
    set_background_color(gray, false);
    set_foreground_color(blue, false);
    puts(" Windows ");
    set_background_color(blue, false);
    set_foreground_color(gray, true);
    puts("\n\n     A fatal exception 0E has occured at 0028:C0011E36 in UXD UMM(01) +\n");
    puts("     00010E36. The current application will be terminated.\n\n");
    puts("     *  Press any key to terminate the current application.\n");
    puts("     *  Press CTRL+ALT+DEL again to restart your computer. You will\n");
    puts("        lose any unsaved information in all applications.\n\n");
    for (int i = 0; i < 27; i++)
        putch(' ');
    puts("Press any key to continue ");
    while(1);
}
