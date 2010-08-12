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
AR=ar
RANLIB=ranlib

INCLUDES=-Iinclude/
WARNINGS=-Wall -Wextra -Wunreachable-code -Wshadow -Wno-unused-parameter -Wpointer-arith -Wbad-function-cast -Wcast-align -Wwrite-strings -Wmissing-field-initializers -Wredundant-decls -Wnested-externs
CFLAGS=-m32 -std=c99 -nostdlib -nostartfiles -nodefaultlibs -nostdinc -ffreestanding -fno-builtin $(WARNINGS) $(INCLUDES)

ARFLAGS=rc

SOURCES:=$(wildcard src/*.c)
OBJECTS:=$(SOURCES:%.c=%.o)

OUTPUT=gamelib.lib

all: $(SOURCES) $(OUTPUT)

$(OUTPUT): include/version.h $(OBJECTS)
	$(AR) $(ARFLAGS) $(OUTPUT) $(OBJECTS)
	$(RANLIB) $(OUTPUT)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

include/version.h: $(SOURCES)
	@if [ "$(shell git tag --contains $(shell git rev-parse HEAD))" ]; then \
	echo "#define VERSION \"$(shell git tag --contains $(shell git rev-parse HEAD) | cut -c2-)\"" > $@; \
	else \
	echo "#define VERSION \"git-$(shell git rev-parse HEAD | cut -c-20)\"" > $@; \
	fi

doc: $(wildcard include/*.h) .doxygenrc
	doxygen .doxygenrc

clean:
	rm -f $(OBJECTS)
	rm -f $(OUTPUT)
	rm -rf doc/

distclean: clean
	rm -f *~
	rm -f include/*~
	rm -f src/*~

check-syntax:
	$(CC) $(CFLAGS) -fsyntax-only $(CHK_SOURCES)

.PHONY: clean distclean check-syntax
