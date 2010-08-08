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

STAGE2=/usr/lib/grub/i386-pc/stage2_eltorito
GENISOIMAGE=genisoimage
ISO=amusos.iso

all: $(ISO)

kernel:
	@cd kernel/; $(MAKE) $(MFLAGS)

lib:
	@cd lib/; $(MAKE) $(MFLAGS)

games: lib
	@cd games/; $(MAKE) $(MFLAGS)

iso: $(ISO)

$(ISO): kernel lib games
	mkdir -p iso
	mkdir -p iso/boot/grub
	mkdir -p iso/games
	cp $(STAGE2) iso/boot/grub/stage2_eltorito
	cp kernel/kernel.elf iso/boot/kernel.elf
	echo "default 0" > iso/boot/grub/menu.lst
	echo "timeout 10" >> iso/boot/grub/menu.lst
	for game in games/*/; do \
	cat $${game}/menu.lst >> iso/boot/grub/menu.lst; \
	cp $${game}/*.elf iso/games/; \
	done
	$(GENISOIMAGE) -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o $(ISO) iso/

qemu: $(ISO)
	qemu -cdrom $(ISO)

todo:
	@grep -rInso 'TODO: \([^*]\+\)' kernel; true
	@grep -rInso 'TODO: \([^*]\+\)' lib; true
	@grep -rInso 'TODO: \([^*]\+\)' games; true

clean:
	rm -rf iso/
	rm -f $(ISO)
	@cd kernel/; $(MAKE) $(MFLAGS) clean
	@cd lib/; $(MAKE) $(MFLAGS) clean
	@cd games/; $(MAKE) $(MFLAGS) clean

distclean:
	rm -f *~
	rm -rf iso/
	rm -f $(ISO)
	@cd kernel/; $(MAKE) $(MFLAGS) distclean
	@cd lib/; $(MAKE) $(MFLAGS) distclean
	@cd games/; $(MAKE) $(MFLAGS) distclean

.PHONY: clean distclean kernel lib games qemu todo iso
