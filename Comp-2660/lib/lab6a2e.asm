TITLE Lab 6 Activity 2 E
; Name: Edward Nafornita
; Student ID: 110076381
; Date: March 18, 2023
; Description: While loop logic

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
X dword ?
op1 dword 2
op2 dword 4
op3 dword 5

.code
main proc
    whileLoop:
        inc op1
        mov eax, op1
        cmp eax, op3
        je equal
        jmp notEqual
    equal:
        mov X, 2
        cmp eax, op2
        jb whileLoop
    notEqual:
        mov X, 3
        cmp eax, op2
        jb whileLoop

    xor eax, eax
    xor ebx, ebx
    mov eax, X
    mov ebx, op1
    call DumpRegs
main endp
end main