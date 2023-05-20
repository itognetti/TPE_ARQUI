GLOBAL sys_read
GLOBAL sys_write

section .text

sys_read:
    mov rax, 0x00
    int 80h
    ret

sys_write:
    mov rax, 0x01
    int 80h
    ret
