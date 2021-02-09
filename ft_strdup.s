section    .text
global    _ft_strdup

extern    _malloc                  ; include stuff
extern    _ft_strlen
extern    _ft_strcpy

_ft_strdup:
            mov  rax, 0            ; i = 0
            call _ft_strlen        ; i = len str
            inc rax                ; len str
            push rdi               ; save str
            mov rdi, rax           ; move len str to 1-st arg
            call _malloc           ; call malloc (len str)
            pop rsi                ; load str to 2 arg
            cmp rax, 0             ; new_str = 0 ?
            je return              ; yes, go to return
            mov rdi, rax           ; move new_str to 1-st arg
            call _ft_strcpy        ; call malloc (new_str, str)

return:
            ret                     ; return(new_str)

