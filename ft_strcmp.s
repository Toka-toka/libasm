section    .text
global    _ft_strcmp

_ft_strcmp:                             ; dest = rdi, src = rsi
            mov   rax, 0
            mov   rdx, 0
cmp:
            mov   al, BYTE[rdi + rdx]   ; temp1 = dest
            cmp   al, 0                 ; temp1 == '\0' ?
            je    return                ; yes, go return                       
            cmp   al, BYTE[rsi + rdx]   ; temp1 == src ?
            jne   return                ; no, go return
            inc   rdx                   ; i++
            jmp   cmp                   ; go again
return:
            mov     dl, BYTE[rsi + rdx] ; temp2 = src
            sub		rax, rdx            ; temp1 -= temp2
            ret                         ; return(temp1)
