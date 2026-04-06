global ft_strcpy

ft_strcpy:
    mov rax, rdi;
    push rdi
    push rsi

main_loop:
    mov cl, [rsi];
    mov [rdi], cl;

    cmp cl, 0;
    je return;

    inc rdi;
    inc rsi;
    jmp main_loop;

return:
    pop rsi
    pop rdi
    ret;

section .note.GNU-stack noalloc noexec nowrite progbits