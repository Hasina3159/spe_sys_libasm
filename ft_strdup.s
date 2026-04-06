extern ft_strlen
extern ft_strcpy
extern malloc
global ft_strdup

ft_strdup:
    xor rax, rax

    ; on recupere la taille du string avec strlen
    call ft_strlen

    push rdi        ; on stocke l'adresse du src
    lea rdi, [rax + 1]; on parametre la taille du malloc 
    call malloc WRT ..plt

    cmp rax, 0
    je error

    pop rsi         ; on stocke l'adresse du srd dans la registre correspondant pour strcpy
    mov rdi, rax    ; on met l'adresse du dst venant de malloc

    sub rsp, 8
    call ft_strcpy
    add rsp, 8
    ret

error:
    xor rax, rax
    pop rdi
    ret

section .note.GNU-stack noalloc noexec nowrite progbits
