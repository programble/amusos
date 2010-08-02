# Copyright 2010 Curtis McEnroe <programble@gmail.com>
#
# This file is part of <NAME>.
#
# <NAME> is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# <NAME> is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with <NAME>.  If not, see <http://www.gnu.org/licenses/>.

CC=clang
ASM=nasm
LD=ld

CINCLUDES=-Iinclude/
CFLAGS=-m32 -std=c99 -Wall -Wextra -nostdlib -nostartfiles -nodefaultlibs -nostdinc -ffreestanding -fno-builtin $(CINCLUDES)
AFLAGS=-f elf
LDFLAGS=-melf_i386 -T linker.ld

CSOURCES:=$(wildcard src/*.c)
COBJECTS:=$(SOURCES:%.c=%.c.o)

ASOURCES:=$(wildcard src/*.asm)
AOBJECTS:=$(SOURCES:%.asm=%.asm.o)

OUTPUT=kernel.elf

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): $(AOBJECTS) $(COBJECTS)
	$(LD) $(LDFLAGS) $(AOBJECTS) $(COBJECTS) -o $@

%.c.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.asm.o: %.asm
	$(ASM) $(AFLAGS) -o $@ $<

clean:
	rm -f $(COBJECTS)
	rm -f $(AOBJECTS)
	rm -f $(OUTPUT)

.PHONY: clean
