#define ASM_FILE
#include <segment.h>

USER_PROCESS_STACK_ADDR=0x1000

.text
.globl _start
_start:
    movq $USER_PROCESS_STACK_ADDR, %rsp
    movl $SERVER_DATA_SEGMENT, %eax
    movl %eax, %ds
    movl %eax, %ss
    movl %eax, %es

    call main

1:
    jmp 1b

