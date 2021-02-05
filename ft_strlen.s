section    .text
global    _ft_strlen

_ft_strlen:
            mov     rax, -1             ; i = -1
inc:
            inc     rax                 ; i++
            cmp     BYTE [rdi + rax], 0 ; str[i] == 0 ?
            jne     inc                 ; again
            ret                         ; return(i)
