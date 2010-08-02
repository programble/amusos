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

#include <idt.h>

idt_entry idt[256];
idt_ptr idtp;

void idt_set_gate(u8 num, u64 base, u16 sel, u8 flags)
{
    idt[num].base_lo = (base & 0xFFFF);
    idt[num].base_hi = (base >> 16) & 0xFF;
    idt[num].sel = sel;
    idt[num].flags = flags;
    idt[num].always0 = 0x0;
}

void idt_install()
{
    idtp.limit = (sizeof (idt_entry) * 256) - 1;
    idtp.base = (u32) &idt;

    memset((u8*) &idt, 0, sizeof(idt_entry) * 256);

    idt_load();
}
