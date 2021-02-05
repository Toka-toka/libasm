section    .text
global    _ft_strcmp

_ft_strcmp:                           ; dest = rdi, src = rsi
            mov    rcx, -1            ; i = -1
cmp:
            inc   rcx                 ; i++                
            mov   al, BYTE[rdi + rcx] ; temp1 = dest[i]
            mov   bl, BYTE[rsi + rcx]
            sub	  rax, rbx
            jnz   return
            cmp   BYTE[rdi + rcx], 0  ; temp1 == '\0' ?
            jne   cmp                 ; yes, go return                             
return:     
            ret                       ; return(temp1)