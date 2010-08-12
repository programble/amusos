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

all: iso

kernel:
	@cd kernel/; $(MAKE) $(MFLAGS)

lib:
	@cd lib/; $(MAKE) $(MFLAGS)

games: lib
	@cd games/; $(MAKE) $(MFLAGS)

iso: kernel lib games $(ISO)

$(ISO): iso/boot/grub/stage2_eltorito iso/boot/kernel.elf iso/boot/grub/menu.lst
	@$(MAKE) $(MFLAGS) iso/games
	$(GENISOIMAGE) -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o $(ISO) iso/

iso/boot/grub/stage2_eltorito: $(STAGE2)
	@mkdir -p $(@D)
	cp $< $@

iso/boot/kernel.elf: kernel/kernel.elf
	@mkdir -p $(@D)
	cp $< $@

iso/boot/grub/menu.lst: menu.lst $(wildcard games/*/menu.lst)
	@mkdir -p $(@D)
	cat $^ > $@

iso/games: $(wildcard games/*/*.elf)
	@mkdir -p $@
	cp $^ $@

qemu: $(ISO)
	qemu -cdrom $(ISO)

qemu-gdb: $(ISO)
	qemu -s -S -cdrom $(ISO)

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

.PHONY: clean distclean kernel lib games qemu todo iso qemu-gdb
