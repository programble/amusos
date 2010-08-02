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

all: kernel

kernel:
	@cd kernel/; $(MAKE) $(MFLAGS)

clean:
	@cd kernel/; $(MAKE) $(MFLAGS) clean

distclean:
	rm -f *~
	@cd kernel/; $(MAKE) $(MFLAGS) distclean

.PHONY: clean distclean kernel
