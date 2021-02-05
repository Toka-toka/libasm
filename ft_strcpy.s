section    .text
global    _ft_strcpy

_ft_strcpy:                           ; dest = rdi, src = rsi
            mov    rax, -1            ; i = -1

copy:
            inc   rax                 ; i++
            mov   dl, BYTE[rsi + rax] ; temp = src[i]
            mov   BYTE[rdi + rax], dl ; dest[i] = temp
            cmp   BYTE[rsi + rax], 0  ; src[i] == 0 ?
            jne   copy                ; again
            mov   rax, rdi            ; rax = dest
            ret                       ; return(dest)
