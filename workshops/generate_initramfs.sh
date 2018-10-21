#!/bin/bash

LINUX_SOURCE=../linux-4.18
INITRAMFS_PATH=${PWD}/initramfs
MODULES_PATH=${PWD}/..
INITRAMFS_LIST_PATH=${PWD}/initramfs

cd ${LINUX_SOURCE}
scripts/gen_initramfs_list.sh -o ${INITRAMFS_PATH}/initramfs.cpio ${INITRAMFS_LIST_PATH}/initramfs.list
