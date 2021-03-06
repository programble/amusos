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
ASM=nasm
LD=ld

CINCLUDES=-Iinclude/ -include include/kernel.h
CWARNINGS=-Wall -Wextra -Wunreachable-code -Wshadow -Wno-unused-parameter -Wpointer-arith -Wbad-function-cast -Wcast-align -Wwrite-strings -Wmissing-field-initializers -Wredundant-decls -Wnested-externs
CFLAGS=-m32 -std=c99 -nostdlib -nostartfiles -nodefaultlibs -nostdinc -ffreestanding -fno-builtin $(CWARNINGS) $(CINCLUDES)
DFLAGS=-ggdb -DDEBUG -O0
AFLAGS=-f elf
LDFLAGS=-melf_i386 -nostdlib -T linker.ld

CSOURCES:=$(wildcard src/*.c)
COBJECTS:=$(CSOURCES:%.c=%.o)

ASOURCES:=$(wildcard src/*.asm)
AOBJECTS:=$(ASOURCES:%.asm=%.ao)

OUTPUT=amusos.elf

all: $(CSOURCES) $(ASOURCES) $(OUTPUT)

$(OUTPUT): include/version.h $(AOBJECTS) $(COBJECTS)
	$(LD) $(LDFLAGS) $(AOBJECTS) $(COBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

%.ao: %.asm
	$(ASM) $(AFLAGS) -o $@ $<

include/version.h: $(CSOURCES) Makefile
	@echo "#ifndef __VERSION_H__" > $@
	@echo "#define __VERSION_H__" >> $@
	@if [ "$(shell git tag --contains $(shell git rev-parse HEAD))" ]; then \
	echo "#define VERSION \"$(shell git tag --contains $(shell git rev-parse HEAD) | cut -c2-)\"" >> $@; \
	else \
	echo "#define VERSION \"$(shell git tag | cut -c2-).r$(shell git rev-parse HEAD | cut -c-8)\"" >> $@; \
	fi
	@echo "#define COMPILER \"$(CC) \" __VERSION__" >> $@
	@echo "#endif" >> $@

debug:
	@$(MAKE) $(MFLAGS) CFLAGS="$(CFLAGS) $(DFLAGS)"

dry-asm:
	@$(MAKE) $(MFLAGS) CFLAGS="$(CFLAGS) -S" $(COBJECTS)

dry-pp:
	@$(MAKE) $(MFLAGS) CFLAGS="$(CFLAGS) -E" $(COBJECTS)

clean:
	rm -f include/version.h
	rm -f $(COBJECTS)
	rm -f $(AOBJECTS)
	rm -f $(OUTPUT)

distclean: clean
	rm -f *~
	rm -f src/*~
	rm -f include/*~

check-syntax: include/version.h
	$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)

.PHONY: clean distclean check-syntax debug dryasm drypp
