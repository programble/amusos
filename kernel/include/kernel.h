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

#ifndef __KERNEL_H__
#define __KERNEL_H__

/* Macro macros */
#define STRING(x) #x
#define MACRO_STRING(x) STRING(x)

/* Version information */
#define VERSION "0.1.0"
#define COMPILED __DATE__

/* Macros */
#define asm(x) __asm__ __volatile__(x)

/* Types and things */

#define NULL ((void*) 0)

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef char* string;

typedef enum
{
    false,
    true
} bool;

/* Linker things */
extern void *link_kernel_start;
extern void *link_kernel_end;

/* Halt, panic, etc */
void halt();
void _panic(const string, const string, const string, const string);

#define panic(x) _panic(x, (string) __FUNCTION__, (string) __FILE__, (string) MACRO_STRING(__LINE__))
#define assert(x) if (!(x)) _panic("Assert failed: " #x, __FUNCTION__, __FILE, MACRO_STRING(__LINE__))

#endif
