section    .text
global    _ft_read
extern    ___error                  ; include errno

_ft_read:
            mov   rax, 0x2000003    ; code of read
            syscall                 ; call read
            jc  error               ; if error go to error
            ret                     ; return(i)

error:
            push rax                ; save error code
            call   ___error         ; rax = point to errno
            pop   rdx               ; rdx = error code
            mov   [rax], rdx        ; errno = error code
            mov    rax, -1          ; i = -1
            ret                     ; return(i)
