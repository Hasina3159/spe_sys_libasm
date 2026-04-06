bits 64
extern ft_strlen
global ft_atoi_base
global ft_is_whitespace
global ft_is_sign
global ft_has_whitespaces

section .data
    whitespaces db 9, 10, 11, 12, 13, 32, 0
    signs       db "+-", 0

section .text

ft_is_whitespace:
    lea rcx, [rel whitespaces]
.loop:
    cmp byte [rcx], 0
    je .not_found
    cmp dil, byte [rcx]
    je .found
    inc rcx
    jmp .loop
.found:
    mov rax, 1
    ret
.not_found:
    xor rax, rax
    ret

ft_is_sign:
    lea rcx, [rel signs]
.loop:
    cmp byte [rcx], 0
    je .not_found
    cmp dil, byte [rcx]
    je .found
    inc rcx
    jmp .loop
.found:
    mov rax, 1
    ret
.not_found:
    xor rax, rax
    ret

; --- Parcourt RDI pour trouver un espace (Utile pour la base) ---
ft_has_whitespaces:
    push rbx                ; Sauvegarde RBX (callee-saved)
    mov rbx, rdi
.loop:
    movzx rdi, byte [rbx]   ; Prend le char actuel
    cmp dil, 0              ; Fin de string ?
    je .not_found
    
    call ft_is_whitespace
    cmp rax, 1
    je .found
    
    inc rbx
    jmp .loop
.found:
    mov rax, 1
    pop rbx
    ret
.not_found:
    xor rax, rax
    pop rbx
    ret

ft_skip_whitespaces:
    sub rsp, 8
.loop
    mov rcx, rdi
    movzx dil, byte [rdi]
    call ft_is_whitespace
    cmp rax, 1
    inc rdi
    mov rdi, rcx
    je .loop
    mov rax, rdi
    add rsp, 8
    ret

ft_atoi_base:
    push rdi
    call 
    cmp byte [rdi], 

    call ft_has_whitespaces
    add rsp, 8
    ret


section .note.GNU-stack noalloc noexec nowrite progbits