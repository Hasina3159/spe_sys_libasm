global ft_strlen

ft_strlen:
    mov rax, 0;

main_loop:
    mov cl, [rdi];
    cmp cl, 0;
    je return;

    inc rdi;
    inc rax;
    jmp main_loop;

return:
    ret;
