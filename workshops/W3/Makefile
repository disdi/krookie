ifneq (${KERNELRELEASE},)

obj-m := hello.o

else

# modify appropriately
LINUX_SOURCE := ../../linux-4.18

PWD := $(shell pwd)

default:
	${MAKE} -C ${LINUX_SOURCE} M=${PWD} modules

clean:
	${MAKE} -C ${LINUX_SOURCE} M=${PWD} clean

endif
