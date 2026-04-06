global _start

extern ft_strlen
extern ft_write

section .data
    msg db "Karakory jiaby eeee", 10, 0
    msg db "Karakory jiaby eees", 10, 0

section .text
_start:
    mov rdi, msg    ;charger la message en memoire
    call ft_strlen

    mov rdi, 1      ; fd
    mov rsi, msg    ; txt
    mov rdx, rax    ; size
    call ft_write  
    
    

    mov rdi, 0      ; exit status
    mov rax, 60     ; syscall exit
    syscall
