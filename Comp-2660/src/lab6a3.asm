TITLE Lab 6 Activity 2 F
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: Sum of all elements in array

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
sum dword ?
sample dword 5
index dword 0
ArraySize dword 8
array dword 3, 7, 1, 8, 2, 9, 4, 6

.code
main proc
    xor eax, eax
    mov eax, sum
    mov edx, sample
    mov esi, index
    mov ecx, ArraySize

    L1:
        cmp esi, ecx
        jae L5
    L2:
        cmp array[type(array) * esi], edx
        ja L3
        jmp L4
    L3:
        add eax, array[type(array) * esi]
        inc esi
        jmp L1
    L4:
        inc esi
        jmp L1
    L5:
        mov sum, eax
        call DumpRegs
    exit
main endp
end main