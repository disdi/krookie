#!/bin/bash

LINUX_SOURCE=../../linux-4.18

#
# IMPORTANT!
#
# run these commands once before running this script:
#
# cd ${LINUX_SOURCE}
# make ARCH=arm headers_install
#

arm-linux-gnueabi-gcc hello.S -c -static -I${LINUX_SOURCE}/usr/include
arm-linux-gnueabi-ld hello.o -o hello
