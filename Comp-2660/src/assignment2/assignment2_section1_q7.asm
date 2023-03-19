INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    myBytes BYTE 10h, 20h, 30h, 40h
    myWords WORD 3 DUP(?), 2000h
    myString BYTE "ABCDE"

.code
main PROC
    ;mov dx, WORD PTR myBytes
    ;mov al, BYTE PTR myWords + 1
    ;mov eax, DWORD PTR myBytes
    mov eax, TYPE myBytes
    call DumpRegs
    exit
main ENDP
END main
