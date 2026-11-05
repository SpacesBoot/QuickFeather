#!/bin/bash
rm -rf iso syslinux-6.03
mkdir -p iso/isolinux
cp silx.bin iso/kernel.bin
curl -L -o syslinux.tar.xz https://mirrors.kernel.org/pub/linux/utils/boot/syslinux/syslinux-6.03.tar.xz
tar xf syslinux.tar.xz
cp syslinux-6.03/bios/core/isolinux.bin iso/isolinux/
cp syslinux-6.03/bios/com32/elflink/ldlinux.c32 iso/isolinux/
cp syslinux-6.03/bios/com32/modules/mboot.c32 iso/isolinux/
printf 'DEFAULT silx\nLABEL silx\n KERNEL mboot.c32\n APPEND /kernel.bin\n' > iso/isolinux/isolinux.cfg
xorriso -as mkisofs -o silx.iso -b isolinux/isolinux.bin -c isolinux/boot.cat -no-emul-boot -boot-load-size 4 -boot-info-table iso > /dev/null 2>&1#!/bin/bash
rm -rf iso
mkdir -p iso/boot/grub
cp silx_kernel.bin iso/boot/kernel.bin
printf 'menuentry "Silx" {\n multiboot /boot/kernel.bin\n boot\n}\n' > iso/boot/grub/grub.cfg
grub-mkrescue -o silx.iso iso > /dev/null 2>&1
