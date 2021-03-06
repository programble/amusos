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

#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include <common.h>

#define SYSCALL_INTERRUPT 0x80

#define syscall0(x) __asm__ __volatile__("mov $" #x ", %%eax; int $" MACRO_STRING(SYSCALL_INTERRUPT) ";" : : : "eax")

#define syscall1(x, y) __asm__ __volatile__("mov $" #x ", %%eax; mov %0, %%ebx; int $" MACRO_STRING(SYSCALL_INTERRUPT) ";" : : "m" (y) : "eax", "ebx")

#define syscall2(x, y, z) __asm__ __volatile__("mov $" #x ", %%eax; mov %0, %%ebx; mov %1, %%ecx; int $" MACRO_STRING(SYSCALL_INTERRUPT) ";" : : "m" (y), "m" (z) : "eax", "ebx", "ecx")

#define syscall3(a, b, c, d) __asm__ __volatile__("mov $" #a ", %%eax; mov %0, %%ebx; mov %1, %%ecx; mov %2, %%edx; int $" MACRO_STRING(SYSCALL_INTERRUPT) ";" : : "m" (b), "m" (c), "m" (d) : "eax", "ebx", "ecx", "edx")

#endif
