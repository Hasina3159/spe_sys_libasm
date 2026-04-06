global ft_read
extern __errno_location

ft_read:
    mov rax, 0
    syscall

    cmp rax, 0
    jl error_management
    ret

error_management:
    neg rax
    push rax

    call __errno_location WRT ..plt
    pop rcx
    mov [rax], rcx

    mov rax, -1
    ret

section .note.GNU-stack noalloc noexec nowrite progbits