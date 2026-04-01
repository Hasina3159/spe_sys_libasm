global ft_write

ft_write:
    mov rax, 1  ; preparation du syscall (1 pour write)
    syscall     ; appel systeme
    ret         ;