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

#include <multiboot.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <irq.h>
#include <syscall.h>
#include <tty.h>
#include <loader.h>

void kmain(multiboot_header *multiboot, u32 magic)
{
    assert(magic == MULTIBOOT_BOOTLOADER_MAGIC, "Invalid bootloader magic");
    
    gdt_install();
    idt_install();
    isr_install();
    irq_install();
    enable_interrupts();

    syscall_install();

    tty_install();

    /* Test syscall */
    iasm("mov eax, 0x02; mov ebx, 0x68; int 0x80");
    iasm("mov eax, 0x02; mov ebx, 0x65; int 0x80");
    iasm("mov eax, 0x02; mov ebx, 0x6c; int 0x80; int 0x80");
    iasm("mov eax, 0x02; mov ebx, 0x6f; int 0x80");

    panic("No game to load");
}
