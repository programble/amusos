/*  Copyright 2010 Curtis McEnroe <programble@gmail.com>
 *
 *  This file is part of <NAME>.
 *
 *  <NAME> is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  <NAME> is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with <NAME>.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <kernel.h>
#include <multiboot.h>

void kmain(multiboot_header *multiboot, u32 magic)
{
    unsigned char *videoram = (unsigned char *) 0xb8000;
    videoram[0] = 65; /* character 'A' */
    videoram[1] = 0x07; /* forground, background color. */
    while (1);
}
