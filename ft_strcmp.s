global ft_strcmp

ft_strcmp:
    xor eax, eax
    xor ecx, ecx

main_loop:
    mov al, [rdi]
    mov cl, [rsi]

    cmp al, cl
    jne  return

    cmp al, 0
    je return

    inc rdi
    inc rsi
    jmp main_loop

return:
    movzx rax, al
    movzx rcx, cl
    sub rax, rcx
    ret

section .note.GNU-stack noalloc noexec nowrite progbits