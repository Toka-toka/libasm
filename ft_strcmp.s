section    .text
global    _ft_strcmp

_ft_strcmp:                           ; dest = rdi, src = rsi
            mov   rax, 0
            mov   rbx, 0
cmp:
            mov   al, BYTE[rdi]       ; temp1 = dest
            cmp   al, 0               ; temp1 == '\0' ?
            je    return              ; yes, go return                       
            cmp   al, BYTE[rsi]       ; temp1 == src ?
            jne   return              ; no, go return
            inc   rdi                 ; dest++
            inc   rsi                 ; src++
            jmp   cmp                 ; go again
return:
            mov     bl, BYTE[rsi]     ; temp2 = src
            sub		rax, rbx          ; temp1 -= temp2
            ret                       ; return(temp1)