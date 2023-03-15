TITLE Test

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data

.code
main PROC
    xor eax, eax
    mov al, 00000110b
    cmp al, 00000101b
    call DumpRegs
    exit
main ENDP
END main
