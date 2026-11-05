#!/bin/bash
set -e
rm -f silx.bin *.o vga/*.o cmdEmu/*.o input/*.o

nasm -f elf boot.asm -o boot.o

clang --target=i386-pc-none-elf -ffreestanding -nostdlib -c kernel.c -o kernel.o
clang --target=i386-pc-none-elf -ffreestanding -nostdlib -c vga/vga.c -o vga.o
clang --target=i386-pc-none-elf -ffreestanding -nostdlib -c cmdEmu/emu.c -o emu.o
clang --target=i386-pc-none-elf -ffreestanding -nostdlib -c input/input.c -o input.o

ld -m elf_i386 -T linker.ld -o silx.bin boot.o kernel.o vga.o emu.o input.o

ls -lh silx.bin

rm -rf iso syslinux-6.03 syslinux.tar.xz
rm -f *.o
