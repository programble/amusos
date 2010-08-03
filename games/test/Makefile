# Copyright 2010 Curtis McEnroe <programble@gmail.com>
#
# This file is part of AmusOS.
#
# AmusOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# AmusOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with AmusOS.  If not, see <http://www.gnu.org/licenses/>.

CC=clang
LD=ld

INCLUDES=-Iinclude/ -I../../lib/include/
WARNINGS=-Wall -Wextra -Wunreachable-code -Wshadow -Wno-unused-parameter -Wpointer-arith -Wbad-function-cast -Wcast-align -Wwrite-strings -Wmissing-field-initializers -Wredundant-decls -Wnested-externs
CFLAGS=-m32 -std=c99 -nostdlib -nostartfiles -nodefaultlibs -nostdinc -ffreestanding -fno-builtin $(WARNINGS) $(INCLUDES)

LDFLAGS=-melf_i386 -nostdlib -Ttext 0x200000 -L../../lib/src

SOURCES:=$(wildcard src/*.c)
OBJECTS:=$(SOURCES:%.c=%.o)

OUTPUT=test.elf

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ ../../lib/gamelib.lib $<

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	rm -f $(OUTPUT)

distclean: clean
	rm -f *~
	rm -f include/*~
	rm -f src/*~

check-syntax:
	$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)

.PHONY: clean distclean check-syntax
