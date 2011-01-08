AmusOS
======
![](http://stillmaintained.com/programble/amusos.png)

AmusOS is a gaming operating system consisting of a kernel, a game
library, and games. Games are loaded using multiboot modules.

Building
--------

    make

### Dependencies

 * GRUB (or at least `stage2_eltorito`)
 * `genisoimage` or `mkiso`
 * A C Compiler
 * NASM
 * A linker (`ld`)
 * `ar`
 * `ranlib`

### Options

 * `STAGE2` Default: `/usr/lib/grub/i386-pc/stage2_eltorito`
 * `GENISOIMAGE` Default: `genisoimage`
 * `CC` Default: `clang`
 * `ASM` Default: `nasm`
 * `LD` Default: `ld`
 * `AR` Default: `ar`
 * `RANLIB` Default: `ranlib`
