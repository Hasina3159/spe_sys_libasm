global ft_write
extern __errno_location

section .text
ft_write:
    mov rax, 1      ; preparation du syscall write
    syscall         ; appel systeme
    
    cmp rax, 0      ; erreur si write retourne un nombre
    jl error_management
    
    ret         ;

error_management:
    neg rax
    push rax

    call __errno_location WRT ..plt
    xor rcx, rcx
    pop rcx
    mov [rax], rcx
    mov rax, -1
    ret

section .note.GNU-stack noalloc noexec nowrite progbits