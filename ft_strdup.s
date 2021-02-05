section    .text
global    _ft_strdup

extern    _malloc                  ; include 
extern    _ft_strlen
extern    _ft_strcpy

_ft_strdup:
            mov  rax, 0
            call _ft_strlen
            inc rax
            push rdi
            mov rdi, rax
            call _malloc
            pop rsi
            cmp rax, 0
            je error
            mov rdi, rax
            call _ft_strcpy
            ret                     ; return(i)

error:
            mov    rax, 0           ; i = 0
            ret                     ; return(i)