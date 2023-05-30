GLOBAL _syscall
GLOBAL invalidOperationCode

section .text

_syscall:
    int 80h
    ret

invalidOperationCode:
    UD2
    ret
