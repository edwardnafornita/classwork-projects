TITLE Lab7 Activity1

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
val1 QWORD 6789101h
val2 QWORD 12345h
result QWORD 0

.code
main proc
    mov ecx, 8 ; loop counter
    mov esi, offset val1 + sizeof qword ; set index to start
    mov edi, offset val2 + sizeof qword
    clc ; clear Carry flag
    top:
        mov al,BYTE PTR [esi] ; get first number
        sbb al,BYTE PTR [edi] ; subtract second
        mov BYTE PTR [esi], al ; store the result
        dec esi
        dec edi
    loop top

    call DumpRegs
    exit
main endp
end main
