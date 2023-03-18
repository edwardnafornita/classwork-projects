TITLE Lab 6 Activity 1
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: 

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
array sword -3, -6, -1, -10, 10, 30, 40, 4
sentinel sword 0

.code
main proc
    mov esi, offset array
    mov ecx, lengthof array

    L1:
        test word ptr [esi], 8000h
        pushfd
        add esi, type array
        popfd
    loopnz L1
    call DumpRegs
    exit
main endp
end main
