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

all: kernel lib games

kernel:
	@cd kernel/; $(MAKE) $(MFLAGS)

lib:
	@cd lib/; $(MAKE) $(MFLAGS)

games:
	@cd games/; $(MAKE) $(MFLAGS)

qemu: kernel
	qemu -kernel kernel/kernel.elf

todo:
	@grep -rInso 'TODO: \([^*]\+\)' kernel; true
	@grep -rInso 'TODO: \([^*]\+\)' lib; true
	@grep -rInso 'TODO: \([^*]\+\)' games; true

clean:
	@cd kernel/; $(MAKE) $(MFLAGS) clean
	@cd lib/; $(MAKE) $(MFLAGS) clean
	@cd games/; $(MAKE) $(MFLAGS) clean

distclean:
	rm -f *~
	@cd kernel/; $(MAKE) $(MFLAGS) distclean
	@cd lib/; $(MAKE) $(MFLAGS) distclean
	@cd games/; $(MAKE) $(MFLAGS) distclean

.PHONY: clean distclean kernel lib games qemu todo
