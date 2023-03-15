INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.code
main PROC
    mov eax, 0h
    mov ax, 7FF0h
    add al, 10h
    add ah, 1
    add ax, 2
    call DumpRegs
    exit
main ENDP
END main
