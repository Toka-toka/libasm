section    .text
global    _ft_write
extern    ___error                  ; include errno

_ft_write:
            mov   rax, 0x2000004    ; code of write
            syscall                 ; call write
            jc  error               ; if error go to error
            ret                     ; return(i)

error:
            push rax                ; save error code
            call   ___error         ; rax = point to errno
            pop   rdx               ; rdx = error code
            mov   [rax], rdx        ; errno = error code
            mov    rax, -1          ; i = -1
            ret                     ; return(i)
