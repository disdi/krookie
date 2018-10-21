#!/bin/bash

LINUX_SOURCE=../linux-4.18
INITRAMFS_PATH=initramfs
QEMU_PREFIX=

${QEMU_PREFIX}qemu-system-arm \
	-nographic \
	-M vexpress-a9 \
	-kernel ${LINUX_SOURCE}/arch/arm/boot/zImage \
	-append "root=/dev/ram rdinit=/busybox-armv7r init console=ttyAMA0,115200n8 earlyprintk" \
	-dtb ${LINUX_SOURCE}/arch/arm/boot/dts/vexpress-v2p-ca9.dtb \
	-initrd ${INITRAMFS_PATH}/initramfs.cpio
