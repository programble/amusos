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

#include <syscall.h>

#include <tty.h>

void syscall_nop()
{
    return;
}

SYSCALL_RETURN_WRAP(u8, get_cursor_x);
SYSCALL_RETURN_WRAP(u8, get_cursor_y);

static void *syscalls[SYSCALL_COUNT] =
{
    /* 0 */ syscall_nop, /* TODO: syscall_malloc */
    /* 1 */ syscall_nop, /* TODO: syscall_free */
    /* 2 */ cls,
    /* 3 */ putch,
    /* 4 */ set_foreground_color,
    /* 5 */ set_background_color,
    /* 6 */ get_foreground_color,
    /* 7 */ get_background_color,
    /* 8 */ set_cursor_x,
    /* 9 */ set_cursor_y,
    /* 10 */ SYSCALL_WRAPPER(get_cursor_x),
    /* 11 */ SYSCALL_WRAPPER(get_cursor_y),
};

void syscall_handler(registers *r)
{
    if (r->eax >= SYSCALL_COUNT)
        panic("Invalid system call");
    
    void (*syscall)(u32, u32, u32, u32, u32);
    syscall = syscalls[r->eax];
    syscall(r->ebx, r->ecx, r->edx, r->esi, r->edi);
}

extern void isr_syscall();

void syscall_install()
{
    idt_set_gate(SYSCALL_INTERRUPT, (unsigned) isr_syscall, 0x08, 0x8E);
}
