#include "linux/unistd.h"

.data 
hello_string:
      .ascii "Hello World\n"

.text 
.globl _start 
_start:
      mov r7, #__NR_write
      mov r0, #1
      ldr r1,=hello_string
      mov r2, #12
      svc #0

      mov r7, #__NR_exit
      mov r0, #0
      svc #0
