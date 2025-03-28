section .multiboot2_header
header_start:
    dd 0xe85250d6                ; magic number
    dd 0                         ; protected mode code
    dd header_end - header_start ; header length

    ; checksum
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ; required end tag
    dw 0    ; type
    dw 0    ; flags
    dd 8    ; size
header_end:

; Entry point to the kernel
section .text
global _start
extern kernel_main ; Declare kernel_main as an external symbol
_start:
    ; Set up the stack by pointing ESP to the top of the stack
    mov esp, stack_top

    ; Call the kernel's main function
    call kernel_main

    ; Halt the system if kernel_main returns
    cli
.halt:
    hlt
    jmp .halt
section .bss
align 16
stack_bottom: resb 16384 ; 16 KiB stack
stack_top:
